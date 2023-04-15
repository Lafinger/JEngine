#ifndef KEYCODES_H
#define KEYCODES_H

namespace JEngine
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define JENGINE_KEY_SPACE           ::JEngine::Key::Space
#define JENGINE_KEY_APOSTROPHE      ::JEngine::Key::Apostrophe    /* ' */
#define JENGINE_KEY_COMMA           ::JEngine::Key::Comma         /* , */
#define JENGINE_KEY_MINUS           ::JEngine::Key::Minus         /* - */
#define JENGINE_KEY_PERIOD          ::JEngine::Key::Period        /* . */
#define JENGINE_KEY_SLASH           ::JEngine::Key::Slash         /* / */
#define JENGINE_KEY_0               ::JEngine::Key::D0
#define JENGINE_KEY_1               ::JEngine::Key::D1
#define JENGINE_KEY_2               ::JEngine::Key::D2
#define JENGINE_KEY_3               ::JEngine::Key::D3
#define JENGINE_KEY_4               ::JEngine::Key::D4
#define JENGINE_KEY_5               ::JEngine::Key::D5
#define JENGINE_KEY_6               ::JEngine::Key::D6
#define JENGINE_KEY_7               ::JEngine::Key::D7
#define JENGINE_KEY_8               ::JEngine::Key::D8
#define JENGINE_KEY_9               ::JEngine::Key::D9
#define JENGINE_KEY_SEMICOLON       ::JEngine::Key::Semicolon     /* ; */
#define JENGINE_KEY_EQUAL           ::JEngine::Key::Equal         /* = */
#define JENGINE_KEY_A               ::JEngine::Key::A
#define JENGINE_KEY_B               ::JEngine::Key::B
#define JENGINE_KEY_C               ::JEngine::Key::C
#define JENGINE_KEY_D               ::JEngine::Key::D
#define JENGINE_KEY_E               ::JEngine::Key::E
#define JENGINE_KEY_F               ::JEngine::Key::F
#define JENGINE_KEY_G               ::JEngine::Key::G
#define JENGINE_KEY_H               ::JEngine::Key::H
#define JENGINE_KEY_I               ::JEngine::Key::I
#define JENGINE_KEY_J               ::JEngine::Key::J
#define JENGINE_KEY_K               ::JEngine::Key::K
#define JENGINE_KEY_L               ::JEngine::Key::L
#define JENGINE_KEY_M               ::JEngine::Key::M
#define JENGINE_KEY_N               ::JEngine::Key::N
#define JENGINE_KEY_O               ::JEngine::Key::O
#define JENGINE_KEY_P               ::JEngine::Key::P
#define JENGINE_KEY_Q               ::JEngine::Key::Q
#define JENGINE_KEY_R               ::JEngine::Key::R
#define JENGINE_KEY_S               ::JEngine::Key::S
#define JENGINE_KEY_T               ::JEngine::Key::T
#define JENGINE_KEY_U               ::JEngine::Key::U
#define JENGINE_KEY_V               ::JEngine::Key::V
#define JENGINE_KEY_W               ::JEngine::Key::W
#define JENGINE_KEY_X               ::JEngine::Key::X
#define JENGINE_KEY_Y               ::JEngine::Key::Y
#define JENGINE_KEY_Z               ::JEngine::Key::Z
#define JENGINE_KEY_LEFT_BRACKET    ::JEngine::Key::LeftBracket   /* [ */
#define JENGINE_KEY_BACKSLASH       ::JEngine::Key::Backslash     /* \ */
#define JENGINE_KEY_RIGHT_BRACKET   ::JEngine::Key::RightBracket  /* ] */
#define JENGINE_KEY_GRAVE_ACCENT    ::JEngine::Key::GraveAccent   /* ` */
#define JENGINE_KEY_WORLD_1         ::JEngine::Key::World1        /* non-US #1 */
#define JENGINE_KEY_WORLD_2         ::JEngine::Key::World2        /* non-US #2 */

/* Function keys */
#define JENGINE_KEY_ESCAPE          ::JEngine::Key::Escape
#define JENGINE_KEY_ENTER           ::JEngine::Key::Enter
#define JENGINE_KEY_TAB             ::JEngine::Key::Tab
#define JENGINE_KEY_BACKSPACE       ::JEngine::Key::Backspace
#define JENGINE_KEY_INSERT          ::JEngine::Key::Insert
#define JENGINE_KEY_DELETE          ::JEngine::Key::Delete
#define JENGINE_KEY_RIGHT           ::JEngine::Key::Right
#define JENGINE_KEY_LEFT            ::JEngine::Key::Left
#define JENGINE_KEY_DOWN            ::JEngine::Key::Down
#define JENGINE_KEY_UP              ::JEngine::Key::Up
#define JENGINE_KEY_PAGE_UP         ::JEngine::Key::PageUp
#define JENGINE_KEY_PAGE_DOWN       ::JEngine::Key::PageDown
#define JENGINE_KEY_HOME            ::JEngine::Key::Home
#define JENGINE_KEY_END             ::JEngine::Key::End
#define JENGINE_KEY_CAPS_LOCK       ::JEngine::Key::CapsLock
#define JENGINE_KEY_SCROLL_LOCK     ::JEngine::Key::ScrollLock
#define JENGINE_KEY_NUM_LOCK        ::JEngine::Key::NumLock
#define JENGINE_KEY_PRINT_SCREEN    ::JEngine::Key::PrintScreen
#define JENGINE_KEY_PAUSE           ::JEngine::Key::Pause
#define JENGINE_KEY_F1              ::JEngine::Key::F1
#define JENGINE_KEY_F2              ::JEngine::Key::F2
#define JENGINE_KEY_F3              ::JEngine::Key::F3
#define JENGINE_KEY_F4              ::JEngine::Key::F4
#define JENGINE_KEY_F5              ::JEngine::Key::F5
#define JENGINE_KEY_F6              ::JEngine::Key::F6
#define JENGINE_KEY_F7              ::JEngine::Key::F7
#define JENGINE_KEY_F8              ::JEngine::Key::F8
#define JENGINE_KEY_F9              ::JEngine::Key::F9
#define JENGINE_KEY_F10             ::JEngine::Key::F10
#define JENGINE_KEY_F11             ::JEngine::Key::F11
#define JENGINE_KEY_F12             ::JEngine::Key::F12
#define JENGINE_KEY_F13             ::JEngine::Key::F13
#define JENGINE_KEY_F14             ::JEngine::Key::F14
#define JENGINE_KEY_F15             ::JEngine::Key::F15
#define JENGINE_KEY_F16             ::JEngine::Key::F16
#define JENGINE_KEY_F17             ::JEngine::Key::F17
#define JENGINE_KEY_F18             ::JEngine::Key::F18
#define JENGINE_KEY_F19             ::JEngine::Key::F19
#define JENGINE_KEY_F20             ::JEngine::Key::F20
#define JENGINE_KEY_F21             ::JEngine::Key::F21
#define JENGINE_KEY_F22             ::JEngine::Key::F22
#define JENGINE_KEY_F23             ::JEngine::Key::F23
#define JENGINE_KEY_F24             ::JEngine::Key::F24
#define JENGINE_KEY_F25             ::JEngine::Key::F25

/* Keypad */
#define JENGINE_KEY_KP_0            ::JEngine::Key::KP0
#define JENGINE_KEY_KP_1            ::JEngine::Key::KP1
#define JENGINE_KEY_KP_2            ::JEngine::Key::KP2
#define JENGINE_KEY_KP_3            ::JEngine::Key::KP3
#define JENGINE_KEY_KP_4            ::JEngine::Key::KP4
#define JENGINE_KEY_KP_5            ::JEngine::Key::KP5
#define JENGINE_KEY_KP_6            ::JEngine::Key::KP6
#define JENGINE_KEY_KP_7            ::JEngine::Key::KP7
#define JENGINE_KEY_KP_8            ::JEngine::Key::KP8
#define JENGINE_KEY_KP_9            ::JEngine::Key::KP9
#define JENGINE_KEY_KP_DECIMAL      ::JEngine::Key::KPDecimal
#define JENGINE_KEY_KP_DIVIDE       ::JEngine::Key::KPDivide
#define JENGINE_KEY_KP_MULTIPLY     ::JEngine::Key::KPMultiply
#define JENGINE_KEY_KP_SUBTRACT     ::JEngine::Key::KPSubtract
#define JENGINE_KEY_KP_ADD          ::JEngine::Key::KPAdd
#define JENGINE_KEY_KP_ENTER        ::JEngine::Key::KPEnter
#define JENGINE_KEY_KP_EQUAL        ::JEngine::Key::KPEqual

#define JENGINE_KEY_LEFT_SHIFT      ::JEngine::Key::LeftShift
#define JENGINE_KEY_LEFT_CONTROL    ::JEngine::Key::LeftControl
#define JENGINE_KEY_LEFT_ALT        ::JEngine::Key::LeftAlt
#define JENGINE_KEY_LEFT_SUPER      ::JEngine::Key::LeftSuper
#define JENGINE_KEY_RIGHT_SHIFT     ::JEngine::Key::RightShift
#define JENGINE_KEY_RIGHT_CONTROL   ::JEngine::Key::RightControl
#define JENGINE_KEY_RIGHT_ALT       ::JEngine::Key::RightAlt
#define JENGINE_KEY_RIGHT_SUPER     ::JEngine::Key::RightSuper
#define JENGINE_KEY_MENU            ::JEngine::Key::Menu

#endif //!KEYCODES_H