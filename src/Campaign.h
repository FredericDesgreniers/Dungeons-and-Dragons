#pragma once
#include <string>
#include <vector>
#include "Map.h"

class Campaign
{
public:
	Campaign(std::string name);

	void addMap(std::string map)
	{
		maps.push_back(map);
	}	
	std::vector<std::string>* getMaps()
	{
		return &maps;
	}
	std::string getName()
	{
		return name;
	}

	std::string getFirstMap();


private:
	std::vector<std::string> maps;
	std::string name;
};
