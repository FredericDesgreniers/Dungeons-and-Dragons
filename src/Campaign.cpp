#include "Campaign.h"

Campaign::Campaign(std::string name, std::vector<Map*> mapList): name(name)
{
	this->maps = mapList;
}

Map* Campaign::getFirstMap()
{
	if (maps.size() > 0)
		return maps[0];
	else
		return nullptr;
}

void Campaign::addMap(Map* map)
{
	maps.push_back(map);
}

void Campaign::removeMap(Map* map)
{
	
}

std::string Campaign::getName()
{
	return name;
}

