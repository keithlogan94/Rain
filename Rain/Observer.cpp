#include "Observer.h"



Observer::Observer(Broadcaster *broadcaster)
{
	this->broadcaster = broadcaster;
	broadcaster->addObserver(this);
}


Observer::~Observer()
{
}

void Observer::setPosition(const int pos)
{
	this->posInBroadcaster = pos;
}
