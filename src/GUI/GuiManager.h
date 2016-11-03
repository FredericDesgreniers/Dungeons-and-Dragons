#pragma once
#include <iostream>
#include <SDL/SDL.h>

class Screen;

class GuiManager
{
public:
	GuiManager();
	/**
	 * Render the gui on the screen
	 */
	void renderScreen();

	/**
	 * Run tick for the gui / screen
	 */
	void runTick();

	/**
	 * Called on key press, transfers it to screen
	 */
	void keyPressed(SDL_Keycode code);

	/**
	 * Called when screen is clicked
	 */
	void clickScreen(int x, int y);

	/**
	 * Set debug display
	 */
	void setDebug(bool d);

	/**
	 * toggle debug display
	 */
	void toggleDebug();

	/**
	 * Set the screen, return pointer to old screen
	 */
	Screen* setScreen(Screen* screen);
	
private:
	Screen* currentScreen;
	bool debug;
	
};
