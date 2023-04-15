#include <spdlog/sinks/stdout_color_sinks.h>

#include "Runtime/Core/Base/Header.h"
#include "Runtime/Core/Log/Log.h"

namespace JEngine
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	 
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");  // 设置样式，有适当的颜色、时间码、logger名以及实际的消息
		s_CoreLogger = spdlog::stdout_color_mt("JEngine");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}