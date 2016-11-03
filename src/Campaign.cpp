#include "Campaign.h"

Campaign::Campaign(std::string name): name(name)
{
	
}


std::string Campaign::getFirstMap()
{
	if (maps.size() > 0)
		return maps[0];
	else
		return "default";
}

void Campaign::addMap(std::string map)
{
	maps.push_back(map);
}


std::vector<std::string>* Campaign::getMaps()
{
	return &maps;
}

std::string Campaign::getName()
{
	return name;
}

