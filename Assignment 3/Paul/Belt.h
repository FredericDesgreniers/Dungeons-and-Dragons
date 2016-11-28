//! @file 
//! @brief Header file for Belt class  
//!
//! Belt class implementation left in .h for simplicity
//! Contains a constitution and strength boost
#pragma once

#include "CharacterDecorator.h"

class Belt : public CharacterDecorator
{
private:
	int constitution, strength;

public:
	Belt(AbstractCharacter *decoratedCharacter, int con, int str) : CharacterDecorator(decoratedCharacter)
	{
		if (CharacterDecorator::getEquipped()[5] == true)
		{
			std::cout << "Cannot equip another belt..." << std::endl;
		}
		else
		{
			this->constitution = con;
			this->strength = str;
			decoratedCharacter->getEquipped()[5] = true;
		}
	}

	int getConsitution() {
		return CharacterDecorator::getConsitution() + this->constitution;
	}

	int getStrength() {
		return CharacterDecorator::getStrength() + this->strength;
	}
};