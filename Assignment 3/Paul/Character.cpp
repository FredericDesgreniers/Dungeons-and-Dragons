//! @file 
//! @brief Implementation file for the Character class  
//!
#include "Character.h"
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
	abilityscores[6] = rand() % 16 + 3;
	abilityscores[7] = rand() % 16 + 3;
	abilityscores[8] = rand() % 16 + 3;


	hitpoints = 10;
}

Character::Character(int str, int dex, int cons, int intel, int wisd, int chari, int armor, int damage, int attack)
{
	abilityscores[0] = str;
	abilityscores[1] = dex;
	abilityscores[2] = cons;
	abilityscores[3] = intel;
	abilityscores[4] = wisd;
	abilityscores[5] = chari;
	abilityscores[6] = armor;
	abilityscores[7] = damage;
	abilityscores[8] = attack;

	equipped[0] = false; // weapon
	equipped[1] = false; // shield
	equipped[2] = false;  // boots
	equipped[3] = false; // armor
	equipped[4] = false; // helmet
	equipped[5] = false; // belt
	equipped[6] = false; // ring


	hitpoints = 10;
}

void Character::hit(int damage)
{
	hitpoints -= damage;
	
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

int Character::getArmorClass()
{
	return abilityscores[6];
}

int Character::getDamage()
{
	return abilityscores[7];
}

int Character::getAttack()
{
	return abilityscores[8];
}

bool* Character::getEquipped()
{
	return equipped;
}

int* Character::getAbilityScoreArray()
{
	return abilityscores;
}

void Character::setStrength(int str)
{
	abilityscores[0] = str;
}

void Character::setDexterity(int dex)
{
	abilityscores[1] = dex;
}

void Character::setConsitution(int cons)
{
	abilityscores[2] = cons;
}

void Character::setIntelligence(int intel)
{
	abilityscores[3] = intel;
}

void Character::setWisdom(int wis)
{
	abilityscores[4] = wis;
}


void Character::setCharisma(int cha)
{
	abilityscores[5] = cha;
}

void Character::setArmorClass(int arm)
{
	abilityscores[6] = arm;
}

void Character::setDamage(int dmg)
{
	abilityscores[7] = dmg;
}

void Character::setAttack(int atk)
{
	abilityscores[8] = atk;
}

std::string Character::inventoryDisplay() {
	return "Character currently wearing: \nWeapon: " + std::to_string(getEquipped()[0]) +
		"\nShield: " + std::to_string(getEquipped()[1]) +
		"\nBoots: " + std::to_string(getEquipped()[2]) +
		"\nArmor: " + std::to_string(getEquipped()[3]) +
		"\nHelmet: " + std::to_string(getEquipped()[4]) +
		"\nBelt: " + std::to_string(getEquipped()[5]) +
		"\nRing: " + std::to_string(getEquipped()[6]) + "\n";
}







