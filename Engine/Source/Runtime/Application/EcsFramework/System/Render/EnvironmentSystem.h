#ifndef ENVIRONMENTSYSTEM_H
#define ENVIRONMENTSYSTEM_H

#include "Runtime/Application/EcsFramework/System/System.h"
#include "Runtime/Application/EcsFramework/Level/Level.h"
#include "Runtime/Application/Renderer/UniformBuffer.h"

namespace JEngine
{
	struct EnvironmentHdrSettings
	{
		float SkyBoxLod = 0.0f;
		float exposure = 1.0f;
		float basedAmbient = 0.1f;
	};

	class EnvironmentSystem : public System
	{
	public:
		EnvironmentSystem(Level* level) : System(level) {}
		virtual ~EnvironmentSystem() = default;
	public:
		void OnUpdateRuntime(Timestep ts) override;
		void OnUpdateEditor(Timestep ts, EditorCamera& camera) override;
	public:
		static EnvironmentHdrSettings environmentSettings;
	private:
		void DrawSkyBox(const glm::mat4& ViewMatrix, const glm::mat4& ProjectMatrix);
		void DrawEnvironmentHdr(const glm::mat4& ViewMatrix, const glm::mat4& ProjectMatrix);
	};
}

#endif //!ENVIRONMENTSYSTEM_H
