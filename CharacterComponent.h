#pragma once
#include "Style.h"
#include "character.h"


class CharacterComponent:public Style
{
public:
	CharacterComponent(Character* character, int x, int y, int width, int height);

	void render() override;


private:
	Character* character;
	
	void drawStat(int x, int y, std::string name, int level);
};
