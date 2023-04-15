#ifndef INPUT_HPP
#define INPUT_HPP

#include <glm/glm.hpp>

#include "Runtime/Core/Base/Header.h"

#include "Runtime/Application/Input/KeyCodes.h"
#include "Runtime/Application/Input/MouseCodes.h"

namespace JEngine
{
    class JENGINE_API Input
    {
    public:
        static bool IsKeyPressed(KeyCode key);

        static bool IsMouseButtonPressed(MouseCode button);
        static bool IsMouseButtonReleased(MouseCode button);
        static glm::vec2 GetMousePosition();
        [[nodiscard]] static float GetMouseX();
        [[nodiscard]] static float GetMouseY();
    };
}

#endif //!INPUT_HPP