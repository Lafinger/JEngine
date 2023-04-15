#include "Runtime/Core/Base/Header.h"

#include "Runtime/Application/Renderer/VertexBuffer.h"
#include "Runtime/Application/Renderer/Renderer.h"
#include "Runtime/Application/Renderer/RendererAPI.hpp"

#include "Runtime/Platform/OpenGL/OpenGLVertexBuffer.h"

namespace JEngine
{
    Ref<VertexBuffer> VertexBuffer::Create(uint32_t size, VertexBufferUsage usage)
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    JENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLVertexBuffer>(size, usage);
        case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
        case RendererAPI::RendererAPIType::DX11:    return nullptr;
        case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }
        JENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<VertexBuffer> VertexBuffer::Create(void* vertices, uint32_t size, VertexBufferUsage usage)
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    JENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLVertexBuffer>(vertices, size, usage);
        case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
        case RendererAPI::RendererAPIType::DX11:    return nullptr;
        case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }
        JENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}