#pragma once

#include "UILIbraryExports.h"
#include <string>


class PartFile;

UILIBRARY_API PartFile* OpenPartUI(std::string);

UILIBRARY_API PartFile* MakePartUI(std::string);

UILIBRARY_API void SavePartUI(PartFile* partFile);


