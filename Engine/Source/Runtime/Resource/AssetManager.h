#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "Runtime/Core/Base/PublicSingleton.h"

#include <filesystem>

namespace JEngine
{
    class AssetManager : public PublicSingleton<AssetManager>
    {
    public:
        [[nodiscard]] static std::filesystem::path GetFullPath(const std::string& RelativePath);
    };
}

#endif //!ASSETMANAGER_H