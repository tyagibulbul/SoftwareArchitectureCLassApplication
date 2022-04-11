#ifdef CLRAUTOMATIONLIBRARY_EXPORTS
#define CLRAUTOMATIONLIBRARY_API __declspec(dllexport)
#else
#define CLRAUTOMATIONLIBRARY_API __declspec(dllimport)
#endif


extern "C" CLRAUTOMATIONLIBRARY_API void Part_Save(int guid);


