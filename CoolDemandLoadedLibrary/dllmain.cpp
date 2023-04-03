// dllmain.cpp : Defines the entry point for the DLL application.
#include "framework.h"

#include "..\Core\LibraryLoad.h"
#include <iostream>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {

        case DLL_PROCESS_ATTACH:
            std::cout << "COOLDEMANDLOADEDLIBRARY.dll DllMain, DLL_PROCESS_ATTACH\n" << std::endl;
            break;
        case DLL_THREAD_ATTACH:
            std::cout << "COOLDEMANDLOADEDLIBRARY.dll DllMain, DLL_THREAD_ATTACH\n" << std::endl;
            break;
        case DLL_THREAD_DETACH:
            std::cout << "COOLDEMANDLOADEDLIBRARY.dll DllMain, DLL_THREAD_DETACH\n" << std::endl;
            break;
        case DLL_PROCESS_DETACH:
            std::cout << "COOLDEMANDLOADEDLIBRARY.dll DllMain, DLL_PROCESS_DETACH\n" << std::endl;
            break;


    }
    return TRUE;
}

