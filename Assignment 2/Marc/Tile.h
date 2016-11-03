#pragma once
#include "Coordinate.h"

class Tile
{

private:

	Coordinate *coordinate;
	char entity;

public:

	Tile();
	Tile(Coordinate *coordinate, char entity);
	~Tile();

	Coordinate* getCoordinate() { return coordinate; }
	int getXCoordinate() { return coordinate->getX(); }
	int getYCoordinate() { return coordinate->getY(); }
	char getEntity() { return entity; }
	
	void setEntity(char newEntity);

};