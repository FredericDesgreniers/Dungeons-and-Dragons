#include "Monster.h"
#include "Pathfinder.h"
#include <ctime>

Monster::Monster():LivingEntity('M')
{
	setPathfinderDistance(8);
	setName("Monster");
}
Monster::Monster(char c):LivingEntity(c)
{
	setPathfinderDistance(8);
}



SDL_Color Monster::getDisplayColor()
{
	return{ 255,200,0,255 };
}
