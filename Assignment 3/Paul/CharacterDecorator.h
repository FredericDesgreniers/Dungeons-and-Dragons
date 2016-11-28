#pragma once

#include "AbstractCharacter.h"
#include "Character.h"
#include <iostream>;

class CharacterDecorator : public AbstractCharacter
{
protected:
	AbstractCharacter *decoratedCharacter;
public:

	/*
	Character Decorator constructor
	*/
	CharacterDecorator(AbstractCharacter *decoratedCharacter)
	{
		this->decoratedCharacter = decoratedCharacter;
	}

	int getLevel() {
		return decoratedCharacter->getLevel();
	}

	int getHitPoints() {
		return decoratedCharacter->getHitPoints();
	}

	int getStrength() {
		return decoratedCharacter->getStrength();
	}

	int getConsitution() {
		return decoratedCharacter->getConsitution();
	}

	int getDexterity() {
		return decoratedCharacter->getDexterity();
	}

	int getIntelligence() {
		return decoratedCharacter->getIntelligence();
	}

	int getWisdom() {
		return decoratedCharacter->getWisdom();
	}

	int getCharisma() {
		return decoratedCharacter->getCharisma();
	}


	int* getAbilityScoreArray()
	{
		return decoratedCharacter->getAbilityScoreArray();
	}

	int getArmorClass() {
		return decoratedCharacter->getArmorClass();
	}

	int getDamage() {
		return decoratedCharacter->getDamage();
	}

	int getAttack() {
		return decoratedCharacter->getAttack();
	}

	bool* getEquipped() {
		return decoratedCharacter->getEquipped();
	}

	std::string toString() {
		return decoratedCharacter->toString();
	}

	std::string inventoryDisplay() {
		return decoratedCharacter->inventoryDisplay();
	}


};