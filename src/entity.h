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

	void setPosition(int x, int y)
	{
		positionX = x;
		positionY = y;
	}
	int getPositionX()
	{
		return positionX;
	}
	int getPositionY()
	{
		return positionY;
	}

	char getRenderChar()
	{
		return renderChar;
	}

	int distanceTo(Entity*  entity)
	{
		return (std::abs(entity->getPositionX() - positionX) + std::abs(entity->getPositionY() - positionY));
	}

private:
	int positionX, positionY;
	char renderChar = ' ';
};
