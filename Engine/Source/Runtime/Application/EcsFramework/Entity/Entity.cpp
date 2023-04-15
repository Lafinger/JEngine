#include "Runtime/Core/Base/Header.h"

#include "Runtime/Application/EcsFramework/Entity/Entity.h"
#include "Runtime/Application/EcsFramework/Component/Basic/IDComponent.h"
#include "Runtime/Application/EcsFramework/Component/Basic/TagComponent.h"

namespace JEngine
{
    Entity::Entity(entt::entity handle, Level* level)
        : mEntityHandle(handle), mLevel(level)
    {
        //AddComponent<IDComponent>(UUID());
    }

    UUID Entity::GetUUID() { return GetComponent<IDComponent>().ID; }
    const std::string& Entity::GetName() { return GetComponent<TagComponent>().Tag; }
}