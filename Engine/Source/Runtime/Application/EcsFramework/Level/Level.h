#ifndef LEVEL_H
#define LEVEL_H

#include <entt.hpp>
#include <unordered_map>

#include "Runtime/Core/Utils/Timestep.hpp"
#include "Runtime/Core/Utils/UUID.h"
#include "Runtime/Core/Base/Base.h"
#include "Runtime/Application/Camera/EditorCamera.h"

namespace JEngine
{
    class Entity;

    class Level
    {
    public:
        Level();
        ~Level();

		static Ref<Level> Copy(Ref<Level> other);

        void ChangeDimMode();

        Entity CreateEntity(const std::string& name = std::string());
        Entity CreateEntityWithUUID(UUID uuid, const std::string& name = std::string());
        void DestroyEntity(Entity entity);

		void OnRuntimeStart();
		void OnRuntimeStop();

        void OnUpdateRuntime(Timestep ts);
        void OnUpdateEditor(Timestep ts, EditorCamera& camera);
        void OnViewportResize(uint32_t width, uint32_t height);

		void DuplicateEntity(Entity entity);

		Entity GetPrimaryCameraEntity();

		template<typename... Components>
		auto GetAllEntitiesWith()
		{
			return mRegistry.view<Components...>();
		}
    private:
        template<typename T>
        void OnComponentAdded(Entity entity, T& component);
    public:
        entt::registry mRegistry;
    private:
        std::vector<Scope<class System>> mSystems;

        friend class Entity;
        // friend class SceneSerializer;
        friend class SceneHierarchyPanel;
    };
}

#endif //!LEVEL_H
