#pragma once
#include "Component.h"
#include "Style.h"

class TextField: public Style
{
public:
	TextField(std::string text, int x, int y, int width, int height);

	void render() override;
	void keyPressed(SDL_Keycode) override;

	std::string getText()
	{
		return text;
	}

private:
	std::string text;

	std::vector<std::string> whiteList;
};
