#include "Log.h"

namespace JKNL {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() 
	{
		std::vector<spdlog::sink_ptr> logSinks;
		logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());

		logSinks[0]->set_pattern("%^[%T] [%n]: [%v] %@%$");

		
		s_CoreLogger = std::make_shared<spdlog::logger>("JKNL", begin(logSinks), end(logSinks));
		s_CoreLogger = spdlog::stdout_color_mt("JKNL");
		s_CoreLogger->set_level(spdlog::level::trace);
		s_CoreLogger->flush_on(spdlog::level::trace);

		s_ClientLogger = std::make_shared<spdlog::logger>("APP", begin(logSinks), end(logSinks));
		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);
		s_ClientLogger->flush_on(spdlog::level::trace);
		
	}

}