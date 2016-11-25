#include "Strategy.h"

#include <iostream>
#include "Pathfinder.h"

void Strategy::doStrategy(Map* map, LivingEntity* le)
{
	Character* character = map->getCharacter();
	Pathfinder* pathfinder = new Pathfinder(map, character->getPositionX(), character->getPositionY());

	if (pathfinder == nullptr) {
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

		return;
	}
	std::vector<Node*>* path = pathfinder->getPath(le->getPositionX(), le->getPositionY());


	if (path->size() > 0 && path->size() <le->getPathfinderDistance())
	{
		Node* nextNode = (*path)[path->size() - 1];
		map->moveEntity(le, nextNode->x, nextNode->y);
	}
}

void CharacterStrategy::doStrategy(Map* map,LivingEntity* le)
{

}

void FriendlyStrategy::doStrategy(Map* map, LivingEntity* le)
{
	std::cout << "Do friendly action!";
	Strategy::doStrategy(map,le);
}

void HostileStrategy::doStrategy(Map* map, LivingEntity* le)
{
	Strategy::doStrategy(map, le);
	std::cout << "Do hostile action";
	//attack character if possible
	Character* character = map->getCharacter();
	if (character->distanceTo(le) <= 1) {
		if (character->hit(5)) {
			//map->removeEntity(c->getPositionX(), c->getPositionY());
		}
	}
}
