#pragma once

#ifdef JKNL_PLATFORM_WINDOWS
	#ifdef JKNL_BUILD_DLL
		#define JKNL_API __declspec(dllexport)
	#else
		#define JKNL_API __declspec(dllimport)
	#endif // JKNL_BUILD_DLL
#else
	#error only support on Windows
#endif // JKNL_PLATFORM_WINDOWS

//…Ë÷√Œª ˝
#define BIT(x) (1<<x)

#include <string>
#include <functional>
#include <sstream>
#include <iostream>