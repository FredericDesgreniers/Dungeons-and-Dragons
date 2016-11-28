//! @file 
//! @brief Header file for Boots class  
//!
//! Boots class implementation left in .h for simplicity
//! Contains an armor class and dexterity boost
#pragma once

#include "CharacterDecorator.h"

class Boots : public CharacterDecorator
{
private:
	int armorClass, dexterity;

public:
	Boots(AbstractCharacter *decoratedCharacter, int armor, int dex) : CharacterDecorator(decoratedCharacter)
	{
		if (CharacterDecorator::getEquipped()[2] == true)
		{
			std::cout << "Cannot equip another boots..." << std::endl;
		}
		else
		{
			this->armorClass = armor;
			this->dexterity = dex;
			decoratedCharacter->getEquipped()[2] = true;
		}
	}

	int getArmorClass() {
		return CharacterDecorator::getArmorClass() + this->armorClass;
	}

	int getDexterity() {
		return CharacterDecorator::getDexterity() + this->dexterity;
	}
};
