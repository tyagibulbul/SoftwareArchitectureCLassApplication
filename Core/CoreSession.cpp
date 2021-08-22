#include "CoreSession.h"
#include "Observer.h"



CoreSession::CoreSession() : m_observerForSavePart(nullptr), m_observerForClosePart(nullptr), m_observerForOpenPart(nullptr)
{

}

CoreSession& CoreSession::GetInstance()
{
    static CoreSession instance;

    return instance;
}

void CoreSession::SetupDefaultObservers()
{
    m_observerForSavePart = new Observer(CoreSession::GetInstance(), Observer::SavePart);
    m_observerForClosePart = new Observer(CoreSession::GetInstance(), Observer::ClosePart);
    m_observerForOpenPart = new Observer(CoreSession::GetInstance(), Observer::OpenPart);

}


CoreSession::~CoreSession() {
    std::cout << "Goodbye, I was the CoreSession.\n";
}

/**
 * The subscription management methods.
 */
void CoreSession::Attach(IObserver* observer)  {
    list_observer_.push_back(observer);
}
void CoreSession::Detach(IObserver* observer)  {
    list_observer_.remove(observer);
}
void CoreSession::Notify()  {
    std::list<IObserver*>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end()) {
        (*iterator)->Update(message_);
        ++iterator;
    }
}

static std::string  GenerateMessageFromEvent(Observer::EventTypes eventType)
{
    std::string retVal;
    if (eventType == Observer::ClosePart)
    {
        retVal = "Close Part was Called";
    }
    else if (eventType == Observer::OpenPart)
    {
        retVal = "Open Part was Called";
    }
    else if (eventType == Observer::SavePart)
    {
        retVal = "Save Part was Called";
    }
    else if (eventType == Observer::CreatePart)
    {
        retVal = "Create Part was Called";
    }
    else
    {
        retVal = "Unknown Event Type";
    }

    return retVal;
}

void CoreSession::Notify(Observer::EventTypes eventType) 
{
    std::list<IObserver*>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end()) 
    {
        Observer* observer = dynamic_cast<Observer*>(*iterator);
        if (observer != nullptr && observer->UpdateOnEventType(eventType))
        {
            std::string generateMessage = GenerateMessageFromEvent(eventType);
            observer->Update(generateMessage);
        }
        ++iterator;
    }
}

void CoreSession::CreateMessage(Observer::EventTypes eventType)
{
    Notify(eventType);

}

void CoreSession::CreateMessage(std::string message ) {
    this->message_ = message;
    Notify();
}
void CoreSession::HowManyObserver() {
    std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
}


void CoreSession::ClearObservers()
{

}
