#ifndef RENDERER_H
#define RENDERER_H

#include "Runtime/Application/Renderer/GraphicsContext.h"
#include "Runtime/Application/Renderer/Shader.h"
#include "Runtime/Application/Renderer/VertexArray.h"

namespace JEngine
{
    class Renderer
    {
    public:
        static void Init();
		static void Shutdown();

        static void OnWindowResize(uint32_t width, uint32_t height);

        static void EndScene();

        static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

        [[nodiscard]] static Ref<GraphicsContext> GetContext();
    private:
        struct SceneData
        {
            glm::mat4 ViewProjectionMatrix;
        };

        static SceneData* mSceneData;
    };
}

#endif //!RENDERER_H