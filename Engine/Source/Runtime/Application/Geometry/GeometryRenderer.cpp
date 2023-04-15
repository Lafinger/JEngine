#include <glm/glm.hpp>

#include "Runtime/Core/Base/Header.h"
#include "Runtime/Application/Renderer/GeometryRenderer.h"

namespace JEngine
{
	struct GeometryLine
	{
		glm::vec3 start;
		glm::vec3 end;
		glm::vec4 color;
	};

	struct GeometryPoint
	{
		glm::vec3 p1;
		glm::vec4 color;
		float     size;
	};

	struct GeometryTriangle
	{
		glm::vec3 p1;
		glm::vec3 p2;
		glm::vec3 p3;
		glm::vec4 color;
	};

	namespace
	{
		constexpr uint32_t MaxPoints               = 10000;
		constexpr uint32_t MaxPointVertices        = MaxPoints * 4;
		constexpr uint32_t MaxPointIndices         = MaxPoints * 6;
		constexpr uint32_t MaxBatchDrawCalls       = 100;
		constexpr uint32_t RendererPointSize       = sizeof(PointVertex) * 4;
		constexpr uint32_t RendererPointBufferSize = RendererPointSize * MaxPointVertices;

		constexpr uint32_t MaxLines               = 10000;
		constexpr uint32_t MaxLineVertices        = MaxLines * 2;
		constexpr uint32_t MaxLineIndices         = MaxLines * 6;
		constexpr uint32_t MaxLineBatchDrawCalls  = 100;
		constexpr uint32_t RendererLineSize       = sizeof(LineVertex) * 4;
		constexpr uint32_t RendererLineBufferSize = RendererLineSize * MaxLineVertices;
	}        // namespace

	namespace component
	{
		struct GeometryRenderData
		{
			std::vector<GeometryLine>     lines;
			std::vector<GeometryTriangle> triangles;
			std::vector<GeometryPoint>    points;

			std::shared_ptr<VertexBuffer> lineVertexBuffers;
			std::shared_ptr<VertexBuffer> pointVertexBuffers;

			std::shared_ptr<IndexBuffer> lineIndexBuffer;
			std::shared_ptr<IndexBuffer> pointIndexBuffer;

			std::vector<std::shared_ptr<DescriptorSet>> pointDescriptorSet;
			std::vector<std::shared_ptr<DescriptorSet>> lineDescriptorSet;

			LineVertex * lineBuffer  = nullptr;
			PointVertex *pointBuffer = nullptr;

			uint32_t lineIndexCount          = 0;
			uint32_t pointIndexCount         = 0;
			uint32_t lineBatchDrawCallIndex  = 0;
			uint32_t pointBatchDrawCallIndex = 0;

			std::shared_ptr<Shader> lineShader;
			std::shared_ptr<Shader> pointShader;

			GeometryRenderData()
			{
				pointShader = Shader::create("shaders/BatchPoint.shader");
				lineShader  = Shader::create("shaders/BatchLine.shader");

				{
					DescriptorInfo descriptorInfo{};
					descriptorInfo.layoutIndex = 0;
					descriptorInfo.shader      = pointShader.get();
					pointDescriptorSet.emplace_back(DescriptorSet::create(descriptorInfo));

					pointVertexBuffers = VertexBuffer::create(BufferUsage::Dynamic);
					pointVertexBuffers->resize(RendererPointBufferSize);

					std::vector<uint32_t> indices;
					indices.resize(MaxPointIndices);

					for (int32_t i = 0, offset = 0; i < MaxPointIndices; i += 6, offset += 4)
					{
						indices[i]     = offset + 0;
						indices[i + 1] = offset + 1;
						indices[i + 2] = offset + 2;

						indices[i + 3] = offset + 2;
						indices[i + 4] = offset + 3;
						indices[i + 5] = offset + 0;
					}

					pointIndexBuffer = IndexBuffer::create(indices.data(), MaxPointIndices);
				}
				{
					DescriptorInfo descriptorLineInfo{};
					descriptorLineInfo.layoutIndex = 0;
					descriptorLineInfo.shader      = lineShader.get();
					lineDescriptorSet.emplace_back(DescriptorSet::create(descriptorLineInfo));

					lineVertexBuffers = VertexBuffer::create(BufferUsage::Dynamic);
					lineVertexBuffers->resize(RendererLineBufferSize);

					std::vector<uint32_t> indices;
					indices.resize(MaxLineIndices);
					for (int32_t i = 0; i < MaxLineIndices; i++)
					{
						indices[i] = i;
					}
					lineIndexBuffer = IndexBuffer::create(indices.data(), MaxLineIndices);
				}
			}
		};
	}        // namespace component

	void GeometryRenderer::drawLine(const glm::vec3 &start, const glm::vec3 &end, const glm::vec4 &color)
	{
		auto &renderData = Application::getExecutePoint()->getGlobalComponent<component::GeometryRenderData>();
		renderData.lines.push_back({start, end, color});
	}

	// void GeometryRenderer::drawFrustum(const Frustum &frustum, const glm::vec4 &color)
	// {
	// 	const glm::vec3 *vertices = frustum.getVertices();

	// 	auto c = color * 0.6f;
	// 	c.a    = 1.0f;

	// 	drawLine(vertices[0], vertices[1], c);
	// 	drawLine(vertices[1], vertices[2], c);
	// 	drawLine(vertices[2], vertices[3], c);
	// 	drawLine(vertices[3], vertices[0], c);
	// 	drawLine(vertices[4], vertices[5], color);
	// 	drawLine(vertices[5], vertices[6], color);
	// 	drawLine(vertices[6], vertices[7], color);
	// 	drawLine(vertices[7], vertices[4], color);
	// 	drawLine(vertices[0], vertices[4], color);
	// 	drawLine(vertices[1], vertices[5], color);
	// 	drawLine(vertices[2], vertices[6], color);
	// 	drawLine(vertices[3], vertices[7], color);
	// }

	// void GeometryRenderer::drawRect(int32_t x, int32_t y, int32_t width, int32_t height)
	// {
	// 	auto right  = x + width;
	// 	auto bottom = y + height;

	// 	drawLine({x, y, 0}, {right, y, 0});
	// 	drawLine({right, y, 0}, {right, bottom, 0});
	// 	drawLine({right, bottom, 0}, {x, bottom, 0});
	// 	drawLine({x, bottom, 0}, {x, y, 0});
	// }

	// void GeometryRenderer::drawBox(const glm::vec3 &position, const BoundingBox &box, const glm::vec4 &color)
	// {
	// 	glm::vec3 uuu = box.max + position;
	// 	glm::vec3 lll = box.min + position;
	// 	glm::vec3 ull(uuu.x, lll.y, lll.z);
	// 	glm::vec3 uul(uuu.x, uuu.y, lll.z);
	// 	glm::vec3 ulu(uuu.x, lll.y, uuu.z);
	// 	glm::vec3 luu(lll.x, uuu.y, uuu.z);
	// 	glm::vec3 llu(lll.x, lll.y, uuu.z);
	// 	glm::vec3 lul(lll.x, uuu.y, lll.z);

	// 	drawLine(luu, uuu, color);
	// 	drawLine(lul, uul, color);
	// 	drawLine(llu, ulu, color);
	// 	drawLine(lll, ull, color);
	// 	drawLine(lul, lll, color);
	// 	drawLine(uul, ull, color);
	// 	drawLine(luu, llu, color);
	// 	drawLine(uuu, ulu, color);
	// 	drawLine(lll, llu, color);
	// 	drawLine(ull, ulu, color);
	// 	drawLine(lul, luu, color);
	// 	drawLine(uul, uuu, color);
	// }

	// void GeometryRenderer::drawTriangle(const glm::vec3 &v0, const glm::vec3 &v1, const glm::vec3 &v2, const glm::vec4 &color)
	// {
	// 	auto &renderData = Application::getExecutePoint()->getGlobalComponent<component::GeometryRenderData>();
	// 	renderData.triangles.push_back({v0, v1, v2, color});
	// }

	void GeometryRenderer::drawLight(component::Light *light, const glm::quat &rotation, const glm::vec4 &color)
	{
		// Directional
		if (light->lightData.type < 0.1f)
		{
			glm::vec3 offset(0.0f, 0.1f, 0.0f);
			drawLine(glm::vec3(light->lightData.position) + offset, glm::vec3(light->lightData.position + (light->lightData.direction) * 2.0f) + offset, color);
			drawLine(glm::vec3(light->lightData.position) - offset, glm::vec3(light->lightData.position + (light->lightData.direction) * 2.0f) - offset, color);
			drawLine(glm::vec3(light->lightData.position), glm::vec3(light->lightData.position + (light->lightData.direction) * 2.0f), color);

			drawCone(60, 4, 30.0f, 1.5f, (light->lightData.position - (light->lightData.direction) * 1.5f), rotation, color);
		}
		// Spot
		else if (light->lightData.type < 1.1f)
		{
			drawCone(60, 4, light->lightData.angle, light->lightData.intensity, light->lightData.position, rotation, color, true);
		}
		// Point
		else
		{
			drawSphere(light->lightData.radius / 2.0f, light->lightData.position, color);
		}
	}

	void GeometryRenderer::drawCone(int32_t numCircleVerts, int32_t numLinesToCircle, float angle, float length, const glm::vec3 &position, const glm::quat &rotation, const glm::vec4 &color, bool backward)
	{
		float     endAngle    = std::tan(angle * 0.5f) * length;
		glm::vec3 forward     = glm::normalize(rotation * maple::FORWARD * (backward ? -1.f : 1.f));
		glm::vec3 endPosition = position + forward * length;
		float     offset      = 0.0f;
		drawCircle(numCircleVerts, endAngle, endPosition, rotation, color);

		for (int i = 0; i < numLinesToCircle; i++)
		{
			float     a     = glm::radians(i * 90.0f);
			glm::vec3 point = rotation * glm::vec3(std::cos(a), std::sin(a), 0.0f) * endAngle;
			drawLine(position, position + point + forward * length, color);
		}
	}

	// void GeometryRenderer::drawSphere(float radius, const glm::vec3 &position, const glm::vec4 &color)
	// {
	// 	drawCircle(60, radius, position, glm::quat(glm::vec3(0.0f, 0.0f, 0.0f)), color);
	// 	drawCircle(60, radius, position, glm::quat(glm::vec3(45.0f, 0.0f, 0.0f)), color);

	// 	drawCircle(60, radius, position, glm::quat(glm::vec3(0.0f, 45.0f, 0.0f)), color);
	// 	drawCircle(60, radius, position, glm::quat(glm::vec3(0.0f, 90.0f, 0.0f)), color);

	// 	drawCircle(60, radius, position, glm::quat(glm::vec3(0.0f, 0, 45.0f)), color);
	// 	drawCircle(60, radius, position, glm::quat(glm::vec3(0.0f, 0, 90.0f)), color);

	// 	drawCircle(60, radius, position, glm::quat(glm::vec3(0.0f, 90.f, 90.0f)), color);
	// 	drawCircle(60, radius, position, glm::quat(glm::vec3(0.0f, 45.f, 90.0f)), color);
	// }

	void GeometryRenderer::drawCircle(int32_t numVerts, float radius, const glm::vec3 &position, const glm::quat &rotation, const glm::vec4 &color)
	{
		float step = 360.0f / float(numVerts);

		for (int i = 0; i < numVerts; i++)
		{
			float     cx      = std::cos(step * i) * radius;
			float     cy      = std::sin(step * i) * radius;
			glm::vec3 current = glm::vec3(cx, cy, 0.0f);

			float     nx   = std::cos(step * (i + 1)) * radius;
			float     ny   = std::sin(step * (i + 1)) * radius;
			glm::vec3 next = glm::vec3(nx, ny, 0.0f);

			drawLine(position + (rotation * current), position + (rotation * next), color);
		}
	}

	// void GeometryRenderer::drawArc(int32_t numVerts, float radius, const glm::vec3 &start, const glm::vec3 &end, const glm::quat &rotation, const glm::vec4 &color)
	// {
	// 	PROFILE_FUNCTION();
	// 	float     step = 180.0f / numVerts;
	// 	glm::quat rot  = glm::lookAt(rotation * start, rotation * end, maple::UP);
	// 	rot            = rotation * rot;

	// 	glm::vec3 arcCentre = (start + end) * 0.5f;
	// 	for (int i = 0; i < numVerts; i++)
	// 	{
	// 		float     cx      = std::cos(glm::radians(step * i)) * radius;
	// 		float     cy      = std::sin(glm::radians(step * i)) * radius;
	// 		glm::vec3 current = glm::vec3(cx, cy, 0.0f);

	// 		float     nx   = std::cos(glm::radians(step * (i + 1))) * radius;
	// 		float     ny   = std::sin(glm::radians(step * (i + 1))) * radius;
	// 		glm::vec3 next = glm::vec3(nx, ny, 0.0f);

	// 		drawLine(arcCentre + (rot * current), arcCentre + (rot * next), color);
	// 	}
	// }

	// void GeometryRenderer::drawCapsule(const glm::vec3 &position, const glm::quat &rotation, float height, float radius, const glm::vec4 &color)
	// {
	// 	PROFILE_FUNCTION();
	// 	glm::vec3 up = (rotation * maple::UP);

	// 	glm::vec3 topSphereCentre    = position + up * (height * 0.5f);
	// 	glm::vec3 bottomSphereCentre = position - up * (height * 0.5f);

	// 	drawCircle(20, radius, topSphereCentre, rotation * glm::quat(glm::vec3(glm::radians(90.0f), 0.0f, 0.0f)), color);
	// 	drawCircle(20, radius, bottomSphereCentre, rotation * glm::quat(glm::vec3(glm::radians(90.0f), 0.0f, 0.0f)), color);

	// 	float step = 360.0f / float(20);
	// 	for (int32_t i = 0; i < 20; i++)
	// 	{
	// 		float z = std::cos(glm::radians(step * i)) * radius;
	// 		float x = std::sin(glm::radians(step * i)) * radius;

	// 		glm::vec3 offset = rotation * glm::vec4(x, 0.0f, z, 0.0f);
	// 		drawLine(bottomSphereCentre + offset, topSphereCentre + offset, color);

	// 		if (i < 10)
	// 		{
	// 			float z2 = std::cos(glm::radians(step * (i + 10))) * radius;
	// 			float x2 = std::sin(glm::radians(step * (i + 10))) * radius;

	// 			glm::vec3 offset2 = rotation * glm::vec4(x2, 0.0f, z2, 0.0f);
	// 			//Top Hemisphere
	// 			drawArc(10, radius, topSphereCentre + offset, topSphereCentre + offset2, rotation, color);
	// 			//Bottom Hemisphere
	// 			drawArc(10, radius, bottomSphereCentre + offset, bottomSphereCentre + offset2, rotation * glm::quat(glm::vec3(glm::radians(180.0f), 0.0f, 0.0f)), color);
	// 		}
	// 	}
	// }

	namespace on_begin_scene
	{
		using Entity = ecs::Registry ::Fetch<component::RendererData>::Modify<component::GeometryRenderData>::Fetch<component::CameraView>::To<ecs::Entity>;

		inline void system(Entity entity, ecs::World world)
		{
			auto [render, geometry, cameraView] = entity;
			geometry.lineDescriptorSet[0]->setUniform("UniformBufferObject", "projView", &cameraView.projView);
			geometry.pointDescriptorSet[0]->setUniform("UniformBufferObject", "projView", &cameraView.projView);
		}
	}        // namespace on_begin_scene

	namespace on_render_lines
	{
		using Entity = ecs::Registry ::Fetch<component::RendererData>::Modify<component::GeometryRenderData>::Modify<component::CameraView>::Modify<capture_graph::component::RenderGraph>::To<ecs::Entity>;

		inline void systemLines(Entity entity, ecs::World world)
		{
			auto [render, geometry, cameraView, graph] = entity;
			auto commandBuffer                         = render.commandBuffer;

			if (!geometry.lines.empty())
			{
				geometry.lineDescriptorSet[0]->update(render.commandBuffer);

				PipelineInfo pipelineInfo;
				pipelineInfo.shader              = geometry.lineShader;
				pipelineInfo.polygonMode         = PolygonMode::Fill;
				pipelineInfo.cullMode            = CullMode::Back;
				pipelineInfo.transparencyEnabled = false;
				pipelineInfo.clearTargets        = false;
				pipelineInfo.drawType            = DrawType::Lines;
				pipelineInfo.colorTargets[0]     = render.gbuffer->getBuffer(GBufferTextures::SCREEN);

				auto pipeline = Pipeline::get(pipelineInfo, geometry.lineDescriptorSet, graph);

				pipeline->bind(commandBuffer);
				geometry.lineVertexBuffers->bind(commandBuffer, pipeline.get());
				geometry.lineBuffer = geometry.lineVertexBuffers->getPointer<LineVertex>();

				for (auto &line : geometry.lines)
				{
					geometry.lineBuffer->vertex = line.start;
					geometry.lineBuffer->color  = line.color;
					geometry.lineBuffer++;
					geometry.lineBuffer->vertex = line.end;
					geometry.lineBuffer->color  = line.color;
					geometry.lineBuffer++;
					geometry.lineIndexCount += 2;
				}

				geometry.lineVertexBuffers->releasePointer();
				geometry.lineVertexBuffers->unbind();

				geometry.lineIndexBuffer->setCount(geometry.lineIndexCount);
				geometry.lineVertexBuffers->bind(commandBuffer, pipeline.get());
				geometry.lineIndexBuffer->bind(commandBuffer);

				Renderer::bindDescriptorSets(pipeline.get(), commandBuffer, 0, geometry.lineDescriptorSet);
				Renderer::drawIndexed(commandBuffer, DrawType::Lines, geometry.lineIndexCount);

				geometry.lineVertexBuffers->unbind();
				geometry.lineIndexBuffer->unbind();

				geometry.lineIndexCount = 0;

				pipeline->end(commandBuffer);

				geometry.lines.clear();
			}
		}

		inline void systemPoints(Entity entity, ecs::World world)
		{
			auto [render, geometry, cameraView, graph] = entity;
			auto commandBuffer                         = render.commandBuffer;

			if (!geometry.points.empty())
			{
				geometry.pointDescriptorSet[0]->update(render.commandBuffer);
				PipelineInfo pipelineInfo;
				pipelineInfo.shader              = geometry.pointShader;
				pipelineInfo.polygonMode         = PolygonMode::Fill;
				pipelineInfo.cullMode            = CullMode::Back;
				pipelineInfo.transparencyEnabled = true;
				pipelineInfo.drawType            = DrawType::Triangle;
				pipelineInfo.blendMode           = BlendMode::SrcAlphaOneMinusSrcAlpha;
				pipelineInfo.colorTargets[0]     = render.gbuffer->getBuffer(GBufferTextures::SCREEN);

				auto pipeline = Pipeline::get(pipelineInfo, geometry.pointDescriptorSet, graph);

				pipeline->bind(commandBuffer);
				geometry.pointVertexBuffers->bind(commandBuffer, pipeline.get());
				geometry.pointBuffer = geometry.pointVertexBuffers->getPointer<PointVertex>();

				for (auto &pointInfo : geometry.points)
				{
					auto right = pointInfo.size * cameraView.cameraTransform->getRightDirection();
					auto up    = pointInfo.size * cameraView.cameraTransform->getUpDirection();

					geometry.pointBuffer->vertex = pointInfo.p1 - right - up;
					geometry.pointBuffer->color  = pointInfo.color;
					geometry.pointBuffer->size   = {pointInfo.size, 0.0f};
					geometry.pointBuffer->uv     = {-1.0f, -1.0f};
					geometry.pointBuffer++;

					geometry.pointBuffer->vertex = pointInfo.p1 + right - up;
					geometry.pointBuffer->color  = pointInfo.color;
					geometry.pointBuffer->size   = {pointInfo.size, 0.0f};
					geometry.pointBuffer->uv     = {1.0f, -1.0f};
					geometry.pointBuffer++;

					geometry.pointBuffer->vertex = pointInfo.p1 + right + up;
					geometry.pointBuffer->color  = pointInfo.color;
					geometry.pointBuffer->size   = {pointInfo.size, 0.0f};
					geometry.pointBuffer->uv     = {1.0f, 1.0f};
					geometry.pointBuffer++;

					geometry.pointBuffer->vertex = pointInfo.p1 - right + up;
					geometry.pointBuffer->color  = pointInfo.color;
					geometry.pointBuffer->size   = {pointInfo.size, 0.0f};
					geometry.pointBuffer->uv     = {-1.0f, 1.0f};
					geometry.pointBuffer++;

					geometry.pointIndexCount += 6;
				}

				geometry.pointVertexBuffers->releasePointer();
				geometry.pointIndexBuffer->setCount(geometry.pointIndexCount);
				geometry.pointIndexBuffer->bind(commandBuffer);

				Renderer::bindDescriptorSets(pipeline.get(), commandBuffer, 0, geometry.pointDescriptorSet);
				Renderer::drawIndexed(commandBuffer, DrawType::Triangle, geometry.pointIndexCount);

				geometry.pointVertexBuffers->unbind();
				geometry.pointIndexBuffer->unbind();

				geometry.pointIndexCount = 0;

				pipeline->end(commandBuffer);

				geometry.pointBatchDrawCallIndex++;

				geometry.points.clear();
			}
		}
	}        // namespace on_render_lines

	namespace geometry_renderer
	{
		void registerGeometryRenderer(ExecuteQueue &begin, ExecuteQueue &renderer, std::shared_ptr<ExecutePoint> executePoint)
		{
			executePoint->registerGlobalComponent<component::GeometryRenderData>();
			executePoint->registerWithinQueue<on_begin_scene::system>(begin);
			executePoint->registerWithinQueue<on_render_lines::systemLines>(renderer);
			executePoint->registerWithinQueue<on_render_lines::systemPoints>(renderer);
		}
	}        // namespace geometry_renderer

};        // namespace maple
