#include "character.h"
#include <iostream>
#include <ctime>

Character::Character(int level):LivingEntity('C')
{
	srand(time(NULL));

	this->level = level;

	abilityscores[0] = Dice::rollStat();
	abilityscores[1] = Dice::rollStat();
	abilityscores[2] = Dice::rollStat();
	abilityscores[3] = Dice::rollStat();
	abilityscores[4] = Dice::rollStat();
	abilityscores[5] = Dice::rollStat();

	hitpoints = 10;

}

Character::Character(int str, int dex, int cons, int intel, int wisd, int chari):LivingEntity('C')
{
	abilityscores[0] = str;
	abilityscores[1] = dex;
	abilityscores[2] = cons;
	abilityscores[3] = intel;
	abilityscores[4] = wisd;
	abilityscores[5] = chari;

	hitpoints = 10;
}



int Character::getModifier(int score)
{
	return (score - 10) / 2;
}

bool Character::validateNewCharacter()
{
	for (int i = 0; i < (sizeof(abilityscores) / sizeof(int)); i++){
		if (abilityscores[i] < 3 || abilityscores[i] > 18)
			return false;
		
	}
	return true;
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

int Character::getHitPoints()
{
	return hitpoints;
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



