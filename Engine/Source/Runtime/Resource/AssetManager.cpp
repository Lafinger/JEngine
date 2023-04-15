#include "Runtime/Core/Base/Header.h"

#include "Runtime/Resource/AssetManager.h"
#include "Runtime/Resource/ConfigManager.h"

namespace JEngine
{
    std::filesystem::path AssetManager::GetFullPath(const std::string& RelativePath)
    {
        return ConfigManager::GetInstance().GetRootFolder() / RelativePath;
    }
}