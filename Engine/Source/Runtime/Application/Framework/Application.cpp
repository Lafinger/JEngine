#include <GLFW/glfw3.h>

#include "Runtime/Core/Base/Header.h"

#include "Runtime/Application/Framework/Application.h"
#include "Runtime/Application/Input/Input.h"
// #include "Runtime/Resource/ConfigManager.h"

#include "Runtime/Application/Renderer/Renderer.h"
#include "Runtime/Application/Renderer/RenderCommand.h"


namespace JEngine
{
	void Application::PushLayer(Layer* layer)
	{
		mLayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		mLayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::PopLayer(Layer* layer)
	{
		mLayerStack.PopLayer(layer);
		layer->OnDetach();
	}

	void Application::Close()
	{
		bRunning = false;
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(JENGINE_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(JENGINE_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = mLayerStack.rbegin(); it != mLayerStack.rend(); ++it)
		{
			if (e.bHandled)
				break;
			(*it)->OnEvent(e);
		}
	}

	void Application::Init(const std::string& name)
	{
		Log::Init();

		mWindow = Window::Create(WindowProps(name));
		mWindow->SetEventCallback(JENGINE_BIND_EVENT_FN(Application::OnEvent));

		mImGuiLayer = ImGuiLayer::Create();
		PushOverlay(mImGuiLayer);

		Renderer::Init();
	}

	void Application::Run()
	{
		while (bRunning)
		{
			float time = (float)glfwGetTime();
			Timestep timestep = time - mLastFrameTime;
			mLastFrameTime = time;

			if (!bMinimized)
			{
				for (Layer* layer : mLayerStack)
					layer->OnUpdate(timestep);

				mImGuiLayer->Begin();
				for (Layer* layer : mLayerStack)
					layer->OnImGuiRender();
				mImGuiLayer->End();
			}

			mWindow->OnUpdate();
		}
	}

	void Application::Clean()
	{
		Renderer::Shutdown();
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		bRunning = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			bMinimized = true;
			return false;
		}

		bMinimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}

}


