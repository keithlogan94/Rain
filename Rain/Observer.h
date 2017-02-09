#pragma once
#include "Broadcaster.h"
#include <memory>
class Observer
{
	Broadcaster *broadcaster;
	int posInBroadcaster = 0;
protected:
	inline void stopObserving() { broadcaster->stopObserving(posInBroadcaster); }
public:
	Observer(Broadcaster *broadcaster);
	virtual ~Observer();
	void setPosition(const int pos);
};

