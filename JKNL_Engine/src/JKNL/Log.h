#pragma once
#include <memory>

#include "core.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace JKNL {

	class JKNL_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

//CoreLog  
#define JKNL_CORE_ERROR(...)			::JKNL::Log::GetCoreLogger()->error(__VA_ARGS__)	//´íÎó
#define JKNL_CORE_WARN(...)				::JKNL::Log::GetCoreLogger()->warn(__VA_ARGS__)		//¾¯¸æ
#define JKNL_CORE_INFO(...)				::JKNL::Log::GetCoreLogger()->info(__VA_ARGS__)		//ÏûÏ¢
#define JKNL_CORE_TRACE(...)			::JKNL::Log::GetCoreLogger()->trace(__VA_ARGS__)	//¸ú×Ù
#define JKNL_CORE_CRITICAL(...)			::JKNL::Log::GetCoreLogger()->critical(__VA_ARGS__) //Î£¼±

//ClientLog  
#define JKNL_CLIENT_ERROR(...)			::JKNL::Log::GetClientLogger()->error(__VA_ARGS__)	    //´íÎó
#define JKNL_CLIENT_WARN(...)			::JKNL::Log::GetClientLogger()->warn(__VA_ARGS__)		//¾¯¸æ
#define JKNL_CLIENT_INFO(...)			::JKNL::Log::GetClientLogger()->info(__VA_ARGS__)		//ÏûÏ¢
#define JKNL_CLIENT_TRACE(...)			::JKNL::Log::GetClientLogger()->trace(__VA_ARGS__)		//¸ú×Ù
#define JKNL_CLIENT_CRITICAL(...)		::JKNL::Log::GetClientLogger()->critical(__VA_ARGS__)   //Î£¼±