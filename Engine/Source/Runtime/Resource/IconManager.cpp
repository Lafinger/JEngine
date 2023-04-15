#include "Runtime/Resource/AssetManager.h"
#include "Runtime/Resource/IconManager.h"

namespace JEngine
{
    IconManager::IconManager()
    {
        Add("EntityIcon", Texture2D::Create(AssetManager::GetFullPath("Assets/Icons/Entity.png")));
        Add("NullTextrue", Texture2D::Create(AssetManager::GetFullPath("Assets/Textures/DefaultTexture.png")));
        Add("SettingIcon", Texture2D::Create(std::string(("Assets/Icons/Setting.png"))));
        Add("DirectoryIcon", Texture2D::Create(std::string(("Assets/Icons/ContentBrowser/FolderIcon.png"))));
        Add("FileIcon", Texture2D::Create(std::string(("Assets/Icons/ContentBrowser/FileIcon.png"))));
        Add("PlayIcon", Texture2D::Create(std::string(("Assets/Icons/PlayButton.png"))));
        Add("StopIcon", Texture2D::Create(std::string(("Assets/Icons/StopButton.png"))));
        Add("TransIcon", Texture2D::Create(std::string(("Assets/Icons/Trans.png"))));
        Add("RotateIcon", Texture2D::Create(std::string(("Assets/Icons/Rotate.png"))));
        Add("ScaleIcon", Texture2D::Create(std::string(("Assets/Icons/Scale.png"))));
        Add("MusicIcon", Texture2D::Create(std::string(("Assets/Icons/Music.png"))));
    }
}