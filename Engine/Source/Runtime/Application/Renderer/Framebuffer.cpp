#include "Runtime/Core/Base/Header.h"

#include "Runtime/Application/Renderer/Framebuffer.h"
// #include "Runtime/Application/Renderer/Renderer.h"
#include "Runtime/Application/Renderer/RendererAPI.hpp"

#include "Runtime/Platform/OpenGL/OpenGLFramebuffer.h"

namespace JEngine
{
    Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    JENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLFramebuffer>(spec);
        case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
        case RendererAPI::RendererAPIType::DX11:    return nullptr;
        case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }
        JENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}