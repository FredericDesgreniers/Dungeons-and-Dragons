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
	}
}

void CharacterStrategy::doStrategy(Map* map,LivingEntity* le)
{
	//get player input
	std::cout << "Input character move: (n,e,s,w):";
	char c;
	std::cin >> c;
	int x = le->getPositionX();
	int y = le->getPositionY();
	//Get x for action
	switch(tolower(c))
	{
	case 'n':
		y--;
		break;
	case 'e':
		x++;
		break;
	case 's':
		y++;
		break;
	case 'w':
		x--;
		break;
	}
	//is tile occupied by entity?
	if(Entity* en = map->getEntity(x,y))
	{
		//interact with entity
		if(LivingEntity* entity = dynamic_cast<LivingEntity*>(en))
		{
			if (!entity->getHostile()) {
				entity->setStrategy(new HostileStrategy());

			}
			entity->hit(10);
			if (entity->getHealth() <= 0)
			{
				map->removeEntity(entity->getPositionX(), entity->getPositionY());
			}
			le->setTurnFinished(true);
		}
	}else //move entity
	{
		if(map->moveEntity(le, x, y))
		{
			le->setTurnFinished(true);
		}
	}
}

void FriendlyStrategy::doStrategy(Map* map, LivingEntity* le)
{

	Strategy::doStrategy(map,le);
	le->setTurnFinished(true);
}

void HostileStrategy::doStrategy(Map* map, LivingEntity* le)
{
	Strategy::doStrategy(map, le);
	//attack character if possible
	Character* character = map->getCharacter();
	if (character->distanceTo(le) <= 1) {
		if (character->hit(5)) {
			//map->removeEntity(c->getPositionX(), c->getPositionY());
		}
	}
	le->setTurnFinished(true);
}
