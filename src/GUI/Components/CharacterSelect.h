#pragma once
#include "Style.h"
#include "Pane.h"

/**
 * Pane used to select characters from the characters folder
 */
class CharacterSelect:public Pane
{
public:
	/**
	 * Constructor to create Pane using x,y,width,height
	 */
	CharacterSelect(int x, int y, int width, int height);
	/**
	 * Add a callback for when a character it clicked
	 */
	void addOnCharacterClick_callback(std::function<void(std::string name)> func);
private:
	std::vector<std::function<void(std::string name)>> onCharacterClick_callback;
};
