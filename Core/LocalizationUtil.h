#pragma once

#include "CoreExports.h"
#include <string>



/// <summary>
/// 
/// </summary>
/// <param name="msg"></param>
/// <param name="ctx"></param>
/// <returns></returns>
CORE_API std::string Localize(const std::string& ctx, const std::string& msg);


/// <summary>
/// 
/// </summary>
/// <param name="msgSing"></param>
/// <param name="msgPlural"></param>
/// <param name="count"></param>
/// <returns></returns>
CORE_API std::string Localize(const std::string& msgSing, const std::string& msgPlural, int count);



