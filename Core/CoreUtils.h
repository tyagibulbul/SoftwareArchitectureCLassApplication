#pragma once

#include "CoreExports.h"
#include <string>

CORE_API std::string BasePath();
CORE_API std::string RemoveLastDirectory(const std::string& dirPath);
CORE_API std::string GetFileName(const std::string& s);
CORE_API std::string GetBaseName(const std::string& s);
