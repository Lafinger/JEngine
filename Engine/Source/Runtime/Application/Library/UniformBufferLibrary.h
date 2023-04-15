#ifndef UNIFORMBUFFERLIBRARY_H
#define UNIFORMBUFFERLIBRARY_H

#include <glm/glm.hpp>

#include "Runtime/Application/Renderer/UniformBuffer.h"
#include "Runtime/Application/Library/Library.h"

namespace JEngine
{
    struct CameraData
    {
        glm::mat4 ViewProjection;
    };

    template<>
    class Library<UniformBuffer> : public LibraryBase<Library, UniformBuffer>
    {
    public:
        Library();

        [[nodiscard]] Ref<UniformBuffer> GetCameraUniformBuffer();
    };
}

#endif //!UNIFORMBUFFERLIBRARY_H