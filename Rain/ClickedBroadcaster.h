#pragma once
#include "Broadcaster.h"
#include <vector>
#include <algorithm>
class ClickBroadcaster :
	public Broadcaster
{
	int mouseX = 0, mouseY = 0;
	Uint32 mouseState = 0;
public:
	ClickBroadcaster();
	~ClickBroadcaster();

	void update();
};

