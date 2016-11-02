#pragma once
#include "Screen.h"
#include <iostream>

class Screen;

class GuiManager
{
public:
	GuiManager();
	void renderScreen();
	void runTick();

	void keyPressed(SDL_Keycode code);

	void clickScreen(int x, int y);

	void setDebug(bool d)
	{
		debug = d;
	}

	void toggleDebug()
	{
		debug = !debug;
		std::cout << "Debug is now " << (debug ? "on" : "off") << std::endl;
	}

	/**
	 * Set the screen, return pointer to old screen
	 */
	Screen* setScreen(Screen* screen);
	
private:
	Screen* currentScreen;
	bool debug;
	
};
