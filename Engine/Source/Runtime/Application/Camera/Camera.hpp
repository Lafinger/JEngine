#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>

namespace JEngine
{
    class Camera
    {
    public:
        Camera() = default;
        Camera(const glm::mat4& projection)
            : mProjection(projection) {}

        virtual ~Camera() = default;

        [[nodiscard]] const glm::mat4& GetProjection() const { return mProjection; }
    protected:
        glm::mat4 mProjection = glm::mat4(1.0f);
    };
}


#endif //!CAMERA_HPP