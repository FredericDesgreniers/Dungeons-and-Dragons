#pragma once
#include <string>
class AbstractCharacter
{

public:

	virtual int getLevel() = 0;

	virtual int getHitPoints() = 0;

	virtual int getStrength() = 0;

	virtual int getDexterity() = 0;

	virtual int getConsitution() = 0;

	virtual int getIntelligence() = 0;

	virtual int getWisdom() = 0;

	virtual int getCharisma() = 0;

	virtual int* getAbilityScoreArray() = 0;

	virtual int getArmorClass() = 0;

	virtual int getDamage() = 0;

	virtual int getAttack() = 0;

	virtual std::string toString() = 0;

	virtual std::string inventoryDisplay() = 0;

	virtual bool* getEquipped() = 0;

};