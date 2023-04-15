#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include "Runtime/Application/Framework/Window.hpp"
#include "Runtime/Application/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace JEngine
{

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		uint32_t GetWidth() const override { return mData.width; }
		uint32_t GetHeight() const override { return mData.height; }

		// Window attributes
		void SetEventCallback(const EventCallbackFn& callback) override { mData.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const override { return mWindow; }
		virtual Ref<GraphicsContext> GetGraphicsContext() const override { return mContext; };
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* mWindow;
		Ref<GraphicsContext> mContext;

		struct WindowData
		{
			std::string title;
			uint32_t width, height;
			bool vsync;

			EventCallbackFn EventCallback;
		};

		WindowData mData;
	};

}

#endif //WINDOWSWINDOW_H