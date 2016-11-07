#pragma once
#include <string>
#include <vector>
#include "Map.h"

/**
 * A campaign is a series of Maps that are to be played in order
 */
class Campaign
{
public:
	Campaign(std::string name);

	/**
	 * Add a map to the end of the campaign
	 */
	void addMap(std::string map);

	/**
	 * Add map instance to camapign
	 */
	void addMap(Map* map);

	/**
	 * Get the list of maps in playable order
	 */
	std::vector<std::string>* getMaps();

	/**
	 * Get campaign name
	 */
	std::string getName();

	/**
	 * Get the first map
	 */
	std::string getFirstMap();


private:
	std::vector<std::string> maps;
	std::string name;
};
