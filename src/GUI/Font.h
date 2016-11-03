#pragma once
#include <SDL/SDL_ttf.h>
#include <string>
#include <map>

/**
 * used to managed fonts of various sizes
 */
class Font
{
public:
	/**
	 * Use with the name of a font placed int he resources folder
	 */
	Font(std::string name);

	/**
	 * Get the font for a certain size
	 */
	TTF_Font* get(int index);
private:
	std::map<int,TTF_Font*> fonts;
	std::string name;
};
