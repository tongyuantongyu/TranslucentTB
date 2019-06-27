#pragma once
#include <ostream>
#include <string_view>
#include <type_traits>

namespace impl {
	template<typename T, typename = void>
	struct is_streamable : std::false_type { };

	template<typename T>
	struct is_streamable<T, std::void_t<decltype(std::declval<std::wostream &>() << std::declval<T>())>> : std::true_type { };

	template<typename T>
	inline constexpr bool is_streamable_v = is_streamable<T>::value;
}

// Disable overload for already valid operands.
template<class T, class = std::enable_if_t<!impl::is_streamable_v<const T &> && std::is_convertible_v<const T &, std::wstring_view>>>
std::wostream &operator <<(std::wostream &stream, const T &thing)
{
	return stream << static_cast<std::wstring_view>(thing);
}