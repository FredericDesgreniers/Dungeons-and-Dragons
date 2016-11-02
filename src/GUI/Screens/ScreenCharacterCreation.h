#pragma once
#include "Screen.h"
#include <sstream>

class ScreenCharacterCreation : public Screen
{

private:
	std::string strength, constitution, dexterity, intelligence, wisdom, charisma;
	std::string rollStat();

public:
	ScreenCharacterCreation(Game* game);
	void render() override;
	void setStrength(std::string value);
	void setConstitution(std::string value);
	void setDexterity(std::string value);
	void setIntelligence(std::string value);
	void setWisdom(std::string value);
	void setCharisma(std::string value);




};
