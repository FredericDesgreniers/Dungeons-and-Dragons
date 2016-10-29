#pragma once
#include <string>
#include "Style.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

class Button : public Style
{
public:
	Button(std::string text,TTF_Font* font, int x, int y, int width, int height);



	/**
	 * Render button on screen
	 */
	void render();


	/**
	 * Set the font color for the button text. 
	 * Calling this will destroy and create a texture.
	 * Do not call this often
	 */
	void setFontColor(int r, int g, int b, int a) override;

	void adjustButtonDimensions()
	{
		TTF_SizeText(font, text.c_str(),  &dimensions.w, &dimensions.h);
	}

	~Button();

private:
	std::string text;
	TTF_Font* font;
	SDL_Texture* texture;
};
