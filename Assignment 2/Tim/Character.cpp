//! @file 
//! @brief Implementation file for the Character class 
//!
#include "Character.h"

Character::Character() : Character(Dice::rollStat(), Dice::rollStat(), Dice::rollStat(), Dice::rollStat(), Dice::rollStat(), Dice::rollStat(),1)
{
}


Character::Character(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int lvl)

{
	level = lvl;
	abilityscores[0] = strength;
	abilityscores[1] = dexterity;
	abilityscores[2] = constitution;
	abilityscores[3] = intelligence;
	abilityscores[4] = wisdom;
	abilityscores[5] = charisma;
	health = maxHealth = 20;
}


bool Character::hit(int damage)
{
	health -= damage;
	if (health > maxHealth)
	health = maxHealth;
	Notify();
	return health <= 0;
}

int Character::getHealth()
{
	return health;
}

int Character::getMaxHealth()
{
	return maxHealth;
}

int Character::getLevel()
{
	return level;
}

int* Character::getAbilityScoreArray()
{
	return abilityscores;
}


int Character::getStrength()
{
	return abilityscores[0];
}


int Character::getDexterity()
{
	return abilityscores[1];
}

int Character::getConstitution()
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

void Character::setLevel(int value)
{
	level = value;
	Notify();
}


void Character::setStrength(int value)
{
	abilityscores[0] = value;
	Notify();
}


void Character::setDexterity(int value)
{
	abilityscores[1]=value;
	Notify();
}

void Character::setConstitution(int value)
{
	abilityscores[2] = value;
	Notify();
}

void Character::setIntelligence(int value)
{
	abilityscores[3] = value;
	Notify();
}

void Character::setWisdom(int value)
{
	abilityscores[4] = value;
	Notify();
}

void Character::setCharisma(int value)
{
	abilityscores[5] = value;
	Notify();
}

