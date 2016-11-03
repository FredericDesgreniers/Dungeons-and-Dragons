#include "Button.h"
#include <SDL/SDL.h>


Button::Button(std::string text, Font* font, int x, int y,int width, int height):Label(text,font, x, y, width, height)
{

	setFontColor(255, 255, 255, 255);

	setBackgroundColor_both(255, 255, 255, 0);

	setFontUnderlineColor_hover(255, 255, 255, 255);
	setFontUnderline_hover(1);

	setPadding(10);

}

Button* Button::adjustButtonDimensions()
{
	Label::adjustDimensions();
	return this;
}


