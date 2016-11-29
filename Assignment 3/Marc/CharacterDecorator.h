//! @file 
//! @brief Header file for the CharacterDecorator class.
//!
#pragma once
#include "Character.h"

//! Class that represents a CharacterDecorator, it attributes and its behaviors
class CharacterDecorator : public Character
{

private:

	EquipmentSlot decorationSlot;
	Character *decoratedCharacter;

public:

	CharacterDecorator();
	CharacterDecorator(Character *decoratedCharacter, EquipmentSlot decorationKind);

	Character* getSelf() { return this; }

	Character* getDecoratedCharacter();

	std::string getCharName() { return decoratedCharacter->getCharName(); }
	int getStrenght() { return decoratedCharacter->getStrenght(); }
	int getConstitution() { return decoratedCharacter->getConstitution(); }
	int getDexterity() { return decoratedCharacter->getDexterity(); }
	int getIntelligence() { return decoratedCharacter->getIntelligence(); }
	int getCharisma() { return decoratedCharacter->getCharisma(); }
	int getWisdom() { return decoratedCharacter->getWisdom(); }

	std::string getStats() { return decoratedCharacter->getStats(); }
	std::string getEquipment() { return decoratedCharacter->getEquipment(); }
	bool validateEquipmentSlot(EquipmentSlot equipmentSlot) { return decoratedCharacter->validateEquipmentSlot(equipmentSlot); }

	void setDecoratedCharacter(Character *character);
};
