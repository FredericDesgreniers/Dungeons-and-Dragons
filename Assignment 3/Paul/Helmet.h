#pragma once
#include "CharacterDecorator.h"

class Helmet : public CharacterDecorator
{
private:
	int intelligence, wisdom, armorClass;

public:
	Helmet(AbstractCharacter *decoratedCharacter, int intel, int wisdom, int armor) : CharacterDecorator(decoratedCharacter) 
	{
		if (CharacterDecorator::getEquipped()[4] == true)
		{
			std::cout << "Cannot equip another helmet..." << std::endl;
		}
		else
		{
			this->intelligence = intel;
			this->wisdom = wisdom;
			this->armorClass = armor;
			decoratedCharacter->getEquipped()[4] = true;
		}
	}

	int getIntelligence() {
		return CharacterDecorator::getIntelligence() + this->intelligence;
	}

	int getWisdom() {
		return CharacterDecorator::getWisdom() + this->wisdom;
	}

	int getArmorClass() {
		return CharacterDecorator::getArmorClass() + this->armorClass;
	}
};
