#pragma once
#include "LivingEntity.h"

/**
 * An entity that seeks out the player to kill him
 */
class Monster:public LivingEntity
{
public:
	Monster();

	




	SDL_Color getDisplayColor();

protected:
	Monster(char c);
};
