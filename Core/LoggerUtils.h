#pragma once

#include "CoreExports.h"
#include <string>


// We define our own severity levels
enum severity_level
{
    normal,
    notification,
    warning,
    error,
    critical
};

/// <summary>
/// 
/// </summary>
/// <param name="msg"></param>
/// <param name="ctx"></param>
/// <returns></returns>
CORE_API void LogMessages(const std::string& ctx, severity_level level);


