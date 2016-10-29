#pragma once
#include <SDL/SDL.h>
#include "Component.h"

class Style : public Component
{
public:
	Style(int width, int height);
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

	virtual void renderDebug() override;

	/**
	* Returns if x and y are within the bounds of the button
	*/
	bool isInBounds(int x, int y) override
	{
		return x >= dimensions.x - padding_left - borderSize
 		&& y >= dimensions.y - padding_top - borderSize
		&& x <= dimensions.x + dimensions.w  +padding_right + borderSize 
		&& y <= dimensions.y + dimensions.h  + padding_bottom + borderSize;
	}

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

	/*
	 * Set background color for both hover and non-hover
	 */
	void setBackgroundColor_both(int r, int g, int b, int a)
	{
		setBackgroundColor(r, g, b, a);
		setBackgroundColor_hover(r, g, b, a);
	}
	/**
	 * Set border color for both hover and non-hover
	 */
	void setBorderColor_both(int r, int g, int b, int a)
	{
		setBorderColor(r, g, b, a);
		setBorderColor_hover(r, g, b, a);
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
	 * Set padding
	 */
	void setPadding(int top, int right, int bottom, int left)
	{
		padding_top = top;
		padding_right = right;
		padding_bottom = bottom;
		padding_left = left;
	}

	/**
	 * Set padding
	 */
	void setPadding(int padding)
	{
		setPadding(padding, padding, padding, padding);
	}
	void setFontUnderline_both(int size)
	{
		setFontUnderline(size);
		setFontUnderline_hover(size);
	}
	void setFontUnderline(int size)
	{
		fontUnderline = size;
	}
	
	void setFontUnderline_hover(int size)
	{
		fontUnderline_hover = size;
	}
	void setFontUnderlineColor_both(int r, int g, int b, int a)
	{
		setFontUnderlineColor(r, g, b, a);
		setFontUnderlineColor_hover(r, g, b, a);
	}

	void setFontUnderlineColor(int r, int g, int b, int a)
	{
		fontUnderlineColor.r = r;
		fontUnderlineColor.g = g;
		fontUnderlineColor.b = b;
		fontUnderlineColor.a = a;
	}
	void setFontUnderlineColor_hover(int r, int g, int b, int a)
	{
		fontUnderlineColor_hover.r = r;
		fontUnderlineColor_hover.g = g;
		fontUnderlineColor_hover.b = b;
		fontUnderlineColor_hover.a = a;
	}
	/**
	 * Set color that should be displayed for text
	 */
	virtual void setFontColor(int r, int g, int b, int a);

	friend void copyStyle(Style &copyFrom, Style &copyTo)
	{
		copyTo.setFontColor(copyFrom.fontColor.r, copyFrom.fontColor.g, copyFrom.fontColor.b, copyFrom.fontColor.a);
		copyTo.backgroundColor = copyFrom.backgroundColor;
		copyTo.backgroundColor_hover = copyFrom.backgroundColor_hover;

		copyTo.borderSize = copyFrom.borderSize;
		copyTo.borderSize_hover = copyFrom.borderSize_hover;
		copyTo.borderColor = copyFrom.borderColor;
		copyTo.borderColor_hover = copyFrom.borderColor_hover;

		copyTo.fontUnderline = copyFrom.fontUnderline;
		copyTo.fontUnderline_hover = copyFrom.fontUnderline_hover;
		copyTo.fontUnderlineColor = copyFrom.fontUnderlineColor;
		copyTo.fontUnderlineColor_hover = copyFrom.fontUnderlineColor_hover;
		
		copyTo.padding_left = copyFrom.padding_left;
		copyTo.padding_right = copyFrom.padding_right;
		copyTo.padding_top = copyFrom.padding_top;
		copyTo.padding_bottom = copyFrom.padding_bottom;
	}

protected:
	SDL_Color backgroundColor;
	SDL_Color backgroundColor_hover;
	SDL_Color borderColor;
	SDL_Color borderColor_hover;

	SDL_Color fontColor;
	SDL_Color fontUnderlineColor;
	SDL_Color fontUnderlineColor_hover;


	int borderSize;
	int borderSize_hover;

	int padding_right, padding_left, padding_top, padding_bottom;

	int fontUnderline, fontUnderline_hover;

};
