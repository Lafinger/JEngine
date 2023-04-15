#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <ImGuizmo.h>

#include <imgui_notify.h>
// #include <imgui/src/implot.h>
#include <tahoma.h>
#include <imgui/src/IconsMaterialDesignIcons.h>
#include <imgui/src/MaterialDesign.inl>
#include <imgui/src/RobotoRegular.inl>

#include "Runtime/Core/Base/Header.h"

#include "Runtime/Application/Framework/Application.h"
#include "Runtime/Platform/OpenGL/OpenGLImGuiLayer.h"
#include "Runtime/Resource/AssetManager.h"

namespace JEngine
{
	OpenGLImGuiLayer::~OpenGLImGuiLayer()
	{
	}

    void OpenGLImGuiLayer::OnAttach()
    {
        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
        //io.ConfigViewportsNoAutoMerge = true;
        //io.ConfigViewportsNoTaskBarIcon = true;

        // ------------------------------------------------------ imgui font size ---------------------------------------------------------------
        // float fontSize = 18.0f;
        // io.Fonts->AddFontFromFileTTF(AssetManager::GetFullPath("Assets/Fonts/opensans/OpenSans-Bold.ttf").string().c_str(), fontSize);
        // io.FontDefault = io.Fonts->AddFontFromFileTTF(AssetManager::GetFullPath("Assets/Fonts/opensans/OpenSans-Regular.ttf").string().c_str(), fontSize);
        
		static const ImWchar icons_ranges[] = {ICON_MIN_MDI, ICON_MAX_MDI, 0};

        ImFontConfig iconsConfig;
		iconsConfig.MergeMode   = false;
		iconsConfig.PixelSnapH  = true;
		iconsConfig.OversampleH = iconsConfig.OversampleV = 1;
		iconsConfig.GlyphMinAdvanceX                      = 4.0f;
		iconsConfig.SizePixels                            = 16.f;

        static const ImWchar ranges[] = {
		    0x0020,
		    0x00FF,
		    0x0400,
		    0x044F,
		    0,
		};

        io.Fonts->AddFontFromMemoryCompressedTTF(
		    RobotoRegular_compressed_data,
		    RobotoRegular_compressed_size, 16.f,
		    &iconsConfig,
		    ranges);

        iconsConfig.MergeMode     = true;
		iconsConfig.PixelSnapH    = true;
		iconsConfig.GlyphOffset.y = 1.0f;
		iconsConfig.OversampleH = iconsConfig.OversampleV = 1;
		iconsConfig.PixelSnapH                            = true;
		iconsConfig.SizePixels                            = 16.f;
		io.Fonts->AddFontFromMemoryCompressedTTF(
		    MaterialDesign_compressed_data,
		    MaterialDesign_compressed_size, 16.f,
		    &iconsConfig, icons_ranges);
        io.Fonts->AddFontDefault();

        ImFontConfig font_cfg;
        font_cfg.FontDataOwnedByAtlas = false;
		io.Fonts->AddFontFromMemoryTTF((void *) tahoma, sizeof(tahoma), 16.f, &font_cfg);

		// Initialize notify
		ImGui::MergeIconsWithLatestFont(16.f, false);
        // ------------------------------------------------------ imgui font size ---------------------------------------------------------------

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsClassic();

        // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        // Setup custom ImGui style
        SetDarkThemeColors();

        Application& app = Application::GetInstance();
        GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 460");
    }

    void OpenGLImGuiLayer::OnDetach()
    {
        // Cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void OpenGLImGuiLayer::OnImGuiRender()
    {
    }

    void OpenGLImGuiLayer::Begin()
    {
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGuizmo::BeginFrame();
    }

    void OpenGLImGuiLayer::End()
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::GetInstance();
        io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }
}