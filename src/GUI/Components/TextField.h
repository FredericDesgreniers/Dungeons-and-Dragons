#pragma once
#include "Component.h"
#include "Style.h"
/**
 * Textfield is used for text input
 */
class TextField: public Style
{
public:
	TextField(std::string text, int x, int y, int width, int height);

	void render() override;
	void keyPressed(SDL_Keycode) override;
	void tick() override;

	/**
	 * returns current textfield text
	 */
	std::string getText();

	void setMaxLength(int length);
	int getMaxLength();

private:
	std::string text;
	
	Uint32 timeOfLastErase;

	int maxLength;

	std::vector<std::string> whiteList;
};
