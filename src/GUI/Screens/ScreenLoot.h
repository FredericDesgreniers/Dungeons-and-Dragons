#pragma once
#include "Screen.h"
#include "../../ItemContainer.h"

class ScreenLoot:public Screen
{
public:
	ScreenLoot(Game* game, ItemContainer*  to, ItemContainer* from);
};
