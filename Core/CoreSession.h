#pragma once
#include "CoreExports.h"
#include "ISubject.h"
#include <list>
#include <iostream>

class Observer;

class CORE_API CoreSession : ISubject
{
	public:
        static CoreSession& GetInstance();

        CoreSession(CoreSession const&) = delete;
        void operator=(CoreSession const&) = delete;


        virtual ~CoreSession();

        /**
         * The subscription management methods.
         */
        void Attach(IObserver* observer) override;
        void Detach(IObserver* observer) override;
        void Notify() override;
        void Notify(IObserver::EventTypes eventType) override;

        void CreateMessage(IObserver::EventTypes eventType);
        void CreateMessage(std::string message = "Empty");
        void HowManyObserver();

        void ClearObservers();

        void SetupDefaultObservers();

private:
    std::list<IObserver*> list_observer_;
    std::string message_;
    CoreSession();
    Observer* m_observerForSavePart; 
    Observer* m_observerForClosePart;
    Observer* m_observerForOpenPart;

};

