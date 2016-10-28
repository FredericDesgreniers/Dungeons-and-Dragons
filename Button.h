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
	bool isInBounds(int x, int y) { return x >= this->x && y >= this->y && x <= this->x + width && y <= this->y + height; }

	/**
	 * Render button on screen
	 */
	void render();

	int getX() { return x; }
	int getY() { return y; }

	int getWidth() { return width; }
	int getHeight() { return height; }
	
	int getId() { return id; }

	void setFontColor(int r, int g, int b, int a) override;

	~Button();

private:
	int id, x, y, width, height;
	std::string text;

	SDL_Texture* texture;
};
