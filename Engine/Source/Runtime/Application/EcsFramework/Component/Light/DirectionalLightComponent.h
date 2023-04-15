#ifndef DIRECTIONALLIGHTCOMPONENT_H
#define DIRECTIONALLIGHTCOMPONENT_H

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>

#include "Runtime/Application/EcsFramework/Component/ComponentBase.h"
#include "Runtime/Application/Geometry/Geometry.h"

namespace JEngine
{
    class DirectionalLightComponent : public ComponentBase
    {
    public:
        DirectionalLightComponent() = default;
        DirectionalLightComponent(const DirectionalLightComponent&) = default;
        DirectionalLightComponent(float intensity)
            : Intensity(intensity) {}

        float Intensity = 1.0f;
        Ref<Geometry> mGeometry;
    };
}

#endif //!DIRECTIONALLIGHTCOMPONENT_H