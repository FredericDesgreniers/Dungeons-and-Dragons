#pragma once
#include "Screen.h"
#include "screenMain.h"
#include "../../character.h"
#include <sstream>
#include "../Components/TextField.h"
#include "../Renderer.h"
#include "../../dice.h"
#include <string>

class ScreenCharacterCreation : public Screen
{

private:
	std::string strength, constitution, dexterity, intelligence, wisdom, charisma;
	std::string rollStat();
	Character* character;
	TextField* nameInput;

public:
	ScreenCharacterCreation(Game* game);
	void render() override;
	void createCharacter();
	void setStrength(std::string value);
	void setConstitution(std::string value);
	void setDexterity(std::string value);
	void setIntelligence(std::string value);
	void setWisdom(std::string value);
	void setCharisma(std::string value);



};
