#include "LivingEntity.h"

LivingEntity::LivingEntity(char c):Entity(c)
{
	abilityscores[0] = Dice::rollStat();
	abilityscores[1] = Dice::rollStat();
	abilityscores[2] = Dice::rollStat();
	abilityscores[3] = Dice::rollStat();
	abilityscores[4] = Dice::rollStat();
	abilityscores[5] = Dice::rollStat();
	level = 1;
	// TODO: Proper HP Calculations
	maxHealth = 100;
	health = 100;

}


LivingEntity::LivingEntity(char c, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int level):Entity(c), level(level)

{
	abilityscores[0] = strength;
	abilityscores[1] = dexterity;
	abilityscores[2] = constitution;
	abilityscores[3] = intelligence;
	abilityscores[4] = wisdom;
	abilityscores[5] = charisma;

	// TODO: Proper HP calculations
	maxHealth = 100;
	health = 100;

}


bool LivingEntity::hit(int damage)
{
	health -= damage;
	if (health > maxHealth)
		health = maxHealth;
	return health <= 0;
}

int LivingEntity::getHealth()
{
	return health;
}

int LivingEntity::getMaxHealth()
{
	return maxHealth;
}

int LivingEntity::getLevel()
{
	return level;
}

int* LivingEntity::getAbilityScoreArray()
{
	return abilityscores;
}

int LivingEntity::getStrength()
{
	return abilityscores[0];
}


int LivingEntity::getDexterity()
{
	return abilityscores[1];
}

int LivingEntity::getConsitution()
{
	return abilityscores[2];
}

int LivingEntity::getIntelligence()
{
	return abilityscores[3];
}

int LivingEntity::getWisdom()
{
	return abilityscores[4];
}

int LivingEntity::getCharisma()
{
	return abilityscores[5];
}

void LivingEntity::setLevel(int value)
{
	level = value;
}


void LivingEntity::setStrength(int value)
{
	abilityscores[0] = value;
}


void LivingEntity::setDexterity(int value)
{
	abilityscores[1]=value;
}

void LivingEntity::setConsitution(int value)
{
	abilityscores[2] = value;
}

void LivingEntity::setIntelligence(int value)
{
	abilityscores[3] = value;
}

void LivingEntity::setWisdom(int value)
{
	abilityscores[4] = value;
}

void LivingEntity::setCharisma(int value)
{
	abilityscores[5] = value;
}

