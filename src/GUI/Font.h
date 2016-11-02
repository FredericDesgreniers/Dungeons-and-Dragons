#pragma once
#include <SDL/SDL_ttf.h>
#include <string>
#include <map>

class Font
{
public:
	Font(std::string name);

	TTF_Font* get(int index);
private:
	std::map<int,TTF_Font*> fonts;
	std::string name;
};
