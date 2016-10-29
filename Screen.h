#pragma once
#include <SDL/SDL.h>
#include <vector>
#include "Button.h"


class Game;

class Screen
{
public:
	Screen(Game* game);
	virtual void render();
	void tick();

	void click(int x, int y);



	void addComponent(Component* comp)
	{
		components.push_back(comp);
	}

	~Screen();
protected:
	Game* game;
private:
	SDL_Texture* titleText;
	std::vector<Component*> components;
};
