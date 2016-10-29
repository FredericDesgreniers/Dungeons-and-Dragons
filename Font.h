#pragma once
#include <SDL/SDL_ttf.h>
#include <string>

class Font
{
public:
	Font(std::string name);

	TTF_Font* get(int index);
private:
	TTF_Font *fonts[100];
	std::string name;
};
