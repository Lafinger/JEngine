#include <glm/glm.hpp>

#include "Runtime/Core/Base/Header.h"

#include "Runtime/Resource/ModeManager.h"
#include "Runtime/Resource/ConfigManager.h"
#include "Runtime/Resource/AssetManager.h"

#include "Runtime/Application/Renderer/Renderer3D.h"
#include "Runtime/Application/Renderer/Texture.h"
#include "Runtime/Application/Renderer/VertexArray.h"
#include "Runtime/Application/Renderer/Shader.h"
#include "Runtime/Application/Renderer/RenderCommand.h"
#include "Runtime/Application/Renderer/UniformBuffer.h"
#include "Runtime/Application/Renderer/Framebuffer.h"
#include "Runtime/Application/Library/ShaderLibrary.h"
#include "Runtime/Application/Library/UniformBufferLibrary.h"
#include "Runtime/Application/Library/Library.h"

namespace JEngine
{
	Ref<Framebuffer> Renderer3D::lightFBO = nullptr;

	void Renderer3D::Init()
	{
		FramebufferSpecification fbSpec;
		fbSpec.Attachments = { FramebufferTextureFormat::DEPTH32F_TEX3D };
		// light depth texture uses high resolution
		fbSpec.Width = 2048;
		fbSpec.Height = 2048;
		lightFBO = Framebuffer::Create(fbSpec);
	}

	void Renderer3D::Shutdown()
	{
	}

	void Renderer3D::DrawModel(const glm::mat4& transform, const glm::vec3& cameraPos, MeshComponent& MeshComponent, int EntityID)
	{
		Ref<Shader> defaultShader = Library<Shader>::GetInstance().GetDefaultShader();
		defaultShader->Bind();
		// if (MeshComponent.mMesh->bPlayAnim)
		// 	defaultShader->SetBool("u_Animated", true);
		// else
			defaultShader->SetBool("u_Animated", false);

		MeshComponent.mMesh->Draw(transform, cameraPos, Library<Shader>::GetInstance().GetDefaultShader(), EntityID);
	}

	void Renderer3D::DrawGeometry(const glm::mat4& transform, const glm::mat4& projection, Ref<Geometry>& geometry, int EntityID)
	{
		Ref<Shader> geometry_shader = Library<Shader>::GetInstance().GetGeometryShader();
		geometry->Draw(transform, projection, geometry_shader, EntityID);
	}

	void Renderer3D::BeginScene(const Camera& camera, const glm::mat4& transform)
	{
		Ref<UniformBuffer> cameraUniform = Library<UniformBuffer>::GetInstance().GetCameraUniformBuffer();
		glm::mat4 ViewProjection = camera.GetProjection() * glm::inverse(transform);
		cameraUniform->SetData(&ViewProjection, sizeof(ViewProjection));
	}

	void Renderer3D::BeginScene(const EditorCamera& camera)
	{
		Ref<UniformBuffer> cameraUniform = Library<UniformBuffer>::GetInstance().GetCameraUniformBuffer();
		glm::mat4 ViewProjection = camera.GetViewProjection();
		cameraUniform->SetData(&ViewProjection, sizeof(ViewProjection));
	}

	void Renderer3D::EndScene()
	{
	}
}