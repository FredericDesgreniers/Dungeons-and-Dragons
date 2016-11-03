//! @file 
//! @brief Header file for the Tile class.
//!
#pragma once
#include "Coordinate.h"

//! class that represents a single Tile on a Map and its attributes, namely its coordinates and the entity it contains
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