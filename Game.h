#pragma once
#include "GuiManager.h"

class Game
{
public:
	Game();
	bool ini();
	bool run();
	bool exit();

private:
	GuiManager gui_manager;
};
