#ifndef MATERIAL_H
#define MATERIAL_H

#include <unordered_map>

#include "Runtime/Application/Renderer/Texture.h"
#include "Runtime/Application/Renderer/Shader.h"
#include "Runtime/Application/Library/ShaderLibrary.h"
#include "Runtime/Application/Library/TextureLibrary.h"

namespace JEngine
{
    // from https://stackoverflow.com/questions/18837857/cant-use-enum-class-as-unordered-map-key
    struct EnumClassHash
    {
        template <typename T>
        std::size_t operator()(T t) const
        {
            return static_cast<std::size_t>(t);
        }
    };

    enum class TextureType
    {
        Albedo = 0,
        Normal,
        Metalness,
        Roughness,
        AmbientOcclusion,
        Specular,
        Height,
        Emission,
    };

    struct MaterialTexture
    {
        Ref<Texture2D> texture2d = nullptr;
        TextureType type;
        std::string path;
    };

    class Material
    {
    public:
        Material() { Initialize(); };
        Material(Ref<Shader> shader) : mShader(shader) { Initialize(); };
    public:
        void SetShader(Ref<Shader> shader) { mShader = shader; }
        [[nodiscard]] Ref<Shader> GetShader() { return mShader; }

        void AddTexture(TextureType type, Ref<Texture2D> texture) 
        {
            JENGINE_CORE_ASSERT(mTexMap.find(type) == mTexMap.end());
            mTexMap[type] = texture;
        }

        [[nodiscard]] Ref<Texture2D> GetTexture(TextureType type) { return mTexMap[type]; }
    private:
        void Initialize();
    public:
        std::vector<MaterialTexture> mTextures;

        bool bUseAlbedoMap = true;
        glm::vec4 col = { 1.0f, 1.0f, 1.0f, 1.0f }; // 0 ~ 1
        Ref<Texture2D> albedoRGBA = Texture2D::Create(1, 1);
        Ref<Texture2D> mAlbedoMap = Library<Texture2D>::GetInstance().GetDefaultTexture();

        bool bUseNormalMap = true;
        Ref<Texture2D> mNormalMap = Library<Texture2D>::GetInstance().Get("DefaultNormal");

        bool bUseMetallicMap = true;
        float metallic = 0.1f;
        Ref<Texture2D> metallicRGBA = Texture2D::Create(1, 1);
        Ref<Texture2D> mMetallicMap = Library<Texture2D>::GetInstance().Get("DefaultMetallicRoughness");

        bool bUseRoughnessMap = true;
        float roughness = 0.9f;
        Ref<Texture2D> roughnessRGBA = Texture2D::Create(1, 1);
        Ref<Texture2D> mRoughnessMap = Library<Texture2D>::GetInstance().Get("DefaultMetallicRoughness");

        bool bUseAoMap = true;
        Ref<Texture2D> mAoMap = Library<Texture2D>::GetInstance().GetWhiteTexture();
    private:
        Ref<Shader> mShader;
        std::unordered_map<TextureType, Ref<Texture2D>, EnumClassHash> mTexMap;
    };

}

#endif //!MATERIAL_H