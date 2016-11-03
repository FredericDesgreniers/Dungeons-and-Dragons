#include "stdafx.h"
#include "Map.h"
#include <iostream>
using namespace std;

Map::Map()
{
	this->height = rand() % 10 + 5;
	this->width = rand() % 10 + 5;
}

Map::Map(int width, int height)
{
	this->height = height;
	this->width = width;
}

Map::~Map()
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

	playerCoordinate = NULL;
	exitCoordinate = NULL;
}

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

			if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
			{
				newTile->setEntity('W');
			}

			if (width <= height)
			{
				if (x == width / 2 && y == 0)
				{
					newTile->setEntity('X');
					exitCoordinate = newTile->getCoordinate();
				}

				if (x == width / 2 && y == 1)
				{
					newTile->setEntity('M');
				}

				if (x == width / 2 && y == height - 1)
				{
					newTile->setEntity('N');
				}
			}
			else
			{
				if (y == height / 2 && x == width - 1)
				{
					newTile->setEntity('X');
					exitCoordinate = newTile->getCoordinate();
				}

				if (y == height / 2 && x == width - 2)
				{
					newTile->setEntity('M');
				}

				if (y == height / 2 && x == 0)
				{
					newTile->setEntity('N');
				}
			}
			
		}
	}
	playerCoordinate = spawnPlayer();

	Notify();
}

Tile* Map::getTile(int x, int y)
{
	return tileGrid[y][x];
}

bool Map::isCompleted()
{
	return playerCoordinate == exitCoordinate;
}

bool Map::controlPlayer(char input)
{
	Tile* destinationTile = setDestinationTile(input);
	return (destinationTile != NULL) ? interactWith(destinationTile) : false;
}

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
					playerCoordinate = new Coordinate(x, y - 1);
					
				}
				else
				{
					getTile(x + 1, y)->setEntity('P');
					playerCoordinate = new Coordinate(x + 1, y);
				}
				return playerCoordinate;
			}
		}
	}
	return false;
}

void Map::movePlayer(Tile* tile)
{
	Tile* playerTile = getTile(playerCoordinate->getX(), playerCoordinate->getY());
	tile->setEntity('P');

	playerCoordinate = tile->getCoordinate();

	playerTile->setEntity('-');

	Notify();
}

void Map::attackMonster(Tile* tile)
{
	tile->setEntity('-');

	Notify();

	cout << "You kill the monster." << endl;
}

void Map::openChest(Tile* tile)
{
	tile->setEntity('O');

	Notify();

	cout << "You open the chest." << endl;
}

void Map::endMap()
{

}

