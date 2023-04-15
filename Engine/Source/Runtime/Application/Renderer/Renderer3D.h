#ifndef RENDERER3D_H
#define RENDERER3D_H

#include "Runtime/Application/Camera/EditorCamera.h"
#include "Runtime/Application/Renderer/Texture.h"

#include "Runtime/Application/EcsFramework/Component/Mesh/MeshComponent.h" 
#include "Runtime/Application/Geometry/Geometry.h"

namespace JEngine
{
    class Renderer3D
    {
    public:
        static void Init();
        static void Shutdown();

        static void DrawModel(const glm::mat4& transform, const glm::vec3& cameraPos, MeshComponent& MeshComponent, int EntityID);
        static void DrawGeometry(const glm::mat4& transform, const glm::mat4& projection, Ref<Geometry>& geometry, int EntityID);

        static void BeginScene(const Camera& camera, const glm::mat4& transform);
        static void BeginScene(const EditorCamera& camera);
        static void EndScene();
    public:
        // shadow pass
        static Ref<class Framebuffer> lightFBO;
    };
}

#endif //!RENDERER3D_H