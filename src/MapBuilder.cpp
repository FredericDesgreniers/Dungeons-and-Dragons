#include "MapBuilder.h"
#include <ctime>
#include "Monster.h"
#include <fstream>
#include <direct.h>
#include <iostream>
#include "EntityChest.h"
#include "Wizard.h"


MapBuilder* MapBuilder::createEmptyMap(int w, int h)
{
	MapBuilder* builder = new MapBuilder();
	builder->map = new Map(w, h);
	return builder;
}
MapBuilder* MapBuilder::loadMap(Map* map)
{
	MapBuilder* builder = new MapBuilder();
	builder->map = map;
	return builder;
}

MapBuilder* MapBuilder::saveToFile(std::string fileName, Map* map)
{
	MapBuilder* builder = new MapBuilder();
	std::ofstream mapFile("maps/" + fileName + ".dnd");

	if (mapFile.is_open())
	{
		int width = map->getWidth();
		int height = map->getHeight();
		std::string name = fileName;

		mapFile << name << std::endl;
		mapFile << width << std::endl;
		mapFile << height << std::endl;

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				int type = map->getTile(x, y)->getId();

				switch (type)
				{
				case 0:
					mapFile << '-';
					break;
				case 1:
					mapFile << 'W';
					break;
				case 2:
					mapFile << 'S';
					break;
				case 3:
					mapFile << 'E';
					break;
				default:
					mapFile << ' ';
					break;
				}

				Entity* entity = map->getEntity(x, y);

				if (entity != nullptr)
				{
					mapFile << entity->getRenderChar();
				}
				else
				{
					mapFile << '\'';
				}
			}
			mapFile << std::endl;
		}

		for each(std::string item in map->itemList)
		{
			mapFile << item << std::endl;
		}

		builder->map = map;
		mapFile.flush();
		mapFile.close();
	}
	return builder;
}

MapBuilder* MapBuilder::loadFromFile(std::string fileName)
{
	MapBuilder* builder = new MapBuilder();
	std::fstream mapFile("maps/" + fileName + ".dnd");
	if (mapFile.is_open())
	{
		int width = 20, height = 20;
		std::string name = "";
		std::string line;
		std::getline(mapFile, line);
		name = line;
		std::getline(mapFile, line);
		width = std::stoi(line);
		std::getline(mapFile, line);
		height = std::stoi(line);

		Map* map = new Map(name, width, height);
		int y = 0;

		while (y < height)
		{
			std::getline(mapFile, line);

			int x = 0;
			for (int i = 0; i < line.size(); i++)
			{
				char c = line[i];
				int type;
				switch (c)
				{
				case 'W':
					type = TILE_WALL;
					break;
				case 'S':
					type = SPAWNTILE;
					break;
				case 'E':
					type = ENDTILE;
					break;
				default:
					type = TILE_EMPTY;

				}
				if (x >= 0 && x < width && y >= 0 && y < height)
					map->setTile(new MapTile(type), x, y);
				i++;
				c = line[i];

				switch (c)
				{
				case 'F':
				{
					LivingEntity* fe = new LivingEntity('F');
					fe->setHostile(false);
					fe->setStrategy(new FriendlyStrategy());
					fe->setDisplayColor(255, 255, 0, 255);
					fe->setPathfinderDistance(8);
					map->spawnEntity(fe, x, y);
				}
				break;
				case 'H':
				{
					LivingEntity* he = new LivingEntity('H');
					he->setHostile(true);
					he->setStrategy(new HostileStrategy());
					he->setDisplayColor(255, 0, 255, 255);
					he->setPathfinderDistance(8);
					map->spawnEntity(he, x, y);
				}
				break;
				case 'B':
				{
					EntityChest* ce = new EntityChest();
					ce->setDisplayColor(0, 255, 255, 255);
					map->spawnEntity(ce, x, y);
				}
				break;
				}

				x++;

			}
			y++;
		}
		while (std::getline(mapFile, line))
		{
			int x;
			int y;
			std::stringstream ss(line);
			ss >> x >> y;

			string itemName;
			while (ss >> itemName) {
				((EntityChest*)map->getEntity(x, y))->getContainer()->addItem(Item::loadItem(itemName));
			}
		}

		
		builder->map = map;
		mapFile.close();
	}
	return builder;
}


MapBuilder::MapBuilder()
{

}
Map* MapBuilder::get()
{
	return map;
}


MapBuilder* MapBuilder::spawnCharacter(LivingEntity* character)
{
	map->spawnCharacter(character);
	this->character = character;
	return this;
}

int MapBuilder::getMapLevel()
{
	if (character == nullptr)
		return 1;
	else
		return character->getLevel();
}

MapBuilder* MapBuilder::spawnScaledContent()
{


	int level = character == nullptr ? 1 : character->getLevel();
	for (int x = 0; x < map->getWidth(); x++)
	{
		for (int y = 0; y < map->getHeight(); y++)
		{

			Entity* entity = map->getEntity(x, y);
			if (entity != nullptr)
			{
				int range = rand() % 2 - 1;
				level += range;
				if (level < 1)
					level = 1;

				if(LivingEntity* monster = dynamic_cast<LivingEntity*>(entity))
				{
					monster->setLevel(level);

				}else if(EntityChest* chest = dynamic_cast<EntityChest*>(entity))
				{
					ItemContainer* ic = chest->getContainer();
					for (int i = 0; i < ic->getSize(); i++)
					{
						Item* item = ic->getItemAtIndex(i);
						//TODO scale items
					}
				}
			}
		}
	}
	return this;
}