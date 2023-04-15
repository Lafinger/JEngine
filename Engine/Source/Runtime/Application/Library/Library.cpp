#include "Runtime/Core/Base/Header.h"
#include "Runtime/Resource/AssetManager.h"

#include "Runtime/Application/Library/Library.h"
#include "Runtime/Application/Mesh/Mesh.h"
#include "Runtime/Application/Renderer/Texture.h"
#include "Runtime/Application/Library/UniformBufferLibrary.h"

namespace JEngine
{
    template<typename LibType>
    Library<LibType>::Library()
    {
    }

    template<>
    Library<Mesh>::Library()
    {
        Add("Box", CreateRef<Mesh>("Assets/Models/Test/Box.obj"));
    }

    template<>
    Library<CubeMapTexture>::Library()
    {
        std::vector<std::string> Paths{
            "Assets/Textures/Skybox/right.jpg",
            "Assets/Textures/Skybox/left.jpg",
            "Assets/Textures/Skybox/top.jpg",
            "Assets/Textures/Skybox/bottom.jpg",
            "Assets/Textures/Skybox/front.jpg",
            "Assets/Textures/Skybox/back.jpg",
        };
        Add("SkyBoxTexture", CubeMapTexture::Create(Paths));

        std::vector<std::string> blackPaths{
            "Assets/Textures/black.png",
            "Assets/Textures/black.png",
            "Assets/Textures/black.png",
            "Assets/Textures/black.png",
            "Assets/Textures/black.png",
            "Assets/Textures/black.png",
        };
        Add("BlackCubeMap", CubeMapTexture::Create(blackPaths));

        Add("EnvironmentHdr", CubeMapTexture::Create(512, 512));
        Add("EnvironmentIrradiance", CubeMapTexture::Create(32, 32));
        Add("EnvironmentPrefilter", CubeMapTexture::Create(128, 128));
    }
}