#ifndef IDCOMPONENT_H
#define IDCOMPONENT_H

#include "Runtime/Application/EcsFramework/Component/ComponentBase.h"
#include "Runtime/Core/Utils/UUID.h"

namespace JEngine
{
	class IDComponent : public ComponentBase
	{
	public:
		UUID ID;

		IDComponent() = default;
		IDComponent(const IDComponent&) = default;
		IDComponent(const UUID& id)
			: ID(id)
		{
		}
	};
}

#endif //!IDCOMPONENT_H