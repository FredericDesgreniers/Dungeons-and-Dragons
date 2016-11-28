//! @file 
//! @brief Header file for Armor class  
//!
//! Armor class implementation left in .h for simplicity
//! Contains an armor class boost
#pragma once

#include "CharacterDecorator.h"

class Armor : public CharacterDecorator
{
private:
	int armorClass;

public:
	Armor(AbstractCharacter *decoratedCharacter, int armor) : CharacterDecorator(decoratedCharacter)
	{
		if (CharacterDecorator::getEquipped()[3] == true)
		{
			std::cout << "Cannot equip another armor..." << std::endl;
		}
		else
		{
			this->armorClass = armor;
			decoratedCharacter->getEquipped()[3] = true;
		}
	}

	int getArmorClass() {
		return CharacterDecorator::getArmorClass() + this->armorClass;
	}
};