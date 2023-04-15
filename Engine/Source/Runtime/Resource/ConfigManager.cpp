#include "Runtime/Core/Base/Header.h"

#include "Runtime/Resource/ConfigManager.h"

namespace JEngine
{
    glm::vec2 ConfigManager::mViewportSize = { 1280.0f, 720.0f };
    int ConfigManager::selectedEntity = -1;

    ConfigManager::ConfigManager()
    {
        mRootFolder = { JENGINE_XSTRINGIFY_MACRO(ENGINE_ROOT_DIR) };
        mAssetsFolder = mRootFolder / "Assets";
        mShadersFolder = mRootFolder / "Shaders";
        mResourcesFolder = mRootFolder / "Resources";
    }

    void ConfigManager::Clear()
    {
        mRootFolder.clear();
        mAssetsFolder.clear();
        mShadersFolder.clear();
        mResourcesFolder.clear();
    }

    const std::filesystem::path& ConfigManager::GetRootFolder() const
    {
        JENGINE_CORE_ASSERT(std::filesystem::exists(mRootFolder));
        return mRootFolder;
    }

    const std::filesystem::path& ConfigManager::GetAssetsFolder() const
    { 
        JENGINE_CORE_ASSERT(std::filesystem::exists(mAssetsFolder));
        return mAssetsFolder;
    }

    const std::filesystem::path& ConfigManager::GetShadersFolder() const
    { 
        JENGINE_CORE_ASSERT(std::filesystem::exists(mShadersFolder));
        return mShadersFolder;
    }

    const std::filesystem::path& ConfigManager::GetResourcesFolder() const
    { 
        JENGINE_CORE_ASSERT(std::filesystem::exists(mResourcesFolder));
        return mResourcesFolder;
    }
}