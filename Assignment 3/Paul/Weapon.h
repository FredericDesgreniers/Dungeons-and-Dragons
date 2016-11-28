#pragma once

#include "CharacterDecorator.h"

class Weapon : public CharacterDecorator
{
private:
	int attack, damage;

public:
	Weapon(AbstractCharacter *decoratedCharacter, int atk, int dmg) : CharacterDecorator(decoratedCharacter)
	{
		if (CharacterDecorator::getEquipped()[0] == true)
		{
			std::cout << "Cannot equip another weapon..." << std::endl;
		}
		else
		{
			this->attack = atk;
			this->damage = dmg;
			decoratedCharacter->getEquipped()[0] = true;
		}
	}

	int getAttack() {
		return CharacterDecorator::getAttack() + this->attack;
	}

	int getDamage() {
		return CharacterDecorator::getDamage() + this->damage;
	}
};