#pragma once

#include "JavaLoaderExports.h"
#include <string>

extern JAVALOADER_API void CreateJVM();

extern JAVALOADER_API void RunJavaProgram1(std::string msg);
extern JAVALOADER_API void RunJavaProgram2(std::string classFile);

extern JAVALOADER_API void DestroyJVM();

