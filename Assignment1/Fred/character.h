#pragma once
#include "stdlib.h"
#include "time.h"

class Character
{
private:
	int level;
	int hitpoints;
	int abilityscores[6];
public:
	Character(int level);
	Character(int str, int dex, int cons, int intel, int wisd, int chari);
	int getModifier(int);
	void hit(int);

	bool validateNewCharacter();

	//getters
	int getLevel()
	{
		return level;
	}
	int getHitPoints()
	{
		return hitpoints;
	}

	int getStrength()
	{
		return abilityscores[0];
	} 
	int getDexterity()
	{
		return abilityscores[1];
	}
	int getConsitution()
	{
		return abilityscores[2];
	} 
	int getIntelligence()
	{
		return abilityscores[3];
	} 
	int getWisdom()
	{
		return abilityscores[4];
	} 
	int getCharisma()
	{
		return abilityscores[5];
	}


};

