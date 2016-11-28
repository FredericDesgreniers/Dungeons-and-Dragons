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