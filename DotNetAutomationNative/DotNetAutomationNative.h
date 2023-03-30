// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DOTNETAUTOMATIONNATIVE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DOTNETAUTOMATIONNATIVE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DOTNETAUTOMATIONNATIVE_EXPORTS
#define DOTNETAUTOMATIONNATIVE_API __declspec(dllexport)
#else
#define DOTNETAUTOMATIONNATIVE_API __declspec(dllimport)
#endif


extern "C" DOTNETAUTOMATIONNATIVE_API void  DotNet_automationapi_Session_InitializeSession(void);

extern "C" DOTNETAUTOMATIONNATIVE_API int DotNet_automationapi_Session_MakePart(char* partPath);

extern "C" DOTNETAUTOMATIONNATIVE_API void DotNet_automationapi_Part_Save(int guid);