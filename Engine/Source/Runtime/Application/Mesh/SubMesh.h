#ifndef SUBMESH_H
#define SUBMESH_H

#include "Runtime/Application/Renderer/VertexArray.h"
#include "Runtime/Application/Renderer/VertexBuffer.h"
#include "Runtime/Application/Renderer/IndexBuffer.h"
#include "Runtime/Application/Renderer/Shader.h"
#include "Runtime/Application/Renderer/Material.h"

#define MAX_BONE_INFLUENCE 4

namespace JEngine 
{
	class Mesh; 

	struct StaticVertex
	{
		glm::vec3 Pos;
		glm::vec3 Normal;
		glm::vec2 TexCoord;
		glm::vec3 Tangent;
		glm::vec3 Bitangent;

		int EntityID;
	};

	struct SkinnedVertex 
	{
		glm::vec3 Pos;
		glm::vec3 Normal;
		glm::vec2 TexCoord;
		glm::vec3 Tangent;
		glm::vec3 Bitangent;

		int EntityID;

		int mBoneIDs[MAX_BONE_INFLUENCE];
		float mWeights[MAX_BONE_INFLUENCE];
	};

	class SubMesh
	{
	public:
		SubMesh(const std::vector<StaticVertex>& vertices, const std::vector<uint32_t> indices);
		SubMesh(const std::vector<SkinnedVertex>& vertices, const std::vector<uint32_t> indices);
		SubMesh(const std::vector<StaticVertex>& vertices, const std::vector<uint32_t> indices, const std::vector<MaterialTexture>& textures, uint32_t materialIndex = 0);
		SubMesh(const std::vector<SkinnedVertex>& vertices, const std::vector<uint32_t> indices, const std::vector<MaterialTexture>& textures, uint32_t materialIndex = 0);

		void Draw(const glm::mat4& transform, const glm::vec3& cameraPos, const Ref<Shader>& shader, int entityID, Mesh* model);
		void Draw();

		uint32_t GetFacesCount() const;

	private:
		void SetupMesh(int entityID);
	public:
		uint32_t mMaterialIndex;

		std::vector<StaticVertex> mStaticVertices;
		std::vector<SkinnedVertex> mSkinnedVertices;
	private:
		std::vector<MaterialTexture> mTextures;

		std::vector<uint32_t> mIndices;

		Ref<VertexArray> mVertexArray;
		Ref<VertexBuffer> mVB;
		Ref<IndexBuffer> mIB;

		int mEntityID = -1;
	};
}


#endif //!SUBMESH_H