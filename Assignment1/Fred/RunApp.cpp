#include "map.h"
#include <iostream>
#include "string"


int main(int argc, char* argv[])
{

	Map* map = new Map(50,50);

	map->setTile(new MapTile(1),14,12);
	map->setTile(new MapTile(1), 14, 14);
	map->setTile(new MapTile(1), 13, 13);
	map->setTile(new MapTile(1), 5,0);
	map->setTile(new MapTile(1), 6,0);
	map->setTile(new MapTile(1), 6,1);

	for (int i = 19; i > 3; i--)
	{
		map->setTile(new MapTile(1), i, 7);
	}for (int i = 0; i < 16; i++)
	{
		map->setTile(new MapTile(1), i, 3);
	}
	for (int i = 34; i > -1; i--)
	{
		if(i!=12)
		map->setTile(new MapTile(1), i, 34);
	}for (int i = 3; i < 50; i++)
	{
		map->setTile(new MapTile(1), i, 45);
	}

	Pathfinder* pf = new Pathfinder(map, 0, 0);
	std::cout << std::endl;
	pf->printHGrid();
	std::vector<Node*> path = pf->getPath(49,49);
	std::cout << std::endl;
	for (int i = 0; i < 2; i++)
	{
		char** dMap = new char*[map->getWidth()];
		for (int x = 0; x < map->getWidth(); x++)
		{
			dMap[x] = new char[map->getHeight()];
			for (int y = 0; y < map->getHeight(); y++)
			{
				MapTile* mp = map->getTile(x, y);
				dMap[x][y] = mp->getId() == 0 ? ' ' : 'W';
			}
		}
		dMap[14][13] = 'E';
		dMap[0][0] = 'S';
		if(i==1){
			for (int i = 0; i < path.size(); i++)
			{
				Node* n = path.at(i);
				dMap[n->x][n->y] = 'p';
			}
		}
		std::cout << std::string(3, ' ');
		for (int x = 0; x < map->getWidth(); x++)
		{
			printf("%3d", x);
		}
		std::cout << std::endl << std::string(map->getWidth() * 3 + 4, '-') << std::endl;

		for (int y = 0; y < map->getHeight(); y++) {
			printf("%2d |", y);


			for (int x = 0; x < map->getWidth(); x++)
			{
				std::cout << ' ' << dMap[x][y] << ' ';
			}
			std::cout << '|' << std::endl;
		}
		for (int x = 0; x < map->getWidth(); x++)
		{
			delete dMap[x];
		}
		delete dMap;
		std::cout << std::string(map->getWidth() * 3 + 4, '-') << std::endl;
	}
	int s;
	std::cin >> s;

	
}
