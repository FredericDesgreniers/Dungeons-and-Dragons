#pragma once
#include "Screen.h"

class ScreenTitle : public Screen
{
public:
	ScreenTitle(Game* game);

	void render() override;
	void tick() override;
private:
	long ticksSinceStart;
	Button* button;
};
