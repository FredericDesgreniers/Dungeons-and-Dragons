#include "map.h"
#include <algorithm>
#include <complex>

Map::Map(string name, int width, int height): name(name), height(height), width(width)
{
	generateMap(width, height);
}

Map::Map(int width, int height) : height(height), width(width)
{
	generateMap(width, height);
}

Map::Map(const Map &map)
{
	name = map.name;
	width = map.width;
	height = map.height;
}

std::ostream& operator<<(std::ostream &stream, const Map &map)
{
	return stream << map.name << " (" << map.width << "x" << map.height << ")";
}

void Map::generateMap(int width, int height)
{
	tileGrid = new MapTile**[width];
	for (int x = 0; x < width; x++)
	{
		tileGrid[x] = new MapTile*[height];
		for (int y = 0; y < height; y++)
		{
			tileGrid[x][y] = new MapTile(TILE_EMPTY);
		}
	}

	entityGrid = new Entity**[width];
	for (int x = 0; x < width; x++)
	{
		entityGrid[x] = new Entity*[height];
		for (int y = 0; y < height; y++)
		{
			entityGrid[x][y] = nullptr;
		}
	}
}

MapTile* Map::getTile(int x, int y)
{
	return tileGrid[x][y];
}

void Map::setTile(MapTile* tile, int x, int y)
{
	delete tileGrid[x][y];
	tileGrid[x][y] = tile;
}


Entity* Map::getEntity(int x, int y)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
		return entityGrid[x][y];
	
	return nullptr;

}

Entity* Map::moveEntity(int x1, int y1, int x2, int y2)
{
	if(x2>=0 && y2>=0 && x2<width && y2 < height)
	if(getTile(x2,y2)->getWalkable())
	if(getEntity(x1,y1) != nullptr && getEntity(x2,y2) == nullptr)
	{
		Entity* entity = entityGrid[x1][y1];
		entityGrid[x1][y1] = nullptr;
		entityGrid[x2][y2] = entity;
		entity->setPosition(x2, y2);
		return entity;
	}
	return nullptr;
}

class Entity* Map::moveEntity(class Entity* entity, int x, int y)
{
	return moveEntity(entity->getPositionX(), entity->getPositionY(), x, y);
}


Entity* Map::removeEntity(int x, int y)
{
	Entity* entity = getEntity(x,y);
	entityGrid[x][y] = nullptr;
	if(entity!=nullptr)
		for (int i = 0; i < entities.size(); i++)
		{
			if(entities[i] == entity)
			{
				entities.erase(entities.begin() + i);
				break;
			}
		}
	return entity;
}


bool Map::spawnEntity(Entity* entity, int x, int y)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return false;

	if (getEntity(x,y) != nullptr)
		return false;
	if (getTile(x, y)->getWalkable() == false)
		return false;
	entityGrid[x][y] = entity;
	entity->setPosition(x, y);
	entities.push_back(entity);
	return true;
}

void Map::simulateMapTick()
{
	vector<LivingEntity*> dead;

	ticksSinceLastSimulation++;
	if(turnQueue.size() == 0)
	{
		for (int i = 0; i < getEntities()->size(); i++)
		{
			if(LivingEntity* le = dynamic_cast<LivingEntity*>(getEntities()->at(i)))
			{
				if(le->getHealth()<=0 && !le->isPlayer())
				{
					dead.push_back(le);
				}
				else {
					le->rollInitiative();
					le->resetTurn();
					turnQueue.push(le);
				}
			}
		}
		for(LivingEntity* e:dead)
		{
			this->removeEntity(e->getPositionX(), e->getPositionY());
		}
		if(turnQueue.size() > 0)
		{
			turnQueue.top()->setTurnFinished(false);
		}
	}else if(ticksSinceLastSimulation > 5)
	{
		ticksSinceLastSimulation = 0;
		LivingEntity* le = turnQueue.top();
		
		le->doStrategy(this);

		if (le->getTurnFinished())
		{
			turnQueue.pop();
			if (turnQueue.size() > 0) {
				turnQueue.top()->setTurnFinished(false);
			}
		}
	}
}

bool Map::spawnCharacter(LivingEntity* character)
{
	this->character = character;
	character->setPlayer(true);
	character->setStrategy(new CharacterStrategy());
	for (int x = 0; x < getWidth(); x++)
	{
		for (int y = 0; y < getHeight(); y++)
		{
			if(getTile(x,y)->getId()==SPAWNTILE)
			{
				return (spawnEntity(character, x, y));
			}
		}
	}
	return false;
	
}

LivingEntity* Map::getCharacter()
{
	return character;
}

int Map::getHeight()
{
	return height;
}

int Map::getWidth()
{
	return width;
}

std::vector<Entity*>* Map::getEntities()
{
	return &entities;
}





