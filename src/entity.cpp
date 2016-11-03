#include "entity.h"
#include "Pathfinder.h"
Entity::Entity(char renderChar):renderChar(renderChar)
{
	
}

void Entity::simulate(Map* map, Pathfinder* pathfinder)
{
	
}

bool Entity::interact(Map* map ,Entity* entity)
{
	return false;
}

int Entity::distanceTo(Entity* entity)
{
	return (std::abs(entity->getPositionX() - positionX) + std::abs(entity->getPositionY() - positionY));
}

int Entity::getPositionY()
{
	return positionY;
}
int Entity::getPositionX()
{
	return positionX;
}

void Entity::setPosition(int x, int y)
{
	positionX = x;
	positionY = y;
}

