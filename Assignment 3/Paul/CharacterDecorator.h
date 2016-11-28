//! @file 
//! @brief Header file for CharacterDecorator
//!
//! Extends the AbstractCharacter class and delegates the setters to decorators
//! Items decorating are the following classes:
//! Helmet, Ring, Weapon, Belt, Boots, Armor and Shield
//! Those 7 classes decorating the character are very similar
//! They implement the functions to access the scores they are modifying
//! We implement the decorator pattern with .h files for simplicity
//! The character class used is a simplified version but has all scores needed

#pragma once

#include "AbstractCharacter.h"
#include "Character.h"
#include <iostream>


class CharacterDecorator : public AbstractCharacter
{
	/**
	* decorated character member for Decorator
	*/
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

	// Implementation of virtual functions from the Abstract parent class
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

	//! Displays current scores
	std::string toString() {
		return "Character scores:\nStr:          "
			+ std::to_string(getStrength()) + "\nDex:          "
			+ std::to_string(getDexterity()) + "\nCons:         "
			+ std::to_string(getConsitution()) + "\nIntel:        "
			+ std::to_string(getIntelligence()) + "\nWisd:         "
			+ std::to_string(getWisdom()) + "\nChari:        "
			+ std::to_string(getCharisma()) + "\nArmor class:  "
			+ std::to_string(getArmorClass()) + "\nDamage:       "
			+ std::to_string(getDamage()) + "\nAttack:       "
			+ std::to_string(getAttack()) + "\nHP:           "
			+ std::to_string(getHitPoints()) + "\n";
	}
	
	//! displays current inventory
	std::string inventoryDisplay() {
		return decoratedCharacter->inventoryDisplay();
	}
};