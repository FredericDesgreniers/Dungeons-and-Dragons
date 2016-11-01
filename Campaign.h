#pragma once
#include <string>
#include <vector>
#include "Map.h"

class Campaign
{
public:
	Campaign(std::string name);

	void addMap(Map* map)
	{
		maps.push_back(map);
	}	
	std::vector<Map*>* getMaps()
	{
		return &maps;
	}
	std::string getName()
	{
		return name;
	}



private:
	std::vector<Map*> maps;
	std::string name;
};
