#include "Runtime/Core/Base/Header.h"

#include "Runtime/Application/Renderer/IndexBuffer.h"
#include "Runtime/Application/Renderer/Renderer.h"
#include "Runtime/Application/Renderer/RendererAPI.hpp"

#include "Runtime/Platform/OpenGL/OpenGLIndexBuffer.h"

namespace JEngine
{
    Ref<IndexBuffer> IndexBuffer::Create(uint32_t count)
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLIndexBuffer>(count);
        case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
        case RendererAPI::RendererAPIType::DX11:    return nullptr;
        case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }
        JENGINE_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }

    Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count)
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLIndexBuffer>(indices, count);
        case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
        case RendererAPI::RendererAPIType::DX11:    return nullptr;
        case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }
        JENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}