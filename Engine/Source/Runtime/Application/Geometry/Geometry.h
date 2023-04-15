#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Runtime/Application/Renderer/VertexArray.h"
#include "Runtime/Application/Renderer/VertexBuffer.h"
// #include "Runtime/Application/Renderer/IndexBuffer.h"
#include "Runtime/Application/Renderer/Shader.h"
#include "Runtime/Platform/OpenGL/OpenGLShader.h"

namespace JEngine 
{
    enum class GeometryType
    {
        None = 0,
        Light,
        Camera
    };

	struct GeometryVertex
	{
		glm::vec3 Pos;
	};

	class Geometry
	{
	public:
		Geometry() = default;
		Geometry(const Geometry&) = default;
        Geometry(const GeometryType type);

		void Draw(const glm::mat4& transform, const glm::mat4& projection, Ref<Shader>& shader, int entityID);
        
	private:
		void SetupGeometry();

        void SetupLightGeometry();
        // void drawCamera(component::Light *light, const glm::quat &rotation, const glm::vec4 &color);
        void SetupCone(int32_t numCircleVerts, int32_t numLinesToCircle, float angle, float length, const glm::vec3 &position, bool backward = false);
        void SetupCircle(int32_t numVerts, float radius, const glm::vec3 &position);
        void SetupLine(const glm::vec3 &start, const glm::vec3 &end);
		
	private:
		int mEntityID = -1;
        GeometryType mType = GeometryType::None;
        glm::vec4 mColor = glm::vec4(1.0);
        std::vector<GeometryVertex> mGeometryVertexs;

		std::vector<uint32_t> mIndices;
		Ref<VertexArray> mVertexArray;
		Ref<VertexBuffer> mVB;
		// Ref<IndexBuffer> mIB;
	};
}


#endif //!GEOMETRY_H