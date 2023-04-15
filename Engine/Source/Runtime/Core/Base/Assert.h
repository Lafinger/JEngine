#ifndef ASSERT_H
#define ASSERT_H

#include "Runtime/Core/Base/Base.h"
#include "Runtime/Core/Log/Log.h"
#include <filesystem>

#ifdef JENGINE_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define JENGINE_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { JENGINE##type##ERROR(msg, __VA_ARGS__); JENGINE_DEBUGBREAK(); } }
	#define JENGINE_INTERNAL_ASSERT_WITH_MSG(type, check, ...) JENGINE_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define JENGINE_INTERNAL_ASSERT_NO_MSG(type, check) JENGINE_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", JENGINE_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define JENGINE_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define JENGINE_INTERNAL_ASSERT_GET_MACRO(...) JENGINE_EXPAND_MACRO( JENGINE_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, HE_INTERNAL_ASSERT_WITH_MSG, HE_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define JENGINE_ASSERT(...) JENGINE_EXPAND_MACRO( JENGINE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define JENGINE_CORE_ASSERT(...) JENGINE_EXPAND_MACRO( JENGINE_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define JENGINE_ASSERT(...)
	#define JENGINE_CORE_ASSERT(...)
#endif

#endif //!ASSERT_H
