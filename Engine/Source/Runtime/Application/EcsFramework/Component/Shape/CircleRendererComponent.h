#ifndef CIRCLERENDERERCOMPONENT_H
#define CIRCLERENDERERCOMPONENT_H

#include <glm/glm.hpp>

#include "Runtime/Application/EcsFramework/Component/ComponentBase.h"

namespace JEngine
{
	class CircleRendererComponent : public ComponentBase
	{
	public:
		glm::vec4 Color{ 1.0f, 1.0f, 1.0f, 1.0f };
		float Radius = 0.5f;
		float Thickness = 1.0f;
		float Fade = 0.005f;

		CircleRendererComponent() = default;
		CircleRendererComponent(const CircleRendererComponent&) = default;
	};
}

#endif //!CIRCLERENDERERCOMPONENT_H