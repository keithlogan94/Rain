#pragma once
#include "Observer.h"
class ClickObserver :
	public Observer
{
public:
	ClickObserver(Broadcaster *broadcaster);
	~ClickObserver(); 

	virtual void leftClick(const int x, const int y) = 0;
	virtual void rightClick(const int x, const int y) = 0;
};

