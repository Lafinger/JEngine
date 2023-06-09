#include "Runtime/Core/Base/Header.h"

#include "Runtime/Application/Imgui/ImguiLayer.h"
#include "Runtime/Application/Renderer/RendererAPI.hpp"
#include "Runtime/Platform/OpenGL/OpenGLImguiLayer.h"
// #include "Runtime/Platform/Vulkan/VulkanImGuiLayer.h"
// #include "Runtime/Platform/DirectX11/Dx11ImGuiLayer.h"

#include <imgui.h>

namespace JEngine
{
    ImGuiLayer::ImGuiLayer()
        : Layer("ImGuiLayer")
    {
    }

    ImGuiLayer::ImGuiLayer(const std::string& name)
        : Layer(name)
    {
    }

    ImGuiLayer::~ImGuiLayer()
    {
    }

    void ImGuiLayer::OnEvent(Event& e)
    {
        if (mBlockEvents)
        {
            ImGuiIO& io = ImGui::GetIO();
            e.bHandled |= e.IsInCategory(EventCategoryMouse) & io.WantCaptureMouse;
            e.bHandled |= e.IsInCategory(EventCategoryKeyboard) & io.WantCaptureKeyboard;
        }
    }

    ImGuiLayer* ImGuiLayer::Create()
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    JENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return new OpenGLImGuiLayer("OpenGLImGuiLayer");
        // case RendererAPI::RendererAPIType::Vulkan:  return new VulkanImGuiLayer("VulkanImGuiLayer");
        // case RendererAPI::RendererAPIType::DX11:    return new Dx11ImGuiLayer("Dx11ImGuiLayer");
        // case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }

        JENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    void ImGuiLayer::SetDarkThemeColors()
    {
        ImGuiStyle *style  = &ImGui::GetStyle();
        ImVec4* colors = style->Colors;

        // colors[ImGuiCol_WindowBg] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };

        // // Headers
        // colors[ImGuiCol_Header] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
        // colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.4f, 0.405f, 0.41f, 1.0f };
        // colors[ImGuiCol_HeaderActive] = ImVec4{ 0.25f, 0.2505f, 0.251f, 1.0f };

        // // Buttons
        // colors[ImGuiCol_Button] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
        // colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.4f, 0.405f, 0.41f, 1.0f };
        // colors[ImGuiCol_ButtonActive] = ImVec4{ 0.25f, 0.2505f, 0.251f, 1.0f };

        // // Frame BG
        // colors[ImGuiCol_FrameBg] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
        // colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.4f, 0.405f, 0.41f, 1.0f };
        // colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.25f, 0.2505f, 0.251f, 1.0f };

        // // Tabs
        // colors[ImGuiCol_Tab] = ImVec4{ 0.25f, 0.2505f, 0.251f, 1.0f };
        // colors[ImGuiCol_TabHovered] = ImVec4{ 0.48f, 0.4805f, 0.481f, 1.0f };
        // colors[ImGuiCol_TabActive] = ImVec4{ 0.38f, 0.3805f, 0.381f, 1.0f };
        // colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.25f, 0.2505f, 0.251f, 1.0f };
        // colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };

        // // Title
        // colors[ImGuiCol_TitleBg] = ImVec4{ 0.25f, 0.2505f, 0.251f, 1.0f };
        // colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.25f, 0.2505f, 0.251f, 1.0f };
        // colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.25f, 0.2505f, 0.251f, 1.0f };

        // // Resize Grip
        // colors[ImGuiCol_ResizeGrip] = ImVec4(0.91f, 0.91f, 0.91f, 0.25f);
        // colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.81f, 0.81f, 0.81f, 0.67f);
        // colors[ImGuiCol_ResizeGripActive] = ImVec4(0.46f, 0.46f, 0.46f, 0.95f);

        // // Scrollbar
        // colors[ImGuiCol_ScrollbarBg] = ImVec4(0.12f, 0.12f, 0.12f, 0.53f);
        // colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.41f, 0.41f, 0.41f, 1.0f);
        // colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.51f, 0.51f, 0.51f, 1.0f);
        // colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.61f, 0.61f, 0.61f, 1.0f);

        // // Check Mark
        // colors[ImGuiCol_CheckMark] = ImVec4(0.94f, 0.94f, 0.94f, 1.0f);

        // // Slider
        // colors[ImGuiCol_SliderGrab] = ImVec4(0.51f, 0.51f, 0.51f, 0.7f);
        // colors[ImGuiCol_SliderGrabActive] = ImVec4(0.66f, 0.66f, 0.66f, 1.0f);

        colors[ImGuiCol_Text]                  = ImVec4(1.000f, 1.000f, 1.000f, 1.000f);
		colors[ImGuiCol_TextDisabled]          = ImVec4(0.500f, 0.500f, 0.500f, 1.000f);
		colors[ImGuiCol_WindowBg]              = ImVec4(0.180f, 0.180f, 0.180f, 1.000f);
		colors[ImGuiCol_ChildBg]               = ImVec4(0.280f, 0.280f, 0.280f, 0.000f);
		colors[ImGuiCol_PopupBg]               = ImVec4(0.313f, 0.313f, 0.313f, 1.000f);
		colors[ImGuiCol_Border]                = ImVec4(0.266f, 0.266f, 0.266f, 1.000f);
		colors[ImGuiCol_BorderShadow]          = ImVec4(0.000f, 0.000f, 0.000f, 0.000f);
		colors[ImGuiCol_FrameBg]               = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
		colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.200f, 0.200f, 0.200f, 1.000f);
		colors[ImGuiCol_FrameBgActive]         = ImVec4(0.280f, 0.280f, 0.280f, 1.000f);
		colors[ImGuiCol_TitleBg]               = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
		colors[ImGuiCol_TitleBgActive]         = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
		colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.148f, 0.148f, 0.148f, 1.000f);
		colors[ImGuiCol_MenuBarBg]             = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
		colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.160f, 0.160f, 0.160f, 1.000f);
		colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.277f, 0.277f, 0.277f, 1.000f);
		colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.300f, 0.300f, 0.300f, 1.000f);
		colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_CheckMark]             = ImVec4(1.000f, 1.000f, 1.000f, 1.000f);
		colors[ImGuiCol_SliderGrab]            = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
		colors[ImGuiCol_SliderGrabActive]      = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_Button]                = ImVec4(1.000f, 1.000f, 1.000f, 0.000f);
		colors[ImGuiCol_ButtonHovered]         = ImVec4(1.000f, 1.000f, 1.000f, 0.156f);
		colors[ImGuiCol_ButtonActive]          = ImVec4(1.000f, 1.000f, 1.000f, 0.391f);
		colors[ImGuiCol_Header]                = ImVec4(0.313f, 0.313f, 0.313f, 1.000f);
		colors[ImGuiCol_HeaderHovered]         = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
		colors[ImGuiCol_HeaderActive]          = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
		colors[ImGuiCol_Separator]             = colors[ImGuiCol_Border];
		colors[ImGuiCol_SeparatorHovered]      = ImVec4(0.391f, 0.391f, 0.391f, 1.000f);
		colors[ImGuiCol_SeparatorActive]       = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_ResizeGrip]            = ImVec4(1.000f, 1.000f, 1.000f, 0.250f);
		colors[ImGuiCol_ResizeGripHovered]     = ImVec4(1.000f, 1.000f, 1.000f, 0.670f);
		colors[ImGuiCol_ResizeGripActive]      = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_Tab]                   = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
		colors[ImGuiCol_TabHovered]            = ImVec4(0.352f, 0.352f, 0.352f, 1.000f);
		colors[ImGuiCol_TabActive]             = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
		colors[ImGuiCol_TabUnfocused]          = ImVec4(0.098f, 0.098f, 0.098f, 1.000f);
		colors[ImGuiCol_TabUnfocusedActive]    = ImVec4(0.195f, 0.195f, 0.195f, 1.000f);
		colors[ImGuiCol_DockingPreview]        = ImVec4(1.000f, 0.391f, 0.000f, 0.781f);
		colors[ImGuiCol_DockingEmptyBg]        = ImVec4(0.180f, 0.180f, 0.180f, 1.000f);
		colors[ImGuiCol_PlotLines]             = ImVec4(0.469f, 0.469f, 0.469f, 1.000f);
		colors[ImGuiCol_PlotLinesHovered]      = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_PlotHistogram]         = ImVec4(0.586f, 0.586f, 0.586f, 1.000f);
		colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_TextSelectedBg]        = ImVec4(1.000f, 1.000f, 1.000f, 0.156f);
		colors[ImGuiCol_DragDropTarget]        = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_NavHighlight]          = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.000f, 0.391f, 0.000f, 1.000f);
		colors[ImGuiCol_NavWindowingDimBg]     = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);
		colors[ImGuiCol_ModalWindowDimBg]      = ImVec4(0.000f, 0.000f, 0.000f, 0.586f);

		style->ChildRounding     = 4.0f;
		style->FrameBorderSize   = 1.0f;
		style->FrameRounding     = 2.0f;
		style->GrabMinSize       = 7.0f;
		style->PopupRounding     = 2.0f;
		style->ScrollbarRounding = 12.0f;
		style->ScrollbarSize     = 13.0f;
		style->TabBorderSize     = 1.0f;
		style->TabRounding       = 4.0f;
		style->WindowRounding    = 4.0f;

    }
}
