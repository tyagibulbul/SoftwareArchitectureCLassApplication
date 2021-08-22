#pragma once
#include "Core.h"
#include <string>
#include "IObserver.h"

class CORE_API ISubject {
public:
    virtual ~ISubject() {};
    virtual void Attach(IObserver* observer) = 0;
    virtual void Detach(IObserver* observer) = 0;
    virtual void Notify() = 0;
    virtual void Notify(IObserver::EventTypes eventType) = 0;
};