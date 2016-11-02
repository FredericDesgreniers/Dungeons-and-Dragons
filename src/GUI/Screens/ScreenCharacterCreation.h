#pragma once
#include "Screen.h"

class ScreenCharacterCreation : public Screen
{
public:
	ScreenCharacterCreation(Game* game);

	

	void render() override;

private:
	std::string strength, constitution, dexterity, intelligence, wisdom, charisma;
};
