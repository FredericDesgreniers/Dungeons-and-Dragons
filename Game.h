#pragma once
#include "GuiManager.h"

class Game
{
public:
	Game();
	/**
	 * Initilize game.
	 * Only call one at start
	 */
	bool ini();
	/**
	 * Run game on a loop
	 */
	bool run();
	/**
	 * Exit game
	 */
	bool exit();

private:
	GuiManager gui_manager;
};
