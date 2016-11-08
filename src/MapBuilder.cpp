#include "MapBuilder.h"
#include <ctime>
#include "Monster.h"
#include <fstream>
#include <direct.h>
#include <iostream>
#include "Wizard.h"
#include "EntityChest.h"

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
		string name = fileName;

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
		builder->map = map;
		mapFile.flush();
		mapFile.close();
	}
	return builder;
}

MapBuilder* MapBuilder::loadFromFile(std::string fileName)
{
	MapBuilder* builder = new MapBuilder();
	std::fstream mapFile("maps/"+fileName+".dnd");
	if(mapFile.is_open())
	{
		int width=20, height=20;
		string name = "";
		std::string line;
		std::getline(mapFile, line);
		name = line;
		std::getline(mapFile, line);
		width = std::stoi(line);
		std::getline(mapFile, line);
		height = std::stoi(line);

		Map* map = new Map(name, width, height);
		int y = 0;
		while(std::getline(mapFile, line))
		{	
			int x = 0;
			for (int i= 0; i < line.size(); i++)
			{
				char c = line[i];
				int type;
				switch(c)
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
				case 'M':
					map->spawnEntity(new Monster(), x, y);
					break;
				case 'W':
					map->spawnEntity(new Wizard(), x, y);
					break;
				case 'B':
					map->spawnEntity(new EntityChest(), x, y);
					break;
				}

				x++;
				
			}
			y++;
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


MapBuilder* MapBuilder::spawnCharacter(Character* character)
{
	map->spawnCharacter(character);
	this->character = character;
	return this;
}
MapBuilder* MapBuilder::spawnRandomMonsters()
{
	srand(time(NULL));
	int monsternNum = rand() % 7+3;
	for (int i = 0; i < monsternNum; i++)
	{
		Monster* m = new Monster();
		int x, y;
		do
		{
			x = rand() % map->getWidth();
			y = rand() % map->getHeight();
		} while (!map->spawnEntity(m, x, y));


	}
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
			if(entity!=nullptr)
			{
				int range = rand() % 2-1;
				level += range;
				if (level < 1)
					level = 1;
				if(EntityChest* chest = dynamic_cast<EntityChest*>(entity))
				{
					
					int num = (rand()) % 5;
					for (int i = 0; i < num; i++)
					{
						Item* item = Item::generateRandomItem(level);
						chest->getContainer()->addItem(item);
						
					}
					std::cout << "CHEST RANDOM SPAWN" << num<< std::endl;
					chest->getContainer()->printContainer();
				}else if(Monster* monster = dynamic_cast<Monster*>(entity))
				{
					monster->setLevel(level);
					if(rand() % 2 == 0)
						monster->equip(Item::generateRandomItem(Item::ItemType::WEAPON));
					if(rand() % 2 == 0)
						monster->equip(Item::generateRandomItem(Item::ItemType::ARMOR));
					if(rand() % 2 == 0)
						monster->equip(Item::generateRandomItem(Item::ItemType::BELT));
					if(rand() % 2 == 0)
						monster->equip(Item::generateRandomItem(Item::ItemType::BOOTS));
					if(rand() % 2 == 0)
						monster->equip(Item::generateRandomItem(Item::ItemType::HELMET));
					if(rand() % 2 == 0)
						monster->equip(Item::generateRandomItem(Item::ItemType::RING));
					if(rand() % 2 == 0)
						monster->equip(Item::generateRandomItem(Item::ItemType::SHIELD));

				}
			}
		}
	}
	return this;
}
