#include "Monster.h"
#include "Pathfinder.h"

Monster::Monster():LivingEntity('M')
{
	
}

void Monster::simulate(Map* map, Pathfinder* pathfinder)
{
	std::vector<Node*> path = pathfinder->getPath(getPositionX(), getPositionY());
	if (path.size() > 0 && path.size() < 5)
	{
		Node* nextNode = path[path.size()-1];
		map->moveEntity(this, nextNode->x, nextNode->y);
	}
}

