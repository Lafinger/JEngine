#ifndef GEOMETRYRENDERER_H
#define GEOMETRYRENDERER_H

#include <cstdint>
#include <memory>
#include <glm/glm.hpp>

namespace JEngine
{
	class BoundingBox;

	namespace component
	{
		struct Light;
	};

	namespace geometry_renderer
	{
		void registerGeometryRenderer(ExecuteQueue &begin, ExecuteQueue &renderer, std::shared_ptr<ExecutePoint> executePoint);
	}

	namespace GeometryRenderer
	{
		void drawLine(const glm::vec3 &start, const glm::vec3 &end, const glm::vec4 &color = {1.0f, 1.0f, 1.0f, 1.0f});
		// void drawFrustum(const Frustum &frustum, const glm::vec4 &color = {1.0f, 1.0f, 1.0f, 1.0f});
		// void drawRect(int32_t x, int32_t y, int32_t width, int32_t height);
		// void drawBox(const glm::vec3 &position, const BoundingBox &box, const glm::vec4 &color);
		// void drawTriangle(const glm::vec3 &v0, const glm::vec3 &v1, const glm::vec3 &v2, const glm::vec4 &color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
		void drawLight(component::Light *light, const glm::quat &rotation, const glm::vec4 &color);
		void drawCone(int32_t numCircleVerts, int32_t numLinesToCircle, float angle, float length, const glm::vec3 &position, const glm::quat &rotation, const glm::vec4 &color, bool backward = false);
		// void drawSphere(float radius, const glm::vec3 &position, const glm::vec4 &color);
		void drawCircle(int32_t numVerts, float radius, const glm::vec3 &position, const glm::quat &rotation, const glm::vec4 &color);
		// void drawCapsule(const glm::vec3 &position, const glm::quat &rotation, float height, float radius, const glm::vec4 &color);
		// void drawArc(int32_t numVerts, float radius, const glm::vec3 &start, const glm::vec3 &end, const glm::quat &rotation, const glm::vec4 &color);
	};        // namespace GeometryRenderer
};            // namespace maple


#endif //!GEOMETRYRENDERER_H