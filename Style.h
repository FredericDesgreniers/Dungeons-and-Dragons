#pragma once
#include <SDL/SDL.h>

class Style
{
public:
	Style(SDL_Rect dimensions);
	Style(int x, int y, int w, int h);
	/**
	 * Draw default style:
	 *	-background
	 *	-border
	 */
	void drawDefaultStyle(bool hover);

	/**
	 * Draw background using backgroundColor]
	 */
	void drawBackground(bool hover);

	/**
	 * draw border using backgroundBorder and bvordersize
	 */
	void drawBorder(bool hover);

	/**
	 * Set background color for element
	 */
	void setBackgroundColor(int r, int g, int b, int a)
	{
		backgroundColor.r = r;
		backgroundColor.g = g;
		backgroundColor.b = b;
		backgroundColor.a = a;
	}

	/**
	 * Set border color for element
	 */
	void setBorderColor(int r, int g, int b, int a)
	{
		borderColor.r = r;
		borderColor.g = g;
		borderColor.b = b;
		borderColor.a = a;
	}
	/**
	 * Set background color for element when hovering
	 */
	void setBackgroundColor_hover(int r, int g, int b, int a)
	{
		backgroundColor_hover.r = r;
		backgroundColor_hover.g = g;
		backgroundColor_hover.b = b;
		backgroundColor_hover.a = a;
	}
	/**
	 * Set border color for element when hovering
	 */
	void setBorderColor_hover(int r, int g, int b, int a)
	{
		borderColor_hover.r = r;
		borderColor_hover.g = g;
		borderColor_hover.b = b;
		borderColor_hover.a = a;
	}

	/**
	 * set Border size
	 */
	void setBorderSize(int borderSize)
	{
		this->borderSize = borderSize;
	}
	/**
	 * Set border size when hovering
	 */
	void setBorderSize_hover(int borderSize)
	{
		this->borderSize_hover = borderSize;
	}

	/**
	 * Set color that should be displayed for text
	 */
	virtual void setFontColor(int r, int g, int b, int a)
	{
		fontColor.r = r;
		fontColor.g = g;
		fontColor.b = b;
		fontColor.a = a;
	}
protected:
	SDL_Color backgroundColor;
	SDL_Color backgroundColor_hover;
	SDL_Color borderColor;
	SDL_Color borderColor_hover;

	SDL_Color fontColor;

	int borderSize;
	int borderSize_hover;

	SDL_Rect dimensions;
};
