#pragma once
#include <string>
#include <string_view>
#include <winrt/base.h>

namespace UWP {
	enum class FolderType {
		Temporary,
		Roaming
	};

	winrt::hstring GetApplicationFolderPath(FolderType type);
	std::wstring GetApplicationVersion();
	bool HasPackageIdentity();
	void CopyToClipboard(std::wstring_view str);
};