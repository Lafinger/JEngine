// #include <commdlg.h>
// #include <GLFW/glfw3.h>
// #include <GLFW/glfw3native.h>
// #define GLFW_EXPOSE_NATIVE_WIN32

#include "Runtime/Core/Base/Header.h"
#include "Runtime/Application/Utils/WindowsPlatformUtils.h"
#include "Runtime/Application/Framework/Application.h"

namespace JEngine 
{
	std::string FileDialogs::OpenFile(const char* filter)
	{
		// OPENFILENAME ofn;
		// CHAR szFile[260] = { 0 };
		// ZeroMemory(&ofn, sizeof(OPENFILENAME));
		// ofn.lStructSize = sizeof(OPENFILENAME);
		// ofn.hwndOwner = glfwGetWin32Window((GLFWwindow*)Application::GetInstance().GetWindow().GetNativeWindow());
		// ofn.lpstrFile = szFile;
		// ofn.nMaxFile = sizeof(szFile);
		// ofn.lpstrFilter = filter;
		// ofn.nFilterIndex = 1;
		// ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
		// if (GetOpenFileNameA(&ofn) == TRUE)
		// {
		// 	return ofn.lpstrFile;
		// }
		return std::string();
	}

	std::string FileDialogs::SaveFile(const char* filter)
	{
		// OPENFILENAME ofn;
		// CHAR szFile[260] = { 0 };
		// ZeroMemory(&ofn, sizeof(OPENFILENAME));
		// ofn.lStructSize = sizeof(OPENFILENAME);
		// ofn.hwndOwner = glfwGetWin32Window((GLFWwindow*)Application::GetInstance().GetWindow().GetNativeWindow());
		// ofn.lpstrFile = szFile;
		// ofn.nMaxFile = sizeof(szFile);
		// ofn.lpstrFilter = filter;
		// ofn.nFilterIndex = 1;
		// ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
		// if (GetSaveFileNameA(&ofn) == TRUE)
		// {
		// 	return ofn.lpstrFile;
		// }
		return std::string();
	}
}