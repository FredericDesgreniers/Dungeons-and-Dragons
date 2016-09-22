#include "map.h"

Map::Map(int width, int height): height(height), width(width)
{
	tileGrid = new MapTile**[width];
	for (int x = 0; x < width; x++)
	{
		tileGrid[x] = new MapTile*[height];
		for (int y = 0; y < height; y++)
		{
			tileGrid[x][y] = new MapTile(TILE_EMPTY);
		}
	}

	entityGrid = new Entity**[width];
	for (int x = 0; x < width; x++)
	{
		entityGrid[x] = new Entity*[height];
		for (int y = 0; y < height; y++)
		{
			entityGrid[x][y] = nullptr;
		}
	}
}

MapTile* Map::getTile(int x, int y)
{
	return tileGrid[x][y];
}

void Map::setTile(MapTile* tile, int x, int y)
{
	delete tileGrid[x][y];
	tileGrid[x][y] = tile;
}


Entity* Map::getEntity(int x, int y)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
		return entityGrid[x][y];
	
	return nullptr;

}

Entity* Map::moveEntity(int x1, int y1, int x2, int y2)
{
	if(getTile(x2,y2)->getWalkable())
	if(getEntity(x1,y1) != nullptr && getEntity(x2,y2) == nullptr)
	{
		Entity* entity = entityGrid[x1][y1];
		entityGrid[x1][y1] = nullptr;
		entityGrid[x2][y2] = entity;
		return entity;
	}
	return nullptr;
}

Entity* Map::removeEntity(int x, int y)
{
	Entity* entity = getEntity(x,y);
	entityGrid[x][y] = nullptr;
	return entity;
}


bool Map::spawnEntity(Entity* entity, int x, int y)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return false;

	if (getEntity(x,y) != nullptr)
		return false;

	entityGrid[x][y] = entity;
	return true;
}
