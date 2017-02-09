#pragma once
#include "Observer.h"
#include <memory>
class EventObserver :
	public Observer
{
public:
	EventObserver(Broadcaster *broadcaster);
	~EventObserver();

	virtual void sendEvent(int sentEvent) = 0;
};

