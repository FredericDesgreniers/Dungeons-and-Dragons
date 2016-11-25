#include "character.h"

Character::Character(int level) :LivingEntity('C')
{
	setLevel(level);
}

Character::Character(int str, int dex, int cons, int intel, int wisd, int chari, int lvl) : LivingEntity('C', str, dex, cons, intel, wisd, chari, lvl)
{
}

Character::Character(int str, int dex, int cons, int intel, int wisd, int chari, int lvl, std::string cname) : LivingEntity('C', str, dex, cons, intel, wisd, chari, lvl, cname)
{

}



bool Character::validateNewCharacter()
{
	
	int* abilities = getAbilityScoreArray();
	for (int i = 0; i < 7; i++){
		if (abilities[i] < 3 || abilities[i] > 18)
			return false;

	}
	return true;
}




