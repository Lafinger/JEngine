#ifndef APPLICATION_H
#define APPLICATION_H

#include "Runtime/Core/Utils/Timestep.hpp"

#include "Runtime/Core/Base/Base.h"
#include "Runtime/Core/Base/PublicSingleton.h"
#include "Runtime/Application/Framework/Window.hpp"
#include "Runtime/Application/framework/LayerStack.h"

#include "Runtime/Application/Event/Event.hpp"
#include "Runtime/Application/Event/ApplicationEvent.hpp"
#include "Runtime/Application/Imgui/ImguiLayer.h"

// int main(int argc, char** argv);

namespace JEngine
{
	class Application : public PublicSingleton<Application>
	{
	public:
		Application() = default;
		virtual ~Application() {}

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void PopLayer(Layer* layer);

		[[nodiscard]] Window& GetWindow() { return *mWindow; }

		void Close();

		[[nodiscard]] ImGuiLayer* GetImGuiLayer() { return mImGuiLayer; }
	// private:
		void Init(const std::string& name);
		void Run();
		void Clean();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
		
	private:
		Scope<Window> mWindow;
		ImGuiLayer* mImGuiLayer;
		bool bRunning = true;
		bool bMinimized = false;
		LayerStack mLayerStack;
		float mLastFrameTime = 0.0f;
	// private:
	// 	friend int ::main(int argc, char** argv);

		// To be defined in CLIENT
		// friend void MyAppInitialize(Application& app);
	};
}


#endif //!APPLICATION_H
