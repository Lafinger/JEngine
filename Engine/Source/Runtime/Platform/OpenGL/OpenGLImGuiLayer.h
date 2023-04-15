#ifndef OPENGLIMGUILAYER_H
#define OPENGLIMGUILAYER_H

#define _CRT_SECURE_NO_WARNINGS

#include "Runtime/Application/ImGui/ImGuiLayer.h"

namespace JEngine
{
	class OpenGLImGuiLayer : public ImGuiLayer
	{
	public:
		OpenGLImGuiLayer() = default;
		OpenGLImGuiLayer(const std::string& name) : ImGuiLayer(name) {}
		virtual ~OpenGLImGuiLayer();

		virtual void Begin() override;
		virtual void End() override;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

	private:
		float m_Time = 0.0f;

	};
}


#endif //!OPENGLIMGUILAYER_H