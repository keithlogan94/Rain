#pragma once
#include "Observer.h"
class HoverObserver :
	public Observer
{
public:
	HoverObserver(Broadcaster *broadcaster);
	~HoverObserver();

	virtual void hover(const int mouseX, const int mouseY) = 0;
};

