#pragma once
#include "Screen.h"

class ScreenMain : public Screen
{
public:
	ScreenMain(Game* game);

	void render() override;
};
