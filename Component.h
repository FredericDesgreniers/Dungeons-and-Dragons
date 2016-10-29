#pragma once
#include <SDL/SDL.h>
#include <vector>
#include <functional>

class Component
{
public:
	Component(int width, int height);
	Component(int positionX, int positionY, int width, int height);

	int getPositionX() { return dimensions.x; }
	int getPositionY() { return dimensions.y; }
	int getWidth() { return dimensions.w; }
	int getHeight() { return dimensions.h; }

	void setPositionX(int x) { dimensions.x = x; }
	void setPositionY(int y) { dimensions.y = y; }
	void setWidth(int width) { dimensions.w = width; }
	void setHeight(int height) { dimensions.h = height; }

	void addOnClick_callback(std::function<void(Component*, int, int)> func)
	{
		onClick_callbacks.push_back(func);
	}

	virtual void render();
	virtual void tick();

	virtual void click(int x, int y)
	{
		for(std::function<void(Component*, int, int)> func : onClick_callbacks)
		{
			func(this, x, y);
		}
	}

	/**
	* Returns if x and y are within the bounds of the button
	*/
	virtual bool isInBounds(int x, int y)
	{
		return x >= dimensions.x && y >= dimensions.y && x <= dimensions.x + dimensions.w  && y <= dimensions.y + dimensions.h;
	}

protected:
	SDL_Rect dimensions;
	std::vector<std::function<void(Component*, int , int)>> onClick_callbacks;
};
