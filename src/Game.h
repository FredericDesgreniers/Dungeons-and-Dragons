#pragma once
#include "GUI/GuiManager.h"

class GuiManager;


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

	GuiManager* getGuiManager()
	{
		return gui_manager;
	}

private:
	GuiManager* gui_manager;
};
