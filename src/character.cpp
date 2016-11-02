#include "character.h"
#include <iostream>

Character::Character(int level)
{
	srand(time(NULL));

	this->level = level;

	abilityscores[0] = rand() %16+3;
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
