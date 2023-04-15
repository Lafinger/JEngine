#ifndef RENDERSYSTEM3D_H
#define RENDERSYSTEM3D_H

#include "Runtime/Application/EcsFramework/System/System.h"
#include "Runtime/Application/EcsFramework/Level/Level.h"

namespace JEngine
{
	class RenderSystem3D : public System
	{
	public:
		RenderSystem3D(Level* level) : System(level) {}
		virtual ~RenderSystem3D() = default;
	public:
		void OnUpdateRuntime(Timestep ts) override;
		void OnUpdateEditor(Timestep ts, EditorCamera& camera) override;
	};
}

#endif //!RENDERSYSTEM3D_H