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

	/**
	 * Remove map from campaign
	 */
	void removeMap(Map* map);

	/**
	 * Get the number of maps currently in the campaign
	 */
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
	/**
	 * Load campaign from file
	 */
	static Campaign* loadCampaign(std::string fileName);
	/**
	 * Save campaign to file
	 */
	static void saveCampaign(Campaign* campaign);
	/**
	 * Get current active map index
	 */
	int getActiveMapIndex() { return activeMapIndex; }
	/**
	 * Set active map index
	 */
	void setActiveMapIndex(int index);
	/**
	 * Is compaign completed? 
	 */
	bool isCompleted() { return activeMapIndex >= getMapCount(); }

private:
	/**
	 * Map list
	 */
	std::vector<Map*> maps;
	/**
	 * camapaign name
	 */
	std::string name;
	/**
	 * Current map index
	 */
	int activeMapIndex;
};
