#include "Campaign.h"

Campaign::Campaign(std::string name, std::vector<Map*> mapList): name(name)
{
	activeMapIndex = 0;
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

void Campaign::setActiveMapIndex(int index)
{
	activeMapIndex = index;
}

int Campaign::getMapCount()
{
	int count = 0;
	for each(Map* map in maps)
	{
		count++;
	}
	return count;
}

std::string Campaign::getName()
{
	return name;
}

void Campaign::setName(std::string newName)
{
	name = newName;
}

void Campaign::saveCampaign(Campaign* campaign)
{
	std::ofstream mapFile("campaigns/" + campaign->getName() + ".cam");

	if (mapFile.is_open())
	{
		mapFile << campaign->getName() << std::endl;

		for each (Map* map in campaign->getMaps())
		{
			mapFile << map->getName() << std::endl;
		}

		mapFile.flush();
		mapFile.close();
	}
}

Campaign* Campaign::loadCampaign(std::string fileName)
{
	std::fstream campaignFile("campaigns/" + fileName + ".cam");

	Campaign* campaign = new Campaign(fileName, std::vector<Map*>());

	if (campaignFile.is_open())
	{
		string name = "";
		std::string line;
		std::getline(campaignFile, line);
		name = line;

		while (std::getline(campaignFile, line))
		{
			Map* tempMap = MapBuilder::loadFromFile(line)->get();
			campaign->addMap(tempMap);
		}

		if (campaign->getMapCount() == 0)
		{
		}

		campaignFile.close();
	}

	return campaign;
}

