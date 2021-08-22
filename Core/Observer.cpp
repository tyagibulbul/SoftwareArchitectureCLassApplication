#include "Observer.h"
#include <iostream>

int Observer::static_number_ = 0;

Observer::Observer(CoreSession& coreSession, EventTypes eventType) : coreSession_(coreSession) , m_eventType(eventType){
    this->coreSession_.Attach(this);
    std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
    this->number_ = Observer::static_number_;
}
Observer::~Observer() {
    std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}

void Observer::Update(const std::string& message_from_subject)  {
    message_from_subject_ = message_from_subject;
    PrintInfo();
}
void Observer::RemoveMeFromTheList() {
    coreSession_.Detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
}
void Observer::PrintInfo() {
    std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
}

bool Observer::UpdateOnEventType(EventTypes eventType)
{
    if (eventType == m_eventType)
    {
        return true;
    }
    else
    {
        return false;
    }
}
