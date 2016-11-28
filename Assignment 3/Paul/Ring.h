#pragma once

#include "CharacterDecorator.h"

class Ring : public CharacterDecorator
{
private:
	int strength, constitution, wisdom, charisma, armorClass;

public:
	Ring(AbstractCharacter *decoratedCharacter, int str, int con, int wis, int cha, int armor) : CharacterDecorator(decoratedCharacter)
	{
		if (CharacterDecorator::getEquipped()[6] == true)
		{
			std::cout << "Cannot equip another ring..." << std::endl;
		}
		else
		{
			this->strength = str;
			this->constitution = con;
			this->wisdom = wis;
			this->charisma = cha;
			this->armorClass = armor;
			decoratedCharacter->getEquipped()[6] = true;
		}
		

	}


	int getStrength() {
		return CharacterDecorator::getStrength() + this->strength;
	}

	int getConstitution() {
		return CharacterDecorator::getConsitution() + this->constitution;
	}

	int getWisdom() {
		return CharacterDecorator::getWisdom() + this->wisdom;
	}

	int getCharisma() {
		return CharacterDecorator::getCharisma() + this->charisma;
	}
	int getArmorClass() {
		return CharacterDecorator::getArmorClass() + this->armorClass;
	}
};