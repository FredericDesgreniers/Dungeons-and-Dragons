#include "Monster.h"
#include "Pathfinder.h"
#include <ctime>

Monster::Monster():LivingEntity('M')
{
	setPathfinderDistance(8);
}
Monster::Monster(char c):LivingEntity(c)
{
	setPathfinderDistance(8);
}

void Monster::simulate(Map* map, Pathfinder* pathfinder)
{
	if (pathfinder == nullptr) {
		int side = rand() % 4;
		switch(side)
		{
		case 1:
			map->moveEntity(this, getPositionX() + 1, getPositionY());
			break;
		case 2:
			map->moveEntity(this, getPositionX() - 1, getPositionY());
			break;
		case 3:
			map->moveEntity(this, getPositionX(), getPositionY()+1);
			break;
		case 4:
			map->moveEntity(this, getPositionX(), getPositionY()-1);
			break;
		}

		return;
	}
	std::vector<Node*> path = pathfinder->getPath(getPositionX(), getPositionY());
	Character* c = map->getCharacter();
	if(c->distanceTo(this) <= 1){
		
		if (c->hit(5))
			map->removeEntity(c->getPositionX(), c->getPositionY());
	}
	if (path.size() > 0 && path.size() < getPathfinderDistance())
	{
		Node* nextNode = path[path.size()-1];
		map->moveEntity(this, nextNode->x, nextNode->y);
	}

}

bool Monster::interact(Map* map, Entity* entity)
{
	if(Character* c = dynamic_cast<Character*>(entity))
	{
		if(hit(c->getStrength()*2))
		{
			map->removeEntity(getPositionX(), getPositionY());
		}
		return true;
	} 
	return false;
}

