#include "map_tile.h"
#include <iostream>

MapTile::MapTile(int id)
{
	this->id = id;
	walkable = id > 0 ? false : true;
	if(id > 0)
	{
		std::cout << "HYE";
	}

}
