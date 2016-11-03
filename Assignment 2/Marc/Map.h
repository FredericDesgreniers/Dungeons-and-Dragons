//! @file 
//! @brief Header file for the Map class.
//!
#pragma once
#include "Tile.h"
#include "Subject.h"

//! class that represents a concrete observable Map, its attributes, and its behaviors
class Map : public Subject
{

private:

	Tile ***tileGrid;
	Coordinate* playerCoordinate;
	Coordinate* exitCoordinate;

	int width;
	int height;

	Coordinate* spawnPlayer();
	Tile* setDestinationTile(char input);

	bool interactWith(Tile* tile);
	void attackMonster(Tile* tile);
	void openChest(Tile* tile);

public:

	Map();
	Map(int width, int height);
	~Map();

	void generateMap();

	Tile* getTile(int x, int y);

	int getWidth() { return width; }
	int getHeight() { return height; } 

	bool isCompleted();
	bool controlPlayer(char input);
	void movePlayer(Tile* tile);
	
	Coordinate* getPlayerCoordinate() { return playerCoordinate; }

};