#pragma once
#include "Pane.h"
#include "../../MapBuilder.h"
/**
 * Class used to display maps form maps/ folder and select one
 */
class MapSelect:public Pane{
	public:
	/**
	 * COntructor given x,y,width,height
	 */
		MapSelect(int x, int y, int width, int height);
	/**
	 * Call to set map positions on screen
	 */
		void setMaps();
	/**
	 * Reload maps from maps/ folder
	 */
		void reloadMaps();
	/**
	 * Override render method
	 */
		virtual void render() override;
	/**
	 * Add callback for when a map is clicked
	 */
		void addOnMapClick_callback(std::function<void(Map* map)>);
private:
	std::vector<Map*> maps;
	MapComponent* previousMap;
	MapComponent* currentMap;
	MapComponent* nextMap;
	std::vector<std::function<void(Map* map)>> onMapClick_callback;
	int mapIndex = 0;

};
