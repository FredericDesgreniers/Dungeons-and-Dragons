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

	virtual void onButtonClicked(Button* b);

	void addButton(Button* b)
	{
		buttons.push_back(b);
	}

	~Screen();
protected:
	Game* game;
private:
	SDL_Texture* titleText;
	std::vector<Button*> buttons;
};
