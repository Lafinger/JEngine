#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#include "Runtime/Application/Framework/Layer.hpp"

#include "Runtime/Application/Event/ApplicationEvent.hpp"
#include "Runtime/Application/Event/KeyEvent.hpp"
#include "Runtime/Application/Event/MouseEvent.hpp"

namespace JEngine
{
    class ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ImGuiLayer(const std::string& name);
        ~ImGuiLayer();

        virtual void OnEvent(Event& e) override;

        virtual void Begin() {};
        virtual void End() {};
        virtual void OnImGuiRender() {}

        static ImGuiLayer* Create();

        void BlockEvents(bool block) { mBlockEvents = block; }

        void SetDarkThemeColors();
    private:
        bool mBlockEvents = true;
    };
}

#endif //!IMGUILAYER_H
