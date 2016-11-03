#pragma once

#include "GUI/Components/MapComponent.h"
#include "GUI/Components/CharacterComponent.h"


class MapBuilder
{
public:
	static MapBuilder* createEmptyMap(int width, int height);
	static MapBuilder* loadMap(Map* map);
	static MapBuilder* loadFromFile(std::string fileName);
	MapBuilder* spawnCharacter(Character* character);
	
	MapBuilder* spawnRandomMonsters();
	
	Map* get()
	{
		return map;
	}


private:
	int getMapLevel();

	MapBuilder();
	Map* map;
	Character* character;
};
