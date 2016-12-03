#pragma once
#include "GUI/GuiManager.h"
//#define TEST
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
	 * Set up cpp unit tests
	 */
	bool doTests();
	/**
	 *	Get GUI manager instance
	 */
	GuiManager* getGuiManager();

	
	//Singleton game instance
	static Game* getInstance();

private:
	/**
	 * Gui amnager for this game instance
	 */
	GuiManager* gui_manager;
	/**
	 * Current game instance
	 */
	static Game* instance;
};
