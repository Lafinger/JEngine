#ifndef LAYER_H
#define LAYER_H

#include "Runtime/Core/Base/Base.h"
#include "Runtime/Core/Utils/Timestep.hpp"
#include "Runtime/Application/Event/Event.hpp"

namespace JEngine
{

	class JENGINE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer") : mDebugName(name) {}
		virtual ~Layer() {}

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		[[nodiscard]] inline const std::string& GetName() const { return mDebugName; }
	protected:
		std::string mDebugName;
	};

}

#endif //!LAYER_H