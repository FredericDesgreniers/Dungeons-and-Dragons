#include "Strategy.h"

#include <iostream>
#include "Pathfinder.h"

void Strategy::doStrategy(Map* map, LivingEntity* le)
{
	LivingEntity* character = map->getCharacter();
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
	le->setMovementRemaining(le->getMovementRemaining() - 1);
	delete pathfinder;
}

void CharacterStrategy::doStrategy(Map* map,LivingEntity* le)
{
	
}

void FriendlyStrategy::doStrategy(Map* map, LivingEntity* le)
{

	Strategy::doStrategy(map,le);
	le->setTurnFinished(true);

}

void HostileStrategy::doStrategy(Map* map, LivingEntity* le)
{
	if (le->getHealth() <= 0)
		le->setTurnFinished(true);
	Strategy::doStrategy(map, le);
	//attack character if possible
	LivingEntity* character = map->getCharacter();
	if (character->distanceTo(le) <= 1 && le->getAttacksRemaining()>0) {
		if (le->interact(map, character)) {
			
		}
	}else
	{
		if(le->getMovementRemaining()==0)
			le->setTurnFinished(true);
	}
	if(le->getAttacksRemaining() == 0 && le->getMovementRemaining()==0)
		le->setTurnFinished(true);


	//std::cout << "Hostile strategy excecuted for " << (le->getHostile()?"hostile":"friendly") << " entity at position "<< le->getPositionX() << ","<< le->getPositionY() << std::endl;
}
