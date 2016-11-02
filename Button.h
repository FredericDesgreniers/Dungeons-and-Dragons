#pragma once
#include <string>
#include "Style.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "Font.h"
#include "Label.h"

class Button : public Label
{
public:
	Button(std::string text,Font* font, int x, int y, int width, int height);

	void adjustButtonDimensions()
	{
		Label::adjustDimensions();
	}




};
