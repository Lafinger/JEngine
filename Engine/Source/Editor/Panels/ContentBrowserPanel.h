#ifndef CONTENTBROWSERPANEL_H
#define CONTENTBROWSERPANEL_H

#include <filesystem>
#include <optional>

namespace JEngine
{
	class ContentBrowserPanel
	{
	public:
		ContentBrowserPanel();

		void OnImGuiRender(bool* pOpen);
	private:
		void DrawTree();
		void DrawTreeRecursive(const std::filesystem::path& currentPath);
		void DrawContent();
	private:
		std::filesystem::path mCurrentDirectory;
		std::optional<std::filesystem::path> mSelectedDirectory;
	};
}

#endif //!CONTENTBROWSERPANEL_H
