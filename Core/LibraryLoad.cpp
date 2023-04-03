#include "LibraryLoad.h"
#include <iostream>
#include <windows.h> 
#include <stdio.h> 


typedef int(__cdecl* MYPROC)();

std::wstring s2ws(const std::string& str)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

HMODULE  CoreLoadLibrary(const char* libraryName)
{
    HMODULE hinstLib;
   
    std::wstring temp = s2ws(libraryName);

    // Get a handle to the DLL module.
    LPCWSTR libraryNameForFunc = temp.c_str();
    hinstLib = LoadLibrary(libraryNameForFunc);

    return hinstLib;
}

HMODULE CoreKeepLoadedLibraryPersistant(const char* libraryName)
{
    HMODULE  hinstLib;

    std::string temp = std::string(libraryName);

    BOOL b = GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_PIN, temp.c_str(), &hinstLib);

    return hinstLib;

}


void UnloadLibrary(HMODULE  hinstLib)
{
    BOOL fFreeResult = FALSE;
    fFreeResult = FreeLibrary(hinstLib);

}
