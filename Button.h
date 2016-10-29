#pragma once
#include <string>
#include "Style.h"
#include <SDL/SDL.h>

class Button : public Style
{
public:
	Button(int id, std::string text, int x, int y, int width, int height);

	/**
	 * Returns if x and y are within the bounds of the button
	 */
	bool isInBounds(int x, int y)
	{
		return x >= this->x-padding_left && y >= this->y-padding_top && x <= this->x + width+padding_left+padding_right && y <= this->y + height + padding_top+padding_bottom;
	}

	/**
	 * Render button on screen
	 */
	void render();

	int getX() { return x; }
	int getY() { return y; }

	int getWidth() { return width; }
	int getHeight() { return height; }
	
	int getId() { return id; }

	/**
	 * Set the font color for the button text. 
	 * Calling this will destroy and create a texture.
	 * Do not call this often
	 */
	void setFontColor(int r, int g, int b, int a) override;

	~Button();

private:
	int id, x, y, width, height;
	std::string text;

	SDL_Texture* texture;
};
