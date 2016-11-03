#pragma once
#include <string>
#include <vector>
#include "Map.h"

class Campaign
{
public:
	Campaign(std::string name);

	void addMap(std::string map);
	std::vector<std::string>* getMaps();
	std::string getName();

	std::string getFirstMap();


private:
	std::vector<std::string> maps;
	std::string name;
};
