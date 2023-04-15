#ifndef SHADERLIBRARY_H
#define SHADERLIBRARY_H

#include "Runtime/Application/Renderer/Shader.h"
#include "Runtime/Application/Library/Library.h"

namespace JEngine
{
    template<>
    class Library<Shader> : public LibraryBase<Library, Shader>
    {
    public:
        Library();

        [[nodiscard]] Ref<Shader> GetDefaultShader();
        [[nodiscard]] Ref<Shader> GetSkyBoxShader();
        [[nodiscard]] Ref<Shader> GetGeometryShader();
    };
}

#endif //!SHADERLIBRARY_H