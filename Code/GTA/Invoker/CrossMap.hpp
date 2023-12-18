#pragma once
#include "../../Common.hpp"

namespace Base
{
    constexpr auto g_NativeCount = 6494;
    using CrossMap = std::array<std::pair<rage::scrNativeHash, rage::scrNativeHash>, g_NativeCount>;
    extern CrossMap g_CrossMap;
}