#include "map.h"
#include <iostream>


int main(int argc, char* argv[])
{

	Map* map = new Map(20, 20);
	map->setTile(new MapTile(1),14,12);
	map->setTile(new MapTile(1), 14, 14);
	map->setTile(new MapTile(1), 13, 13);
	map->setTile(new MapTile(1), 5,0);
	map->setTile(new MapTile(1), 6,0);
	map->setTile(new MapTile(1), 6,1);

	Pathfinder* pf = new Pathfinder(map, 14, 13);
	std::cout << std::endl;
	pf->printHGrid();
	std::vector<Node*> path = pf->getPath(0,0);
	std::cout << std::endl;
	char** dMap = new char*[map->getWidth()];
	for (int x = 0; x < map->getWidth(); x++)
	{
		dMap[x] = new char[map->getHeight()];
		for (int y = 0; y < map->getHeight(); y++)
		{
			MapTile* mp = map->getTile(x, y);
			dMap[x][y] = mp->getId()==0?' ':map->getTile(x, y)->getId()+'0';
		}
	}
	for (int i = 0; i < path.size(); i++)
	{
		Node* n = path.at(i);
		dMap[n->x][n->y] = 'p';
	}
	for (int x = 0; x < map->getWidth(); x++)
	{
		for (int y = 0; y < map->getHeight(); y++) {
			std::cout << dMap[x][y];
		}
		std::cout << std::endl;
	}

	int s;
	std::cin >> s;
}
