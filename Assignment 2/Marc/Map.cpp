//! @file 
//! @brief Implementation file for the Map class  
//!
#pragma once
#include "stdafx.h"
#include "Map.h"
#include <iostream>
using namespace std;

//! Default constructor
Map::Map()
{
	this->height = rand() % 10 + 5;
	this->width = rand() % 10 + 5;
}

//! Custom constructor
//! @param int : the map's width
//! @param int : the map's height
Map::Map(int width, int height)
{
	this->height = height;
	this->width = width;
}

//! Deconstructor
Map::~Map()
{
	if (tileGrid != NULL)
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				delete tileGrid[y][x];
				tileGrid[y][x] = NULL;
			}
			delete tileGrid[y];
			tileGrid[y] = NULL;
		}
		delete tileGrid;
		tileGrid = NULL;
	}

	playerCoordinate = NULL;
	exitCoordinate = NULL;
}

//! Instantiates the Tiles forming the map, puts them in a 2D array, 
//! and assigns to each one of them a coordinate and an entity according to these simple rules:
//! - A map should be surrounded by walls, except for the entrance and the exit
//! - If the map layout is vertical:
//!		- the map exit should be the located at the top center of the map
//!		- the map entrance should be the located at the bottom center of the map
//! - If the map layout is horizontal, 
//!		- the map exit should be the located at the right middle
//!		- the map entrance should be the located at the left middle of the map
//! - A monster should always block the map exit
//! - A chest should always be placed at the top right of the map
//! - The player should be spawned in front of the map entrance
void Map::generateMap()
{
	tileGrid = new Tile**[height];
	for (int y = 0; y < height; y++)
	{
		tileGrid[y] = new Tile*[width];
		for (int x = 0; x < width; x++)
		{
			Tile* newTile = new Tile(new Coordinate(x, y), '-');
			tileGrid[y][x] = newTile;

			// surrounds the map with walls
			if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
			{
				newTile->setEntity('W');
			}

			// spawns the chest
			if (x == width - 2 && y == 1)
			{
				newTile->setEntity('C');
			}

			if (width <= height)
			{
				// spawns the exit on a vertical map
				if (x == width / 2 && y == 0)
				{
					newTile->setEntity('X');
					exitCoordinate = newTile->getCoordinate();
				}
				// spawns the monster on a vertical map
				if (x == width / 2 && y == 1)
				{
					newTile->setEntity('M');
				}
				// spawns the entrance on a vertical map
				if (x == width / 2 && y == height - 1)
				{
					newTile->setEntity('N');
				}
			}
			else
			{
				// spawns the exit on a horizontal map
				if (y == height / 2 && x == width - 1)
				{
					newTile->setEntity('X');
					exitCoordinate = newTile->getCoordinate();
				}
				// spawns the monster on a horizontal map
				if (y == height / 2 && x == width - 2)
				{
					newTile->setEntity('M');
				}
				// spawns the entrance on a horizontal map
				if (y == height / 2 && x == 0)
				{
					newTile->setEntity('N');
				}
			}
			
		}
	}

	// spawns the player
	playerCoordinate = spawnPlayer();

	// notifies the map's observers of its generation
	Notify();
}

//! Accesses a specific tile on the map
//! @param int : the x coordinate of the tile
//! @param int : the y coordinate of the tile
//! @return a pointer to the tile corresponding to x and y values
Tile* Map::getTile(int x, int y)
{
	return tileGrid[y][x];
}

//! Checks if the map is completed by checking if the player is standing on top of the exit
//! @return a bool representing the completion of the map
bool Map::isCompleted()
{
	return playerCoordinate == exitCoordinate;
}

//! Makes the player character interact with one of the tile around them
//! @param char : the direction of the player's interaction or an input that signifies cancelation
//! @return a bool representing if the interaction was successful or not
bool Map::controlPlayer(char input)
{
	Tile* destinationTile = setDestinationTile(input);
	return (destinationTile != NULL) ? interactWith(destinationTile) : false;
}

//! Checks which tile will be interacted with by the player
//! @param char : the direction of the interaction or an input that signifies cancelation
//! @return a pointer to the tile with which the player will interact
Tile* Map::setDestinationTile(char input)
{
	Tile* destinationTile = NULL;
	int playerXCoordinate = playerCoordinate->getX();
	int playerYCoordinate = playerCoordinate->getY();

	switch (input)
	{
	case 'w':
		if (playerYCoordinate - 1 >= 0)
		{
			destinationTile = getTile(playerXCoordinate, playerYCoordinate - 1);
		}
		break;
	case 'd':
		if (playerXCoordinate + 1 < getWidth())
		{
			destinationTile = getTile(playerXCoordinate + 1, playerYCoordinate);
		}
		break;
	case 's':
		if (playerYCoordinate + 1 < getHeight())
		{
			destinationTile = getTile(playerXCoordinate, playerYCoordinate + 1);
		}
		break;
	case 'a':
		if (playerXCoordinate - 1 >= 0)
		{
			destinationTile = getTile(playerXCoordinate - 1, playerYCoordinate);
		}
		break;
	case 'q':
	case 'r':
		return NULL;
		break;
	}

	return destinationTile;
}

//! Execute the action of the player based on the entity of the tile that is interacted with
//! @param Tile* : a pointer to the tile to be interacted with
//! @return a bool representing if the interaction was successful or not
bool Map::interactWith(Tile* tile)
{
	switch (tile->getEntity())
	{
	case 'W':
		cout << "There is a wall blocking your way, you cannot progress" << endl;
		break;
	case '-':
		movePlayer(tile);
		cout << "You step on the tile" << endl;
		break;
	case 'N':
		cout << "This is the map entrance, you cannot go back" << endl;
		break;
	case 'X':
		movePlayer(tile);
		cout << "Congratulation, you reached the end of the map!" << endl;
		break;
	case 'M':
		attackMonster(tile);
		break;
	case 'C':
		openChest(tile);
		break;
	case 'O':
		cout << "There is a chest, it is already open." << endl;
		break;
	default:
		return false;
		break;
	}
	return true;
}

//! Spawns a player entity on a tile according to these simple rules:
//! - If the map layout is vertical:
//!		- the player should be spawned 1 tile above the entrance
//! - If the map layout is horizontal, 
//!		- the player should be spawned 1 tile to the right of the entrance
//! @return a pointer to the Coordinate of the player that was just spawned
Coordinate* Map::spawnPlayer()
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			Tile* tile = getTile(x, y);
			char entity = getTile(x, y)->getEntity();
			if (entity == 'N')
			{
				Coordinate* playerCoordinate = NULL;
				if (width <= height)
				{
					getTile(x, y - 1)->setEntity('P');
					playerCoordinate = getTile(x, y - 1)->getCoordinate();
					
				}
				else
				{
					getTile(x + 1, y)->setEntity('P');
					playerCoordinate = getTile(x + 1, y)->getCoordinate();
				}
				return playerCoordinate;
			}
		}
	}
	return false;
}

//! Moves the player to the desired tile
//! @param Tile* : a pointer to the desired tile
void Map::movePlayer(Tile* tile)
{
	Tile* playerTile = getTile(playerCoordinate->getX(), playerCoordinate->getY());
	tile->setEntity('P');

	playerCoordinate = tile->getCoordinate();

	playerTile->setEntity('-');

	// notifies the map's observers of the player's movement
	Notify();
}

//! Attacks a monster on a specific tile
//! @param Tile* : a pointer to the tile with the monster
void Map::attackMonster(Tile* tile)
{
	tile->setEntity('-');

	// notifies the map's observers of the player's action
	Notify();

	cout << "You kill the monster." << endl;
}

//! Opens a chest on a specific tile
//! @param Tile* : a pointer to the tile with the chest
void Map::openChest(Tile* tile)
{
	tile->setEntity('O');

	// notifies the map's observers of the player's action
	Notify();

	cout << "You open the chest." << endl;
}
