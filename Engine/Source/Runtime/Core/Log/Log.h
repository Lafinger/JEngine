#ifndef LOG_H
#define LOG_H

#include "Runtime/Core/Base/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace JEngine
{
	class JENGINE_API Log
	{
	public:
		static void Init();

		[[nodiscard]] inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		[[nodiscard]] inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define JENGINE_CORE_TRACE(...)		::JEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JENGINE_CORE_INFO(...)		::JEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JENGINE_CORE_WARN(...)		::JEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JENGINE_CORE_ERROR(...)		::JEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JENGINE_CORE_FATAL(...)		::JEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define JENGINE_TRACE(...)			::JEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JENGINE_INFO(...)			::JEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define JENGINE_WARN(...)			::JEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JENGINE_ERROR(...)			::JEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define JENGINE_FATAL(...)			::JEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)

#endif //!LOG_H