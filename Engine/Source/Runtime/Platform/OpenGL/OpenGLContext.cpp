#include "Runtime/Core/Base/Header.h"

#include "Runtime/Platform/OpenGL/OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace JEngine
{
    OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
        : mWindowHandle(windowHandle)
    {
        JENGINE_CORE_ASSERT(windowHandle, "Window handle is null!");
    }

    void OpenGLContext::Init()
    {
        // HE_PROFILE_FUNCTION();

        glfwMakeContextCurrent(mWindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        JENGINE_CORE_ASSERT(status, "Failed to initialize Glad!");

        JENGINE_CORE_INFO("OpenGL Info:");
        JENGINE_CORE_INFO("  Vendeor: {0}", glGetString(GL_VENDOR));
        JENGINE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
        JENGINE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
    }

    void OpenGLContext::SwapBuffers()
    {
        // HE_PROFILE_FUNCTION();

        glfwSwapBuffers(mWindowHandle);
    }
}