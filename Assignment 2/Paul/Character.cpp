//! @file 
//! @brief Implementation file for the Character class  
//!
#include "Character.h"
#include "CharacterObserver.h"
#include <iostream>

Character::Character(int level)
{
	srand(time(NULL));

	this->level = level;

	abilityscores[0] = rand() % 16 + 3;
	abilityscores[1] = rand() % 16 + 3;
	abilityscores[2] = rand() % 16 + 3;
	abilityscores[3] = rand() % 16 + 3;
	abilityscores[4] = rand() % 16 + 3;
	abilityscores[5] = rand() % 16 + 3;

	hitpoints = 10;
}

Character::Character(int str, int dex, int cons, int intel, int wisd, int chari)
{
	abilityscores[0] = str;
	abilityscores[1] = dex;
	abilityscores[2] = cons;
	abilityscores[3] = intel;
	abilityscores[4] = wisd;
	abilityscores[5] = chari;

	hitpoints = 10;
}

void Character::hit(int damage)
{
	hitpoints -= damage;
	Character::Notify();
}

int Character::getModifier(int score)
{
	return (score - 10) / 2;
}

bool Character::validateNewCharacter()
{
	for (int i = 0; i < (sizeof(abilityscores) / sizeof(int)); i++) {
		if (abilityscores[i] < 3 || abilityscores[i] > 18)
			return false;

	}
	return true;
}

int Character::getLevel()
{
	return level;
}

int Character::getHitPoints()
{
	return hitpoints;
}

int Character::getStrength()
{
	return abilityscores[0];
}

int Character::getDexterity()
{
	return abilityscores[1];
}

int Character::getConsitution()
{
	return abilityscores[2];
}

int Character::getIntelligence()
{
	return abilityscores[3];
}

int Character::getWisdom()
{
	return abilityscores[4];
}

int Character::getCharisma()
{
	return abilityscores[5];
}

int* Character::getAbilityScoreArray()
{
	return abilityscores;
}

void Character::setStrength(int str)
{
	abilityscores[0] = str;
	Notify();
}

void Character::setDexterity(int dex)
{
	abilityscores[1] = dex;
	Notify();
}

void Character::setConsitution(int cons)
{
	abilityscores[2] = cons;
	Notify();
}

void Character::setIntelligence(int intel)
{
	abilityscores[3] = intel;
	Notify();
}

void Character::setWisdom(int wis)
{
	abilityscores[4] = wis;
	Notify();
}

void Character::setCharisma(int cha)
{
	abilityscores[5] = cha;
	Notify();
}

