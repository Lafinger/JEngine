#include "Runtime/Core/Base/Header.h"

#include "Runtime/Application/Renderer/RenderCommand.h"

#include "Runtime/Platform/OpenGL/OpenGLRendererAPI.h"
// #include "Runtime/Platform/DirectX11/Dx11RendererAPI.h"

namespace JEngine
{
	Scope<RendererAPI> RenderCommand::sRendererAPI = CreateScope<OpenGLRendererAPI>();
}
