#ifndef MOUSECODES_H
#define MOUSECODES_H

namespace JEngine
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define JENGINE_MOUSE_BUTTON_0      ::JEngine::Mouse::Button0
#define JENGINE_MOUSE_BUTTON_1      ::JEngine::Mouse::Button1
#define JENGINE_MOUSE_BUTTON_2      ::JEngine::Mouse::Button2
#define JENGINE_MOUSE_BUTTON_3      ::JEngine::Mouse::Button3
#define JENGINE_MOUSE_BUTTON_4      ::JEngine::Mouse::Button4
#define JENGINE_MOUSE_BUTTON_5      ::JEngine::Mouse::Button5
#define JENGINE_MOUSE_BUTTON_6      ::JEngine::Mouse::Button6
#define JENGINE_MOUSE_BUTTON_7      ::JEngine::Mouse::Button7
#define JENGINE_MOUSE_BUTTON_LAST   ::JEngine::Mouse::ButtonLast
#define JENGINE_MOUSE_BUTTON_LEFT   ::JEngine::Mouse::ButtonLeft
#define JENGINE_MOUSE_BUTTON_RIGHT  ::JEngine::Mouse::ButtonRight
#define JENGINE_MOUSE_BUTTON_MIDDLE ::JEngine::Mouse::ButtonMiddle

#endif //!MOUSECODES_H