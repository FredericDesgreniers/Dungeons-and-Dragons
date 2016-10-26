#pragma once
#include <SDL/SDL.h>


class Screen
{
public:
	Screen();
	void render();
	void tick();

	~Screen();
private:
	SDL_Texture* titleText;
};
