#pragma once
#include <string>
#include "Style.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "Label.h"

class Font;
/*
 * Button class is the same as a label but with a default style that implies it's a button. 
 * Same funcitonality as a button
 */
class Button : public Label
{
public:
	Button(std::string text,Font* font, int x, int y, int width, int height);

	Button* adjustButtonDimensions();

	friend void copySize(Button &copyFrom, Button &copyTo)
	{
		copyTo.setWidth(copyFrom.getWidth());
		copyTo.setHeight(copyFrom.getHeight());
	}




};
