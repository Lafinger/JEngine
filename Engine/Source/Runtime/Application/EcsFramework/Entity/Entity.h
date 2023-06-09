#ifndef ENTITY_H
#define ENTITY_H

#include <entt.hpp>

#include <tuple>
#include <type_traits>

#include "Runtime/Core/Utils/UUID.h"

#include "Runtime/Application/EcsFramework/Level/Level.h"
#include "Runtime/Application/EcsFramework/Component/ComponentGroup.h"


namespace JEngine
{
    class Entity
    {
    public:
        Entity() = default;
        Entity(entt::entity handle, Level* level);
        Entity(const Entity& other) = default;

        template<typename T, typename... Args>
        T& AddComponent(Args&&... args)
        {
            JENGINE_CORE_ASSERT(!HasComponent<T>(), "Entity already has component!");
            T& component = mLevel->mRegistry.emplace<T>(mEntityHandle, std::forward<Args>(args)...);
            mLevel->OnComponentAdded<T>(*this, component);
            return component;
        }

		template<typename T, typename... Args>
		T& AddOrReplaceComponent(Args&&... args)
		{
			T& component = mLevel->mRegistry.emplace_or_replace<T>(mEntityHandle, std::forward<Args>(args)...);
			mLevel->OnComponentAdded<T>(*this, component);
			return component;
		}

        template<typename T>
        T& GetComponent()
        {
            JENGINE_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");
            return mLevel->mRegistry.get<T>(mEntityHandle);
        }

        template<typename... T>
        std::tuple<T*...> GetComponents()
        {
            JENGINE_CORE_ASSERT((HasComponent<T>() && ...), "Entity does not have component!");
            return std::make_tuple<T*...>((&mLevel->mRegistry.get<T>(mEntityHandle))...);
        }

        template<typename... T>
        std::tuple<const T* const...> GetConstComponents()
        {
            JENGINE_CORE_ASSERT((HasComponent<T>() && ...), "Entity does not have component!");
            return std::make_tuple(((const T* const)&mLevel->mRegistry.get<T>(mEntityHandle))...);
        }

        template<typename T>
        bool HasComponent()
        {
            return mLevel->mRegistry.all_of<T>(mEntityHandle);
        }

        template<typename T>
        void RemoveComponent()
        {
            JENGINE_CORE_ASSERT(HasComponent<T>(), "Entity does not have component!");
            mLevel->mRegistry.remove<T>(mEntityHandle);
        }

        operator bool() const { return mEntityHandle != entt::null; }
        operator entt::entity() const { return mEntityHandle; }
        operator uint32_t() const { return (uint32_t)mEntityHandle; }

        UUID GetUUID();
        const std::string& GetName();

        bool operator==(const Entity& other) const 
        { 
            return mEntityHandle == other.mEntityHandle && mLevel == other.mLevel; 
        }

        bool operator!=(const Entity& other) const
        {
            return !(*this == other);
        }
    private:
        entt::entity mEntityHandle{ entt::null };
        Level* mLevel = nullptr;
    };
}

#endif //!ENTITY_H
