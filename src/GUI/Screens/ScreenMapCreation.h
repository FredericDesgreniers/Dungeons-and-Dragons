#pragma once
#include "Screen.h"
#include "screenMain.h"
#include "../../map.h"
#include "../../MapBuilder.h"
#include <sstream>
#include "../Components/TextField.h"
#include "../Renderer.h"
#include "../../dice.h"
#include "../Components/MapComponent.h"
#include <string>
#include "../Components/MapSelect.h"

/**
 * Screen to display map creator
 */
class ScreenMapCreation : public Screen
{

private:

	Map* map;
	Map* tileMap;
	Map* entityMap;
	TextField* nameInput;

	MapTile* storedTile;
	Entity* storedEntity;
	std::string storedItem;
	std::string storedCharacter;

	int height;
	int width;

public:
	/**
	 * Constructor to initialize screen given a game instance
	 */
	ScreenMapCreation(Game* game);

	/**
	 * Map display component for map that is going to be edited
	 */
	MapComponent* mapComp;
	/**
	 * Map display component for the tiles
	 */
	MapComponent* tileMapComp;
	/**
	 * Map display component for the entities
	 */
	MapComponent* entityMapComp;
	/**
	 * Component used to select a map to edit from saved maps
	 */
	MapSelect* mapSelect;

	/**
	 * Override screen render method
	 */
	void render() override;
	/**
	 * Create a map given the dimensions. 
	 */
	void createMap();
	/**
	 * Save map currently open in editor
	 */
	void saveMap();
	/**
	 * Validate the currently editing map
	 */
	bool validateMap();
	/**
	 * Set the map to edit
	 */
	void setMap(Map* map);
	/**
	 * Set editable map height
	 */
	void setHeight(int value);
	/**
	 * Set editable map width
	 */
	void setWidth(int value);

};
