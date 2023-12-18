#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT _WIN32_WINNT_WIN7
#include <winsdkver.h>
#include <sdkddkver.h>
#include <windows.h>
#include <winternl.h>
#include <d3d11.h>

#include <cassert>
#include <cinttypes>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <deque>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <Psapi.h>
#include <limits>
#include <memory>
#include <mutex>
#include <optional>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <type_traits>
#include <unordered_map>
#include <vector>
#include <array>
#include <ShlObj_core.h>
#include <classes.hpp>

#define Kursed_WIDE_IMPL(str) L ## str
#define Kursed_WIDE(str) Kursed_WIDE_IMPL(str)

#define Kursed_STRINGIZE_IMPL(x) #x
#define Kursed_STRINGIZE(x) Kursed_STRINGIZE_IMPL(x)

#define Kursed_NAME "Kursed"
#define Kursed_VERSION "V 2.0.0.0.3"

namespace Base
{
	using namespace std::chrono_literals;
	namespace fs = std::filesystem;

	inline HMODULE g_Module{};
	inline std::atomic_bool g_Running = true;

	inline std::uint32_t g_SelectedPlayer{};
}

#include "Utility/Settings.hpp"
#include "Utility/Logger.hpp"
#include "Utility/Util.hpp"
#include "Game/Memory.hpp"
#include "Game/Game.hpp"
