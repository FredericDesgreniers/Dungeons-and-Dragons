#pragma once
#include <valarray>
class Pathfinder;
class Map;
class Entity
{
public:
	Entity(char renderChar);

	virtual void simulate(Map* map, Pathfinder* pathfinder);

	virtual bool interact(Map* map, Entity* entity);

	void setPosition(int x, int y);
	int getPositionX();
	int getPositionY();

	char getRenderChar();

	int distanceTo(Entity*  entity);

private:
	int positionX, positionY;
	char renderChar = ' ';
};
