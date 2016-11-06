#pragma once
#include "Pane.h"
#include "../../MapBuilder.h"

class MapSelect:public Pane{
	public:
		MapSelect(int x, int y, int width, int height);
		void setMaps();

		void addOnMapClick_callback(std::function<void(Map* map)>);
private:
	std::vector<Map*> maps;
	MapComponent* previousMap;
	MapComponent* currentMap;
	MapComponent* nextMap;
	std::vector<std::function<void(Map* map)>> onMapClick_callback;
	int mapIndex = 0;

};
