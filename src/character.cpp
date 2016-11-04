#include "character.h"
#include <iostream>
#include <ctime>

Character::Character(int level):LivingEntity('C')
{
	setLevel(level);
}

Character::Character(int str, int dex, int cons, int intel, int wisd, int chari, int lvl):LivingEntity('C', str, dex, cons, intel, wisd, chari, lvl)
{
	

}



int Character::getModifier(int score)
{
	return (score - 10) / 2;
}


// I temporarily removed this since there is no real need to validate characters after creation 
//(neither the character editor or default constructor will ever produce a character with invalid stats)
/**
{
	for (int i = 0; i < (sizeof(getAbilityScoreArray) / sizeof(int)); i++){
		if (abilityScores[i] < 3 || abilityscores[i] > 18)
			return false;
		
	}
	return true;
}
*/




