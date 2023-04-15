#ifndef CAMERACOMPONENT_H
#define CAMERACOMPONENT_H

#include "Runtime/Application/EcsFramework/Component/ComponentBase.h"
#include "Runtime/Application/Camera/SceneCamera.h"

namespace JEngine
{
	class CameraComponent : public ComponentBase
	{
	public:
        SceneCamera Camera;
        bool Primary = true; // TODO: think about moving to Scene
        bool FixedAspectRatio = false;

        CameraComponent() = default;
        CameraComponent(const CameraComponent&) = default;
	};
}

#endif //!CAMERACOMPONENT_H