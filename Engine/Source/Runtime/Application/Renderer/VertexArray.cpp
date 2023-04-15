#include "Runtime/Core/Base/Header.h"

#include "Runtime/Application/Renderer/VertexArray.h"

#include "Runtime/Application/Renderer/RendererAPI.hpp"
#include "Runtime/Platform/OpenGL/OpenGLVertexArray.h"

namespace JEngine
{
    Ref<VertexArray> VertexArray::Create()
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    JENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return std::make_shared<OpenGLVertexArray>();
        case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
        case RendererAPI::RendererAPIType::DX11:    return nullptr;
        case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }
        JENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}