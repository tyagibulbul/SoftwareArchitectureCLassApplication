#pragma once

#include "PartOpsUIExports.h"
#include <string>


class PartFile;

PARTOPSUI_API PartFile* OpenPartUI(std::string);

PARTOPSUI_API PartFile* MakePartUI(std::string);

PARTOPSUI_API void SavePartUI(PartFile* partFile);


