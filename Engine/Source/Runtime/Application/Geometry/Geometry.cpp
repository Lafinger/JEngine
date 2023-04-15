#include "Runtime/Core/Base/Header.h"
#include "Runtime/Resource/ModeManager.h"

#include "Runtime/Application/Geometry/Geometry.h"
#include "Runtime/Application/Renderer/RenderCommand.h"
#include "Runtime/Application/Library/Library.h"

namespace JEngine
{
	Geometry::Geometry(const GeometryType type)
		: mType(type)
	{
		mVertexArray = VertexArray::Create();
        // setup data
		SetupGeometry();
	}

	void Geometry::Draw(const glm::mat4& transform, const glm::mat4& projection, Ref<Shader>& shader, int entityID)
	{
        mEntityID = entityID;
        // shader
		shader->Bind();
		shader->SetMat4("u_modelMat4", transform);
        shader->SetMat4("u_projectionMat4", projection);

        RenderCommand::SetLineWidth(1.0);
		// RenderCommand::DrawIndexed(mVertexArray, mIB->GetCount());
        RenderCommand::DrawLines(mVertexArray, mGeometryVertexs.size());
	}

	void Geometry::SetupGeometry()
	{    
        if(GeometryType::None == mType)
        {
            JENGINE_CORE_WARN("Geometry Type is none");
            return; 
        }
        else if (GeometryType::Light == mType)
        {
            // light
            // generate vertex
            SetupLightGeometry();

            // setup vertex
            mVB = VertexBuffer::Create(sizeof(GeometryVertex) * mGeometryVertexs.size());
		    mVB->SetLayout({
					{ ShaderDataType::Float3, "a_Pos"},
			});
            mVertexArray->AddVertexBuffer(mVB);

            // mIB = IndexBuffer::Create(indices.size());
		    // mVertexArray->SetIndexBuffer(mIB);

            mVertexArray->Bind();
            mVB->SetData(mGeometryVertexs.data(), sizeof(GeometryVertex) * mGeometryVertexs.size());
            // mIB->SetData(mIndices.data(), mIndices.size());
            mVertexArray->Unbind();
        }
        else
        {
            // camera
        }
	}

    void Geometry::SetupLightGeometry()
    {
        // Directional
        SetupCone(60, 4, 30.0f, 1.5f, (glm::vec3(0.0,0.0,0.0) - glm::vec3(0.0,-1.0,0.0) * 1.5f));
    
        // // Spot
        // drawCone(60, 4, light->lightData.angle, light->lightData.intensity, light->lightData.position, rotation, color, true);

        // // Point
        // drawSphere(light->lightData.radius / 2.0f, light->lightData.position, color);
    }

    // void Geometry::drawCamera(component::Light *light, const glm::quat &rotation, const glm::vec4 &color)
    // {

    // }

    void Geometry::SetupCone(int32_t numCircleVerts, int32_t numLinesToCircle, float angle, float length, const glm::vec3 &position, bool backward)
    {
        float     endAngle    = std::tan(angle * 0.5f) * length;
		glm::vec3 forward     = glm::normalize(glm::vec3(0.0, -1.0, 0.0) * (backward ? 1.f : -1.f));
		glm::vec3 endPosition = position + forward * length;
		float     offset      = 0.0f;
		SetupCircle(numCircleVerts, endAngle, endPosition);

		for (int i = 0; i < numLinesToCircle; i++)
		{
			float     a     = glm::radians(i * 90.0f);
			glm::vec3 point = glm::vec3(std::cos(a), std::sin(a), 0.0f) * endAngle;
			SetupLine(position, position + point + forward * length);
		}
    }

    void Geometry::SetupCircle(int32_t numVerts, float radius, const glm::vec3 &position)
    {
        float step = 360.0f / float(numVerts);

		for (int i = 0; i < numVerts; i++)
		{
			float     cx      = std::cos(step * i) * radius;
			float     cz      = std::sin(step * i) * radius;
			glm::vec3 current = glm::vec3(cx, 0.0f, cz);

			float     nx   = std::cos(step * (i + 1)) * radius;
			float     nz   = std::sin(step * (i + 1)) * radius;
			glm::vec3 next = glm::vec3(nx, 0.0f, nz);

			SetupLine(position + current, position +next);
		}
    }

    void Geometry::SetupLine(const glm::vec3 &start, const glm::vec3 &end)
    {
        GeometryVertex start_vertex;
        GeometryVertex end_vertex;
        start_vertex.Pos = start;
        end_vertex.Pos = end;
        mGeometryVertexs.emplace_back(start_vertex);
        mGeometryVertexs.emplace_back(end_vertex);
    }
}