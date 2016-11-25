#include "map_tile.h"
#include <iostream>
#include "Map.h"

MapTile::MapTile(int id)
{
	this->id = id;
	walkable = id != TILE_WALL;

}

int MapTile::getId()
{
	return id;
}
int MapTile::getMovementCost()
{
	return movementCost;
}

bool MapTile::getWalkable()
{
	return walkable;
}

void MapTile::setId(int id)
{
	this->id = id;
}

void MapTile::setWalkable(bool walkable)
{
	this->walkable = walkable;
}




