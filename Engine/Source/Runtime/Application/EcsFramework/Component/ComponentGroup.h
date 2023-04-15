#ifndef COMPONENTGROUP_H
#define COMPONENTGROUP_H

#include "Runtime/Application/EcsFramework/Component/ComponentConcept.h"
#include "Runtime/Application/EcsFramework/Component/Basic/IDComponent.h"
#include "Runtime/Application/EcsFramework/Component/Basic/TagComponent.h"
#include "Runtime/Application/EcsFramework/Component/Camera/CameraComponent.h"
// #include "Runtime/Application/EcsFramework/Component/Physics/2D/BoxCollider2DComponent.h"
// #include "Runtime/Application/EcsFramework/Component/Physics/2D/CircleCollider2DComponent.h"
// #include "Runtime/Application/EcsFramework/Component/Physics/2D/Rigidbody2DComponent.h"
// #include "Runtime/Application/EcsFramework/Component/Physics/3D/Rigidbody3DComponent.h"
// #include "Runtime/Application/EcsFramework/Component/Script/NativeScriptComponent.h"
// #include "Runtime/Application/EcsFramework/Component/Script/PythonScriptComponent.h"
#include "Runtime/Application/EcsFramework/Component/Shape/CircleRendererComponent.h"
#include "Runtime/Application/EcsFramework/Component/Shape/SpriteRendererComponent.h"
#include "Runtime/Application/EcsFramework/Component/Transform/TransformComponent.h" 
#include "Runtime/Application/EcsFramework/Component/Mesh/MeshComponent.h" 
#include "Runtime/Application/EcsFramework/Component/Light/PointLightComponent.h"
#include "Runtime/Application/EcsFramework/Component/Light/DirectionalLightComponent.h"
// #include "Runtime/Application/EcsFramework/Component/Audio/SoundComponent.h"

namespace JEngine
{
    // Every Component Class should be registered in this file
    template<Component... C>
    struct ComponentGroup
    {

    };

    // // Component to be copied
    // using AllComponents = ComponentGroup<TransformComponent, CircleRendererComponent, SpriteRendererComponent,
    //     CameraComponent, NativeScriptComponent, PythonScriptComponent, 
    //     Rigidbody2DComponent, BoxCollider2DComponent, CircleCollider2DComponent, 
    //     Rigidbody3DComponent,
    //     MeshComponent, PointLightComponent, DirectionalLightComponent,
    //     SoundComponent>;

    // temp
    using AllComponents = ComponentGroup<TransformComponent,CircleRendererComponent,SpriteRendererComponent,CameraComponent,MeshComponent,PointLightComponent,DirectionalLightComponent>;
}

#endif //!COMPONENTGROUP_H