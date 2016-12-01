#include "Strategy.h"

#include <iostream>
#include "Pathfinder.h"

void Strategy::doStrategy(Map* map, LivingEntity* le)
{
	Character* character = map->getCharacter();
	Pathfinder* pathfinder = new Pathfinder(map, character->getPositionX(), character->getPositionY());

	//get pathfinder path
	std::vector<Node*>* path = pathfinder->getPath(le->getPositionX(), le->getPositionY());

	//Makes sure path is valid
	if (path->size() > 0 && path->size() <le->getPathfinderDistance())
	{
		//move along the path by one node.
		Node* nextNode = (*path)[path->size() - 1];
		map->moveEntity(le, nextNode->x, nextNode->y);
	}else
	{
		int side = rand() % 4;
		switch (side)
		{
		case 1:
			map->moveEntity(le, le->getPositionX() + 1, le->getPositionY());
			break;
		case 2:
			map->moveEntity(le, le->getPositionX() - 1, le->getPositionY());
			break;
		case 3:
			map->moveEntity(le, le->getPositionX(), le->getPositionY() + 1);
			break;
		case 4:
			map->moveEntity(le, le->getPositionX(), le->getPositionY() - 1);
			break;
		}
	}
	delete pathfinder;
}

void CharacterStrategy::doStrategy(Map* map,LivingEntity* le)
{
	
}

void FriendlyStrategy::doStrategy(Map* map, LivingEntity* le)
{

	Strategy::doStrategy(map,le);
	le->setTurnFinished(true);
	std::cout << "Friendly strategy excecuted for entity at " << le->getPositionX() << "," << le->getPositionY() << std::endl;
}

void HostileStrategy::doStrategy(Map* map, LivingEntity* le)
{
	Strategy::doStrategy(map, le);
	//attack character if possible
	Character* character = map->getCharacter();
	if (character->distanceTo(le) <= 1) {
		if (le->interact(map, character)) {
			//map->removeEntity(c->getPositionX(), c->getPositionY());
		}
	}
	le->setTurnFinished(true);
	std::cout << "Hostile strategy excecuted for " << (le->getHostile()?"hostile":"friendly") << " entity at position "<< le->getPositionX() << ","<< le->getPositionY() << std::endl;
}
