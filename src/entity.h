#pragma once
#include <valarray>
#include <math.h>
#include "Subject.h"
class Pathfinder;
class Map;

/**
 * Entity is a class to represent something that sits on a map tile like a monster, a chess, ...
 */
class Entity : public Subject
{
public:
	Entity(char renderChar);

	/**
	 * Simluate a passage in time for the entity in the context of the map
	 * pathfinder should be a path to whatever the entity is seeking, which is
	 * always the character in this case. 
	 */
	virtual void simulate(Map* map, Pathfinder* pathfinder);

	/**
	 * Gets called when another entity interacts with this entity in context of the maps
	 */
	virtual bool interact(Map* map, Entity* entity);

	/**
	 * Set entity position
	 */
	void setPosition(int x, int y);
	/**
	 * Get entity position X
	 */
	int getPositionX();
	/**
	 * Get entity position Y
	 */
	int getPositionY();
	/**
	 * get the char that should be used to render the entity on the map
	 */
	char getRenderChar();

	/**
	 * returns distance from here to other entity
	 */
	int distanceTo(Entity*  entity);

	/**
	* returns distance to point in map
	*/
	int distanceTo(int x, int y);

	/**
	* expensive distance method
	*/
	double realDistanceTo(int x, int y);

	/**
	 * Set how close the entity needs to be for pathfinding to kick in
	 */
	void setPathfinderDistance(int distance);

	/**
	 * Get maximum distance for pathfinding
	 */
	int getPathfinderDistance();
private:
	int positionX, positionY;
	char renderChar = ' ';

	int pathfinderDistance;
};
