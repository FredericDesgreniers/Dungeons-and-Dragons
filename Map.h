#pragma once

#include "map_tile.h"
#include "entity.h"
#define TILE_EMPTY 0
#define TILE_WALL 1
class Map 
{
private:
	MapTile ***tileGrid;
	Entity ***entityGrid;

	int width;
	int height;
public:
	Map(int width, int height);

	MapTile* getTile(int x, int y);

	void setTile(MapTile* tile, int x, int y);

	Entity* getEntity(int x, int y);

	Entity* moveEntity(int x1, int y1, int x2, int y2);

	Entity* removeEntity(int x, int y);

	bool spawnEntity(Entity* entity, int x, int y);

	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}


};