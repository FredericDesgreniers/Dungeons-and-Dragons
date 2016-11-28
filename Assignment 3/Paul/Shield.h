//! @file 
//! @brief Header file for Shield class  
//!
//! Shield class implementation left in .h for simplicity
//! Contains an armor class boost
#pragma once

#include "CharacterDecorator.h"

class Shield : public CharacterDecorator
{
private:
	int armorClass;

public:
	Shield(AbstractCharacter *decoratedCharacter, int armor) : CharacterDecorator(decoratedCharacter)
	{
		if (CharacterDecorator::getEquipped()[1] == true)
		{
			std::cout << "Cannot equip another shield..." << std::endl;
		}
		else
		{
			this->armorClass = armor;
			decoratedCharacter->getEquipped()[1] = true;
		}
	}

	int getArmorClass() {
		return CharacterDecorator::getArmorClass() + this->armorClass;
	}

	

};