#ifndef WINDOW_H
#define WINDOW_H

#include "Runtime/Core/Base/Header.h"

#include "Runtime/Core/base/Base.h"
#include "Runtime/Application/Event/Event.hpp"
#include "Runtime/Application/Renderer/GraphicsContext.h"

namespace JEngine
{

	struct WindowProps
	{
		std::string title;
		uint32_t width;
		uint32_t height;

		WindowProps(const std::string& title = "JEngine",
			uint32_t width = 1600,
			uint32_t height = 900)
			: title(title), width(width), height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	class JENGINE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		[[nodiscard]] virtual uint32_t GetWidth() const = 0;
		[[nodiscard]] virtual uint32_t GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		[[nodiscard]] virtual void* GetNativeWindow() const = 0;
		[[nodiscard]] virtual Ref<GraphicsContext> GetGraphicsContext() const = 0;

		static Scope<Window> Create(const WindowProps& props = WindowProps());
	};

}

#endif //!WINDOW_H