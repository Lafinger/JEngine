#include "Runtime/Core/Base/Header.h"
#include "Runtime/Resource/AssetManager.h"

#include "Runtime/Application/Library/ShaderLibrary.h"

namespace JEngine
{
    Library<Shader>::Library()
    {
        Add("PBR", Shader::CreateNative(AssetManager::GetFullPath("Shaders/PBR.glsl")));
        Add("PBRandIBL", Shader::CreateNative(AssetManager::GetFullPath("Shaders/PBRandIBL.glsl")));
        Add("Blinn-phong", Shader::CreateNative(AssetManager::GetFullPath("Shaders/Blinn-phong.glsl")));
        Add("Geometry", Shader::CreateNative(AssetManager::GetFullPath("Shaders/Geometry.glsl")));
        Add("SkyBox", Shader::Create(AssetManager::GetFullPath("Shaders/SkyBox.glsl")));

        Add("IBL_background", Shader::CreateNative(AssetManager::GetFullPath("Shaders/IBL/background.glsl")));
        Add("IBL_brdf", Shader::CreateNative(AssetManager::GetFullPath("Shaders/IBL/brdf.glsl")));
        Add("IBL_equirectangularToCubemap", Shader::CreateNative(AssetManager::GetFullPath("Shaders/IBL/equirectangularToCubemap.glsl")));
        Add("IBL_irradiance", Shader::CreateNative(AssetManager::GetFullPath("Shaders/IBL/irradiance.glsl")));
        Add("IBL_prefilter", Shader::CreateNative(AssetManager::GetFullPath("Shaders/IBL/prefilter.glsl")));

        Add("Post_Outline", Shader::CreateNative(AssetManager::GetFullPath("Shaders/PostProcessing/Outline.glsl")));
        Add("Post_Cartoon", Shader::CreateNative(AssetManager::GetFullPath("Shaders/PostProcessing/Cartoon.glsl")));
        Add("Post_GrayScale", Shader::CreateNative(AssetManager::GetFullPath("Shaders/PostProcessing/GrayScale.glsl")));
        Add("Post_GaussianBlur", Shader::CreateNative(AssetManager::GetFullPath("Shaders/PostProcessing/GaussianBlur.glsl")));
        Add("Post_FxaaConsole", Shader::CreateNative(AssetManager::GetFullPath("Shaders/PostProcessing/FxaaConsole.glsl")));
        Add("NormalOutline", Shader::CreateNative(AssetManager::GetFullPath("Shaders/NormalOutline.glsl")));
        Add("NormalOutline_anim", Shader::CreateNative(AssetManager::GetFullPath("Shaders/NormalOutline_anim.glsl")));

        Add("CSM_Depth", Shader::CreateNative(AssetManager::GetFullPath("Shaders/Shadow/CSM_Depth.glsl")));
        Add("Debug_Depth", Shader::CreateNative(AssetManager::GetFullPath("Shaders/Shadow/Debug_Depth.glsl")));
    }

    Ref<Shader> Library<Shader>::GetDefaultShader()
    {
        return mLibrary["PBRandIBL"];
        // return mLibrary["Blinn-phong"];
        // return mLibrary["PBR"];
    }

    Ref<Shader> Library<Shader>::GetSkyBoxShader()
    {
        return mLibrary["SkyBox"];
    }

    Ref<Shader> Library<Shader>::GetGeometryShader()
    {
        return mLibrary["Geometry"];
    }
}