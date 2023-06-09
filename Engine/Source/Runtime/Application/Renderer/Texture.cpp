#include "Runtime/Core/Base/Header.h"
#include "Runtime/Resource/AssetManager.h"

#include "Runtime/Application/Renderer/Texture.h"
#include "Runtime/Application/Renderer/Renderer.h"
#include "Runtime/Application/Renderer/RendererAPI.hpp"

#include "Runtime/Platform/OpenGL/OpenGLTexture.h"

namespace JEngine
{
    Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    JENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLTexture2D>(width, height);
        case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
        case RendererAPI::RendererAPIType::DX11:    return nullptr;
        case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }

        JENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<Texture2D> Texture2D::Create(const std::filesystem::path& path)
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    JENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLTexture2D>(path);
        case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
        case RendererAPI::RendererAPIType::DX11:    return nullptr;
        case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }

        JENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        return Create(AssetManager::GetFullPath(path));
    }

    Ref<Texture3D> Texture3D::Create(uint32_t width, uint32_t height)
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    JENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLTexture3D>(width, height);
        case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
        case RendererAPI::RendererAPIType::DX11:    return nullptr;
        case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }

        JENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<CubeMapTexture> CubeMapTexture::Create(std::vector<std::string>& paths)
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    JENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLCubeMapTexture>(paths);
        case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
        case RendererAPI::RendererAPIType::DX11:    return nullptr;
        case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }

        JENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<CubeMapTexture> CubeMapTexture::Create()
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    JENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLCubeMapTexture>();
        case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
        case RendererAPI::RendererAPIType::DX11:    return nullptr;
        case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }

        JENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<CubeMapTexture> CubeMapTexture::Create(uint32_t width, uint32_t height)
    {
        switch (RendererAPI::Current())
        {
        case RendererAPI::RendererAPIType::None:    JENGINE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
        case RendererAPI::RendererAPIType::OpenGL:  return CreateRef<OpenGLCubeMapTexture>(width, height);
        case RendererAPI::RendererAPIType::Vulkan:  return nullptr;
        case RendererAPI::RendererAPIType::DX11:    return nullptr;
        case RendererAPI::RendererAPIType::DX12:    return nullptr;
        }

        JENGINE_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
