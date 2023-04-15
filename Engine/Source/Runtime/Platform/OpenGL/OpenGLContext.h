#ifndef OPENGLCONTEXT_H
#define OPENGLCONTEXT_H

#include "Runtime/Application/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace JEngine
{
    class OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow* windowHandle);

        virtual void Init() override;
        virtual void SwapBuffers() override;
    private:
        GLFWwindow* mWindowHandle;
    };
}

#endif //!OPENGLCONTEXT_H