#pragma once
#include "CoreExports.h"
#include <string>

class CORE_API IObserver {
public:
    enum EventTypes
    {
        SavePart,
        OpenPart,
        ClosePart,
        CreatePart
    };

    virtual ~IObserver() {};
    virtual void Update(const std::string& message_from_subject) = 0;
};