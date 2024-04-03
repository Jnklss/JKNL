#include "Log.h"

namespace JKNL {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() 
	{
		//               color [时间戳] [Logger's name]: [文本]  Source file and line 结束color
		spdlog::set_pattern("%^[%T] [%n]: [%v] %@%$");
		s_CoreLogger = spdlog::stdout_color_mt("JKNL");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}