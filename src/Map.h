#pragma once

#include "map_tile.h"
#include "Entity.h"
#include <vector>
#include "GUI/Components/CharacterComponent.h"
#define TILE_EMPTY 0
#define TILE_WALL 1
#define SPAWNTILE 2
#define ENDTILE 3
#include "Pathfinder.h"

class PathFinder;
class Entity;

class Map 
{
private:
	MapTile ***tileGrid;
	Entity ***entityGrid;

	std::vector<Entity*> entities;

	Character* character;



	int spawnX = 0, spawnY = 0;

	int width;
	int height;
public:
	Map(int width, int height);

	MapTile* getTile(int x, int y);

	void setTile(MapTile* tile, int x, int y);

	Entity* getEntity(int x, int y);

	Entity* moveEntity(int x1, int y1, int x2, int y2);

	Entity* moveEntity(Entity* entity, int x, int y);

	Entity* removeEntity(int x, int y);

	bool spawnEntity(Entity* entity, int x, int y);

	bool spawnCharacter(Character* character);

	Character* getCharacter()
	{
		return character;
	}

	int getWidth()
	{
		return width;
	}
	int getHeight()
	{
		return height;
	}

	void simulateMapTick();
};