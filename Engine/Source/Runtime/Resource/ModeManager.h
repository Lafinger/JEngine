#ifndef MODEMANAGER_H
#define MODEMANAGER_H

#include "Runtime/Core/Base/PublicSingleton.h"

namespace JEngine
{
    // From UE4.27.2
    // TODO
    enum class EditMode
    {
        Select = 0,
        Landscape = 1,
        Foliage = 2,
        BrushEditing = 3,
        MeshPaint = 4
    };

    enum class SceneMode
    {
        None = 0,
        EnvironmentHdr = 1,
        SkyBox = 2,
    };

    enum class PhysicsDebugDrawModeFlag
    {
        JEngine_NoDebug = 0,
        JEngine_DrawWireframe = 1,
        JEngine_DrawAabb = 2,
        JEngine_DrawFeaturesText = 4,
        JEngine_DrawContactPoints = 8,
        JEngine_NoDeactivation = 16,
        JEngine_NoHelpText = 32,
        JEngine_DrawText = 64,
        JEngine_ProfileTimings = 128,
        JEngine_EnableSatComparison = 256,
        JEngine_DisableBulletLCP = 512,
        JEngine_EnableCCD = 1024,
        JEngine_DrawConstraints = (1 << 11),
        JEngine_DrawConstraintLimits = (1 << 12),
        JEngine_FastWireframe = (1 << 13),
        JEngine_DrawNormals = (1 << 14),
        JEngine_DrawFrames = (1 << 15),
        JEngine_MAX_DEBUG_DRAW_MODE
    };

    class ModeManager final : public PublicSingleton<ModeManager>
    {
    public:
        static bool IsEditState() { return ModeManager::GetInstance().bEditState; }
        static void ChangeState() { ModeManager::GetInstance().bEditState = !ModeManager::GetInstance().bEditState; }
    public:
        static int b3DMode;  // 0 for 2D, 1 for 3D
        static bool bHdrUse;
        static bool bDebugMode;
        static SceneMode mSceneMode;
        static bool bShowPhysicsColliders;
        static PhysicsDebugDrawModeFlag mPhysicsDebugDrawModeFlag;
    private:
        static bool bEditState;
        static EditMode mEditMode;
    };
}

#endif //!MODEMANAGER_H