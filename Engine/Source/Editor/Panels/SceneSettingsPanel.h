#ifndef SCENESETTINGSPANEL_H
#define SCENESETTINGSPANEL_H

#include "Runtime/Application/Renderer/Texture.h"

namespace JEngine
{
    class SceneSettingsPanel
    {
    public:
        SceneSettingsPanel();

        void OnImGuiRender(bool* pOpen);
        
    private:
        std::vector<std::string> mPaths;

        // SkyBox
        Ref<Texture2D> mRight;
        Ref<Texture2D> mLeft;
        Ref<Texture2D> mTop;
        Ref<Texture2D> mBottom;
        Ref<Texture2D> mFront;
        Ref<Texture2D> mBack;
    };
}

#endif //!SCENESETTINGSPANEL_H