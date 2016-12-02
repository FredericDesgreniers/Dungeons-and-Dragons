#pragma once
#include "Component.h"
#include "Style.h"
/**
 * Textfield is used for text input
 */
class TextField: public Style
{
public:
	/**
	 * Constructor given text, x,y,width and height
	 */
	TextField(std::string text, int x, int y, int width, int height);
	/**
	 * Override render method
	 */
	void render() override;
	/**
	 * Override keypressed method
	 */
	void keyPressed(SDL_Keycode) override;
	/**
	 * override tick method
	 */
	void tick() override;

	/**
	 * returns current textfield text
	 */
	std::string getText();
	/**
	 * Set max textfield length
	 */
	void setMaxLength(int length);
	/**
	 * Set text int extfield
	 */
	void setText(std::string text);
	/**
	 * Get max text length
	 */
	int getMaxLength();

private:
	/**
	 * Text in textfield
	 */
	std::string text;
	/**
	 * Time since last erase, so erase is not too fast
	 */
	Uint32 timeOfLastErase;
	/**
	 * mas field length
	 */
	int maxLength;
	/**
	 * list of allowed chars
	 */
	std::vector<std::string> whiteList;
};
