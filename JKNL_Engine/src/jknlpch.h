#pragma once

#include <string>
#include <functional>
#include <sstream>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <utility>
#include <cstring>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "JKNL/core.h"
#include "JKNL/Log.h"

#ifdef JKNL_PLATFORM_WINDOWS
#include <Windows.h>
#endif

#define JKNL_CORE_ASSERT(x,...) { if(!(x)) { JKNL_CORE_ERROR("Assertion Failed : {0}",__VA_ARGS__); __debugbreak();}}
#define JKNL_CLIENT_ASSERT(x,...) { if(!(x)) { JKNL_CLIENT_ERROR("Assertion Failed : {0}",__VA_ARGS__); __debugbreak();}}