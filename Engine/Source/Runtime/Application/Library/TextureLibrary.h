#ifndef TEXTURELIBRARY_H
#define TEXTURELIBRARY_H

#include "Runtime/Application/Renderer/Texture.h"
#include "Runtime/Application/Library/Library.h"

namespace JEngine
{
    template<>
    class Library<Texture2D> : public LibraryBase<Library, Texture2D>
    {
    public:
        Library();

        [[nodiscard]] Ref<Texture2D> GetDefaultTexture();
        [[nodiscard]] Ref<Texture2D> GetWhiteTexture();
    };
}

#endif //!TEXTURELIBRARY_H