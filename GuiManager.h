#pragma once
#include "Screen.h"

class GuiManager
{
public:
	GuiManager();
	void renderScreen();
	void runTick();

	/**
	 * Set the screen, return pointer to old screen
	 */
	Screen* setScreen(Screen* screen);
	
private:
	Screen* currentScreen;
};
