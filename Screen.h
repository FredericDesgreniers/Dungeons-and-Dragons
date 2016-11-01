#pragma once
#include <SDL/SDL.h>
#include <vector>
#include "Button.h"
#include "Game.h"

class Game;

class Screen
{
public:
	Screen(Game* game);
	virtual void render();
	virtual void renderDebug();

	virtual void tick();

	void click(int x, int y);


	/*
	 * Add component to component list. 
	 */
	void addComponent(Component* comp)
	{
		components.push_back(comp);
	}



	~Screen();
protected:
	Game* game;
	Uint32 time;
private:
	std::vector<Component*> components;
	
};
