#pragma once
#include "Screen.h"
#include "screenMain.h"
#include "../../character.h"
#include <sstream>
#include "../Components/TextField.h"
#include "../Components/EquipedItemComponent.h"
#include "../Renderer.h"
#include "../../dice.h"
#include "../../Observer.h"
#include <string>

class ScreenCharacterCreation : public Screen, public Observer
{

private:
	std::string abilityScores[7];
	Character* character;
	TextField* nameInput;
	int mods[6];

public:
	ScreenCharacterCreation(Game* game);
	void render() override;
	void createCharacter();
	~ScreenCharacterCreation();
	void setStrength(std::string value);
	void setConstitution(std::string value);
	void setDexterity(std::string value);
	void setIntelligence(std::string value);
	void setWisdom(std::string value);
	void setCharisma(std::string value);
	void setRemaining(std::string value);
	void increment(int stat);
	void decrement(int stat);
	void Update();

	void rollCharacter();

};
