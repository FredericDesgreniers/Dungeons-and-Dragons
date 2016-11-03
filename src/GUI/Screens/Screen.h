#pragma once
#include <SDL/SDL.h>
#include <vector>

#include "../Components/Component.h"

#include "../../Game.h"
#include "../Components/Button.h"

class Game;
/**
 * Screen is used by guimanager to display gui on screen
 */
class Screen
{
public:
	/**
	 * Create a screen with a game pointer
	 */
	Screen(Game* game);
	/**
	 * Called each render tick to render ui elements
	 */
	virtual void render();
	/**
	 * Called when debug is true to render debug information
	 */
	virtual void renderDebug();

	/**
	 * Called every tick, used for logic. Called before rendering
	 */
	virtual void tick();

	/**
	 * Called when a screen is went back too using the back button for example
	 */
	virtual void reInitialize();

	/**
	 * Called when a key press is detected
	 */
	virtual void keyPressed(SDL_Keycode keycode);

	/**
	 * Called when the user clicks on the screen
	 */
	void click(int x, int y);


	/*
	 * Add component to component list. 
	 */
	void addComponent(Component* comp);

	/**
	 *Set the back button to point to a previous screen
	 */
	void setBackButton(Screen* screen);

	~Screen();
protected:
	Game* game;
	Uint32 time;
	Button* backButton;
private:
	std::vector<Component*> components;
	Screen* backScreen;
	
};
