#pragma once
#include "CoreExports.h"
#include <windows.h> 

CORE_API HMODULE  CoreLoadLibrary(const char* libraryName);
CORE_API void UnloadLibrary(HMODULE  handle);
CORE_API HMODULE CoreKeepLoadedLibraryPersistant(const char* libraryName);
