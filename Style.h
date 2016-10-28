#pragma once
#include <SDL/SDL.h>

class Style
{
public:
	Style(SDL_Rect dimensions);
	Style(int x, int y, int w, int h);

	void drawDefaultStyle(bool);
	void drawBackground(bool);
	void drawBorder(bool);


	void setBackgroundColor(int r, int g, int b, int a)
	{
		backgroundColor.r = r;
		backgroundColor.g = g;
		backgroundColor.b = b;
		backgroundColor.a = a;
	}
	void setBorderColor(int r, int g, int b, int a)
	{
		borderColor.r = r;
		borderColor.g = g;
		borderColor.b = b;
		borderColor.a = a;
	}
	void setBackgroundColor_hover(int r, int g, int b, int a)
	{
		backgroundColor_hover.r = r;
		backgroundColor_hover.g = g;
		backgroundColor_hover.b = b;
		backgroundColor_hover.a = a;
	}
	void setBorderColor_hover(int r, int g, int b, int a)
	{
		borderColor_hover.r = r;
		borderColor_hover.g = g;
		borderColor_hover.b = b;
		borderColor_hover.a = a;
	}
	void setBorderSize(int borderSize)
	{
		this->borderSize = borderSize;
	}
	void setBorderSize_hover(int borderSize)
	{
		this->borderSize_hover = borderSize;
	}

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
