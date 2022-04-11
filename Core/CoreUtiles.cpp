#include "CoreUtils.h"

#include <windows.h>

#include <iostream>

static bool determinedBasePath = false;
static std::string basePath;

// From  -https://stackoverflow.com/questions/4430780/how-can-i-extract-the-file-name-and-extension-from-a-path-in-c
std::string GetFileName(const std::string& s) {
    char sep = '/';
#ifdef _WIN32
    sep = '\\';
#endif
    size_t i = s.rfind(sep, s.length());
    if (i != std::string::npos)
    {
        std::string filename = s.substr(i + 1, s.length() - i);
        size_t lastindex = filename.find_last_of(".");
        std::string rawname = filename.substr(0, lastindex);
        return(rawname);
    }

    return("");
}

std::string GetBaseName(const std::string& s)
{
    size_t pos = s.rfind(".");

    std::string retVal = s.substr(0, pos);

    return retVal;
}


std::string BasePath() {
    if (!determinedBasePath)
    {
        TCHAR buffer[MAX_PATH] = { 0 };
        GetModuleFileName(NULL, buffer, MAX_PATH);
        std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
        std::wstring wStr = std::wstring(buffer).substr(0, pos);

        std::string tmp = std::string(wStr.begin(), wStr.end());

        std::string tmp1 = RemoveLastDirectory(tmp);
        basePath = RemoveLastDirectory(tmp1);
    }

    return basePath;
}

std::string RemoveLastDirectory(const std::string& dirPath)
{
    auto pos = dirPath.find_last_of("\\");
    std::string retVal = dirPath.substr(0, pos);

    return retVal;
}
