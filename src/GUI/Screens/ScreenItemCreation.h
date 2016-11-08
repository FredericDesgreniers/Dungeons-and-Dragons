#pragma once

#include "Screen.h"
#include "ScreenMain.h"
#include "../../Item.h"
#include "../Components/TextField.h"
#include "../Renderer.h"
#include "../../Observer.h"




class ScreenItemCreation : public Screen, public Observer
{
private:
	Item* it;
	TextField* itemName;
	std::string abilityScores[9];
	std::string type;
	int typeCounter;
public:
	ScreenItemCreation(Game* game);
	~ScreenItemCreation();
	void render() override;

	void setType(std::string value);
	void setStrength(std::string value);
	void setConstitution(std::string value);
	void setDexterity(std::string value);
	void setIntelligence(std::string value);
	void setWisdom(std::string value);
	void setCharisma(std::string value);
	void setAttack(std::string value);
	void setDamage(std::string value);
	void setArmor(std::string value);

	void increment(int stat);
	void decrement(int stat);
	void changeType(int stat);

	void createItem();

	void Update();

};