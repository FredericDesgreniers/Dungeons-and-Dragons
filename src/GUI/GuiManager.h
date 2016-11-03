#pragma once
#include <iostream>
#include <SDL/SDL.h>

class Screen;

class GuiManager
{
public:
	GuiManager();
	void renderScreen();
	void runTick();

	void keyPressed(SDL_Keycode code);

	void clickScreen(int x, int y);

	void setDebug(bool d);

	void toggleDebug();

	/**
	 * Set the screen, return pointer to old screen
	 */
	Screen* setScreen(Screen* screen);
	
private:
	Screen* currentScreen;
	bool debug;
	
};
