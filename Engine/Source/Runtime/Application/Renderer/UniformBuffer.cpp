#include "Runtime/Core/Base/Header.h"

#include "Runtime/Application/Renderer/UniformBuffer.h"
#include "Runtime/Application/Renderer/RendererAPI.hpp"
#include "Runtime/Platform/OpenGL/OpenGLUniformBuffer.h"

namespace JEngine 
{
	Ref<UniformBuffer> UniformBuffer::Create(uint32_t size, uint32_t binding)
	{
		switch (RendererAPI::Current())
		{
		case RendererAPI::RendererAPIType::None:    JENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLUniformBuffer>(size, binding);
		case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
		case RendererAPI::RendererAPIType::DX11:    return nullptr;
		case RendererAPI::RendererAPIType::DX12:    return nullptr;
		}

		JENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}