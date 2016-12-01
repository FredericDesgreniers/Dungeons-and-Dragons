#pragma once
#include "GUI/GuiManager.h"

class GuiManager;

/**
 * Class used for the main game flow. 
 */
class Game
{
public:
	/**
	 * Default constructor
	 */
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

	/**
	 *	Get GUI manager instance
	 */
	GuiManager* getGuiManager();

	

	static Game* getInstance();

private:
	GuiManager* gui_manager;

	static Game* instance;
};
