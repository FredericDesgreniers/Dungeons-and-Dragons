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

	void setVisible(bool visible)
	{
		this->visible = visible;
	}

	bool isVisible()
	{
		return visible;
	}

	void scale(int s)
	{
		dimensions.h *= s;
		dimensions.w *= s;
	}

	/**
	 * Add function to callback list. Called when component is clicked. positions are relative
	 */
	void addOnClick_callback(std::function<void(Component*, int, int)> func);
	virtual void render();
	virtual void renderDebug();
	
	virtual void tick();

	/**
	 * Component got clicked
	 */
	virtual void click(int x, int y);
	/**
	* Returns if x and y are within the bounds of the button
	*/
	virtual bool isInBounds(int x, int y);
	virtual ~Component();

	bool isInFocus();

	void setInFocus(bool focus);

	virtual void keyPressed(SDL_Keycode keycode);

protected:
	SDL_Rect dimensions;
	std::vector<std::function<void(Component*, int , int)>> onClick_callbacks;

	bool visible = true;

	bool inFocus;
};
