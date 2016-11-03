#pragma once
#include "stdafx.h"
#include "Coordinate.h"

Coordinate::Coordinate()
{
	x = 0;
	y = 0;
}

Coordinate::Coordinate(int xValue, int yValue)
{
	x = xValue;
	y = yValue;
}

Coordinate::Coordinate(const Coordinate &newCoord)
{
	x = newCoord.x;
	y = newCoord.y;
}

std::ostream& operator<<(std::ostream &os, const Coordinate &coord)
{
	return os << "(" << coord.x << ',' << coord.y << ")";
}
