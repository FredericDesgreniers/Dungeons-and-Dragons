#include "TextField.h"

#include <ctime>
#include <locale>
#include "../../Renderer.h"


TextField::TextField(std::string text, int x, int y, int width, int height):Style(x,y,width,height), text(text)
{
	for (char c = 'A'; c <= 'Z'; c++)
	{
		whiteList.push_back(std::string(1,c));
	}


	this->setBackgroundColor_both(100, 100, 100, 255);
	this->setBorderColor_both(155, 155, 155, 255);
	this->setBorderSize(1);
	this->setFontColor(255, 255, 255, 255);
}

void TextField::keyPressed(SDL_Keycode keycode)
{
	if (!inFocus)
		return;
	switch(keycode){
	case(SDLK_BACKSPACE):
	{
		if (text.size() > 0) {
			text = text.substr(0, text.size() - 1);
			timeOfLastErase = SDL_GetTicks();
		}
		return;
	}
	case(SDLK_SPACE):
		{
			text += " ";
			return;

		}
	}
	bool good = false;
	std::string keyName(SDL_GetKeyName(keycode));
	for(std::string str:whiteList)
	{
		if (str == keyName){
			good = true;
			break;
		}
	}
	if(good)
	{
		const Uint8 *state = SDL_GetKeyboardState(NULL);
		if (!state[SDL_SCANCODE_LSHIFT]) {
			keyName = tolower(keyName[0]);
		}
		text += keyName;
	}
		
}
void TextField::tick()
{
	if(SDL_GetKeyboardState(NULL)[SDL_SCANCODE_BACKSPACE])
	{
		if(SDL_GetTicks() - timeOfLastErase > 200)
		{
			text = text.substr(0, text.size() - 1);
			timeOfLastErase = SDL_GetTicks();
		}
	}
}

void TextField::render()
{
	Style::render();
	drawDefaultStyle();


	if(text.size()>0)
		Renderer::drawString(text, Renderer::FONT_ROBOTO.get(fontSize), getPositionX(), getPositionY(), 1, fontColor);
	if(inFocus && SDL_GetTicks()%1500 > 750)
	{
		
		int width, height;
		TTF_SizeText(Renderer::FONT_ROBOTO.get(fontSize), text.c_str(), &width, &height);
		Renderer::drawString("|", Renderer::FONT_ROBOTO.get(fontSize), getPositionX()+width+1, getPositionY(), 1, { fontColor });
	}
}

