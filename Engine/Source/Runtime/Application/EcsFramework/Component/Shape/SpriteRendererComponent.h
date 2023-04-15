#ifndef SPRITERENDERERCOMPONENT_H
#define SPRITERENDERERCOMPONENT_H

#include <glm/glm.hpp>

#include "Runtime/Application/EcsFramework/Component/ComponentBase.h"
#include "Runtime/Application/Renderer/Texture.h"

namespace JEngine
{
	class SpriteRendererComponent : public ComponentBase
	{
	public:
		glm::vec4 Color{ 1.0f, 1.0f, 1.0f, 1.0f };
		Ref<Texture2D> Texture;
		float TilingFactor = 1.0f;

		SpriteRendererComponent() = default;
		SpriteRendererComponent(const SpriteRendererComponent&) = default;
		SpriteRendererComponent(const glm::vec4 & color)
			: Color(color) {}
	};
}

#endif //!SPRITERENDERERCOMPONENT_H