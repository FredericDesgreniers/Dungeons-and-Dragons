#pragma once
#include <SDL/SDL.h>
#include <vector>

#include "../Components/Component.h"

#include "../../Game.h"
#include "../Components/Button.h"

class Game;

class Screen
{
public:
	Screen(Game* game);
	virtual void render();
	virtual void renderDebug();

	virtual void tick();

	virtual void reInitialize();

	virtual void keyPressed(SDL_Keycode keycode);

	
	void click(int x, int y);


	/*
	 * Add component to component list. 
	 */
	void addComponent(Component* comp)
	{
		components.push_back(comp);
	}

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
