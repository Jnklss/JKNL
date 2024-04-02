#pragma once

#ifdef JKNL_PLATFORM_WINDOWS
	#ifdef JKNL_BUILD_DLL
		#define JKNL_API __declspec(dllexport)
	#else
		#define JKNL_API __declspec(dllimport)
	#endif // JKNL_BUILD_DLL
#else
	#error only support on Windows
#endif // HZ_PLATFORM_WINDOWS
