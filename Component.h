#pragma once
#include <SDL/SDL.h>

class Component
{
public:
	Component(int width, int height);
	Component(int positionX, int positionY, int width, int height);

	int getPositionX() { return dimensions.x; }
	int getPosition() { return dimensions.y; }
	int getWidth() { return dimensions.w; }
	int getHeight() { return dimensions.h; }

	void setPositionX(int x) { dimensions.x = x; }
	void setPositionY(int y) { dimensions.y = y; }
	void setWidth(int width) { dimensions.w = width; }
	void setHeight(int height) { dimensions.h = height; }

protected:
	SDL_Rect dimensions;
};
