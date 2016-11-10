#pragma once
#include <string>
#include "Style.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "../Font.h"

/**
 * Label is used to display static text on the screen
 */
class Label : public Style
{
public:
	/**
	 * Label constructor given text, font, x, y, width, height
	 */
	Label(std::string text, Font* font, int x, int y, int width, int height);



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

	/*
	 * Set the font size for the label
	 */
	Label* setFontSize(int size) override;

	/**
	 * relaod font texture
	 */
	void reloadTexture();

	/**
	 * Set label text. 
	 * Will reload texture
	 */
	void setText(std::string text);
	/**
	 * returns the label text
	 */
	std::string getText();

	/**
	 * adjust width and height to match fonts size and text width
	 */
	Label* adjustDimensions();

	~Label();

private:
	std::string text;
	Font* font;
	SDL_Texture* texture;
};
