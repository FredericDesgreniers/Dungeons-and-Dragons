//! @file 
//! @brief Implementation file for the Tile class  
//!
#pragma once
#include "stdafx.h"
#include "Tile.h"
#include <iostream>
using namespace std;

//! Default constructor
Tile::Tile()
{
	this->coordinate = new Coordinate(0,0);
	this->entity = '-';
}

//! Custom constructor
//! @param Coordinate* : a pointer to the coordinate associated to the tile
//! @param char : the entity contained in the tile
Tile::Tile(Coordinate* coordinate, char entity)
{
	this->coordinate = coordinate;
	this->entity = entity;
}

//! Deconstructor
Tile::~Tile()
{
	delete coordinate;
	coordinate = NULL;
}

//! Method to manually set the entity contained in a tile after the map has been generated
//! @param char : the entity to be contained in the tile
void Tile::setEntity(char newEntity)
{
	entity = newEntity;
}
