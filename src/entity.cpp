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
	return distanceTo(entity->getPositionX(), entity->getPositionY());
}

int Entity::distanceTo(int x, int y) {
	return (std::abs(x - positionX) + std::abs(y - positionY));
}

double Entity::realDistanceTo(int x, int y) {
	int dx = x - positionX;
	int dy = y - positionY;
	return sqrt(dx*dx+dy*dy);
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

char Entity::getRenderChar()
{
	return renderChar;
}
int Entity::getPathfinderDistance()
{
	return pathfinderDistance;
}

void Entity::setPathfinderDistance(int distance)
{
	pathfinderDistance = distance;
}

