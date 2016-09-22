#include "map.h"
#include "iostream"


static void printMap(Map* map)
{
	for (int i = 0; i < map->getWidth(); i++)
	{
		for (int j = 0; j < map->getHeight(); j++)
		{
			MapTile* tile = map->getTile(i, j);
			Entity* entity = map->getEntity(i, j);

			std::cout << i<<","<<j << ": " << tile->getId() << "/" << (entity == nullptr) << "  ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	Map map(10, 10);
	printMap(&map);

	map.spawnEntity(new Entity(), 1, 4);
	map.setTile(new MapTile(2),5 , 4);

	std::cout << "------------------------" << std::endl;
	printMap(&map);

	std::cin.get();
}
