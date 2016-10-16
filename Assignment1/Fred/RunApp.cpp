#include "map.h"
#include <iostream>


int main(int argc, char* argv[])
{

	Map* map = new Map(20, 20);
	map->setTile(new MapTile(1),14,12);
	map->setTile(new MapTile(1), 14, 14);
	map->setTile(new MapTile(1), 13, 13);

	Pathfinder* pf = new Pathfinder(map, 14, 13);
	
	pf->getPath(0,0);

	int s;
	std::cin >> s;
}
