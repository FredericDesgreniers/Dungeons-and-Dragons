//! @file 
//! @brief Implementation file for the Coordinate class  
//!
#pragma once
#include "stdafx.h"
#include "Coordinate.h"

//! Default constructor
Coordinate::Coordinate()
{
	x = 0;
	y = 0;
}

//! Custom constructor
//! @param int : the x value of the coordinate
//! @param int : the y value of the coordinate
Coordinate::Coordinate(int xValue, int yValue)
{
	x = xValue;
	y = yValue;
}

//! Copy constructor
//! @param Coordinate : the source coordinate to be copied
Coordinate::Coordinate(const Coordinate &coord)
{
	x = coord.x;
	y = coord.y;
}

//! << operator overload
//! @param ostream : the address of the output stream
//! @param Coordinate : the address of the coordinate to be printed
std::ostream& operator<<(std::ostream &stream, const Coordinate &coord)
{
	return stream << "(" << coord.x << ',' << coord.y << ")";
}
