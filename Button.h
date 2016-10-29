#pragma once
#include <string>
#include "Style.h"
#include <SDL/SDL.h>

class Button : public Style
{
public:
	Button(int id, std::string text, int x, int y, int width, int height);



	/**
	 * Render button on screen
	 */
	void render();

	int getId() { return id; }

	/**
	 * Set the font color for the button text. 
	 * Calling this will destroy and create a texture.
	 * Do not call this often
	 */
	void setFontColor(int r, int g, int b, int a) override;

	~Button();

private:
	int id;
	std::string text;

	SDL_Texture* texture;
};
