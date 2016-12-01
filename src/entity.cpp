#include "entity.h"
#include "Pathfinder.h"
Entity::Entity(char renderChar):renderChar(renderChar)
{
	color = { 255,0,255,255 };
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

void Entity::setRenderChar(char letter)
{
	renderChar = letter;;
}

int Entity::getPathfinderDistance()
{
	return pathfinderDistance;
}

void Entity::setPathfinderDistance(int distance)
{
	pathfinderDistance = distance;
}

SDL_Color Entity::getDisplayColor()
{
	return color;
}

void Entity::setDisplayColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	color = { r,g,b,a };
}
