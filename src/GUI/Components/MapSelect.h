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
		 * Constructor with already made map list
		 */
		MapSelect(std::vector<Map*> mapList, int x, int y, int width, int height);

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
		void loadMaps(std::vector<Map*> mapList);
		void addOnMapClick_callback(std::function<void(Map* map)>);
private:
	/**
	 * List of maps
	 */
	std::vector<Map*> maps;
	/**
	 * Map component for previous map
	 */
	MapComponent* previousMap;
	/**
	 * Map component for current map
	 */
	MapComponent* currentMap;
	/**
	 * Map component for next map
	 */
	MapComponent* nextMap;
	/**
	 * List of callback functions for maps
	 */
	std::vector<std::function<void(Map* map)>> onMapClick_callback;
	/**
	 * CUrrent map index
	 */
	int mapIndex = 0;

};
