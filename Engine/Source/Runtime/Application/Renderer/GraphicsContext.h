#ifndef GRAPHICSCONTEXT_H
#define GRAPHICSCONTEXT_H

namespace JEngine
{
    class GraphicsContext
    {
    public:
        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;

        static Ref<GraphicsContext> Create(void* window);
    };
}

#endif //!GRAPHICSCONTEXT_H