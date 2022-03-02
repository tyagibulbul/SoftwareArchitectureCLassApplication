#pragma once
#include "CoreExports.h"
#include <windows.h> 

CORE_API HINSTANCE LoadLibrary(const char* libraryName);
CORE_API void UnloadLibrary(HINSTANCE handle);

