#ifndef SCENEHIERARCHYPANEL_H
#define SCENEHIERARCHYPANEL_H

#include "Runtime/Core/Base/Base.h"

#include "Runtime/Application/EcsFramework/Level/Level.h"
#include "Runtime/Application/EcsFramework/Entity/Entity.h"
#include "Runtime/Application/EcsFramework/Component/ComponentConcept.h"

namespace JEngine
{
    class SceneHierarchyPanel
    {
    public:
        SceneHierarchyPanel() = default;
        SceneHierarchyPanel(const Ref<Level>& context);

        void SetContext(const Ref<Level>& context);

        void OnImGuiRender(bool* pOpen, bool* pOpenProperties);

		Entity GetSelectedEntity() const { return mSelectionEntity; }
		void SetSelectedEntity(Entity entity);
    private:
        template <Component componentType>
        void MenuAddComponent(const char* menuName, const char* menuItemName);
        void DrawEntityNode(Entity entity);
        void DrawComponents(Entity entity);
    private:
        Ref<Level> mContext;
        Entity mSelectionEntity;
    };
}


#endif //!SCENEHIERARCHYPANEL_H