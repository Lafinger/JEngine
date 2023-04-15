#include "Runtime/Core/Base/Header.h"

#include "Runtime/Resource/ModeManager.h"

namespace JEngine
{
    int ModeManager::b3DMode = 1;
    bool ModeManager::bHdrUse = false;
    bool ModeManager::bEditState = true;
    SceneMode ModeManager::mSceneMode = SceneMode::None;
    EditMode ModeManager::mEditMode = EditMode::Select;
    bool ModeManager::bShowPhysicsColliders = false;
    PhysicsDebugDrawModeFlag ModeManager::mPhysicsDebugDrawModeFlag = PhysicsDebugDrawModeFlag::JEngine_DrawWireframe;
}