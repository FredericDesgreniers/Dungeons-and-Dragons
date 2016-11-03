#include "Wizard.h"
#include "GUI/Renderer.h"

Wizard::Wizard():Monster('W')
{
	spellProgress = 0;
	setPathfinderDistance(15);
}

void Wizard::simulate(Map* map, Pathfinder* pathfinder)
{
	Character* c = map->getCharacter();
	if (realDistanceTo(c->getPositionX(), c->getPositionY()) < 5)
	{
		spellProgress+=34;
		if(spellProgress > 100)
		{
			spellProgress = 0;
			if(c->hit(20))
			{
				map->removeEntity(c->getPositionX(), c->getPositionY());
			}
		}
	}else
	{
		spellProgress = 0;
		Monster::simulate(map, pathfinder);
	}
}


int Wizard::getSpellProgress()
{
	return spellProgress;
}
