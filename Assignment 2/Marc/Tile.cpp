#include "stdafx.h"
#include "Tile.h"
#include <iostream>
using namespace std;

Tile::Tile()
{
	this->coordinate = new Coordinate(0,0);
	this->entity = 'F';
}

Tile::Tile(Coordinate* coordinate, char entity)
{
	this->coordinate = coordinate;
	this->entity = entity;
}

Tile::~Tile()
{
	delete coordinate;
	coordinate = NULL;
}

void Tile::setEntity(char newEntity)
{
	entity = newEntity;
}
