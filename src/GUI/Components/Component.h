#pragma once
#include <SDL/SDL.h>
#include <vector>
#include <functional>

/**
 * Used to display elements on the screen such as buttons / panes / text
 * 
 */
class Component
{
public:
	Component(int width, int height);
	Component(int positionX, int positionY, int width, int height);

	/**
	 * get Y position of component on the screen
	 */
	int getPositionX() { return dimensions.x; }

	/**
	 * Get X position of component on screen
	 */
	int getPositionY() { return dimensions.y; }

	/**
	 * Get width of component
	 */
	int getWidth() { return dimensions.w; }

	/**
	 * Get height of component
	 */
	int getHeight() { return dimensions.h; }

	/**
	 * Set X position of component on screen
	 */
	void setPositionX(int x) { dimensions.x = x; }
	/**
	 * Set Y position of component on screen
	 */
	void setPositionY(int y) { dimensions.y = y; }

	/**
	 * Set width of component
	 */
	void setWidth(int width) { dimensions.w = width; }
	/**
	 * Set height of component
	 */
	void setHeight(int height) { dimensions.h = height; }

	/**
	 * Set visibility of component
	 */
	void setVisible(bool visible)
	{
		this->visible = visible;
	}

	/**
	 * returns if component is visible
	 */
	bool isVisible()
	{
		return visible;
	}

	/**
	 * Scale the components dimensions to *s
	 */
	void scale(int s)
	{
		dimensions.h *= s;
		dimensions.w *= s;
	}

	/**
	 * Add function to callback list. Called when component is clicked. positions are relative
	 */
	void addOnClick_callback(std::function<void(Component*, int, int)> func);

	void clearCallbacks();

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

	/**
	 * Destructor
	 */
	virtual ~Component();

	bool isInFocus();
	/**
	 * Returns if component is in focus  
	 **/
	void setInFocus(bool focus);

	/**
	 * Called when a key is pressed on the screen
	 */
	virtual void keyPressed(SDL_Keycode keycode);

protected:
	SDL_Rect dimensions;
	std::vector<std::function<void(Component*, int , int)>> onClick_callbacks;

	bool visible = true;

	bool inFocus;
};
