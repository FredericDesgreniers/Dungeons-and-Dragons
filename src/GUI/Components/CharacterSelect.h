#pragma once
#include "Style.h"
#include "Pane.h"

class CharacterSelect:public Pane
{
public:
	CharacterSelect(int x, int y, int width, int height);

	void addOnCharacterClick_callback(std::function<void(std::string name)> func);
private:
	std::vector<std::function<void(std::string name)>> onCharacterClick_callback;
};
