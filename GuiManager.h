#pragma once
#include "Screen.h"
#include <vector>
#include "Button.h"

class GuiManager
{
public:
	GuiManager();
	void renderScreen();
	void runTick();

	void clickScreen(int x, int y);

	/**
	 * Set the screen, return pointer to old screen
	 */
	Screen* setScreen(Screen* screen);
	
private:
	Screen* currentScreen;
	
};
