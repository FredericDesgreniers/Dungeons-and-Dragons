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

	void setDebug(bool d)
	{
		debug = d;
	}

	void toggleDebug()
	{
		debug = !debug;
	}

	/**
	 * Set the screen, return pointer to old screen
	 */
	Screen* setScreen(Screen* screen);
	
private:
	Screen* currentScreen;
	bool debug;
	
};
