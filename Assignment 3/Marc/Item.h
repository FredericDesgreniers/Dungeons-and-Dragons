//! @file 
//! @brief Header file for the Item class.
//!
#pragma once
#include "CharacterDecorator.h"
#include "Character.h"
#include <string>

//! call that represents an Item, its attributes and its behaviors
class Item : public CharacterDecorator
{

private:

	std::string name;
	EquipmentSlot slot;
	int strBonus;
	int	conBonus;
	int dexBonus;
	int intBonus;
	int chaBonus;
	int wisBonus;

public:

	Item();
	Item(std::string name, EquipmentSlot kind, int strBonus, int conBonus, int dexBonus, int intBonus, int chaBonus, int wisBonus);

	Character* getDecoratedCharacter() { return CharacterDecorator::getDecoratedCharacter(); }

	std::string getName() { return name; }
	std::string getCharName() { return CharacterDecorator::getCharName(); }
	EquipmentSlot getSlot() { return slot; }
	std::string getStats();
	int getStrenght() { return CharacterDecorator::getStrenght() + strBonus; }
	int getConstitution() { return CharacterDecorator::getConstitution() + conBonus; }
	int getDexterity() { return CharacterDecorator::getDexterity() + dexBonus; }
	int getIntelligence() { return CharacterDecorator::getIntelligence() + intBonus; }
	int getCharisma() { return CharacterDecorator::getCharisma() + chaBonus; }
	int getWisdom() { return CharacterDecorator::getWisdom() + wisBonus; }
	
	std::string getEquipment();
	bool validateEquipmentSlot(EquipmentSlot equipmentSlot);

	bool isCharacter() { return false; }
};