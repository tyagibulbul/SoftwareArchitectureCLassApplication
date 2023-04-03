// PatrickLocal.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "CoreUtils.h"
#include "LocalizationUtil.h"
#include "LocalizationUtilInternal.h"
#include <boost/locale.hpp>
#include <iostream>

using namespace boost::locale;

static generator* genPtr = nullptr;

static bool isInitialized = false;

static bool determinedBasePath = false;
static std::string basePath;

void LocalizeUtilsInit()
{

    // Specify location of dictionaries
    genPtr = new generator();

    // THe assumption is the directory where the de\LC_MESSAGES is located is at
    // boost_starting\translation\de\LC_MESSAGES
    // So to make this more portable I have taken out the hardcoded path
    std::string basePath = BasePath();
    genPtr->add_messages_path(basePath + "\\translation");
    genPtr->add_messages_domain("messages");

    std::locale::global((*genPtr)("de_DE.UTF - 8"));

    std::cout.imbue(std::locale());

    isInitialized = true;

}


std::string Localize(const std::string& msgSing, const std::string& msgPlural, int count)
{
    if (!isInitialized)
    {
        LocalizeUtilsInit();
    }

    std::string  retval = translate(msgSing, msgPlural, count);
    return retval;
}

std::string Localize(const std::string& ctx, const std::string& msg)
{

    if (!isInitialized)
    {
        LocalizeUtilsInit();
    }


    std::string  retval = translate(ctx, msg);
    return retval;
}
