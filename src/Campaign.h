#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include "Map.h"
#include "MapBuilder.h"

/**
 * A campaign is a series of Maps that are to be played in order
 */
class Campaign
{
public:
	Campaign(std::string name, std::vector<Map*> mapList);

	/**
	 * Add a map to the end of the campaign
	 */
	void addMap(Map* map);

	
	void removeMap(Map* map);

	int getMapCount();

	/**
	 * Get the list of maps in playable order
	 */
	std::vector<Map*> getMaps() { return maps; }

	/**
	 * Get campaign name
	 */
	std::string getName();

	void setName(std::string newName);

	/**
	 * Get the first map
	 */
	Map* getFirstMap();

	static Campaign* loadCampaign(std::string fileName);
	static void saveCampaign(Campaign* campaign);

	int getActiveMapIndex() { return activeMapIndex; }
	void setActiveMapIndex(int index);

	bool isCompleted() { return activeMapIndex >= getMapCount(); }

private:
	std::vector<Map*> maps;
	std::string name;

	int activeMapIndex;
};
