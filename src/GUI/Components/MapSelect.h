#pragma once
#include "Pane.h"
#include "../../MapBuilder.h"

class MapSelect:public Pane{
	public:
		MapSelect(int x, int y, int width, int height);
		void setMaps();
private:
	std::vector<Map*> maps;
	MapComponent previousMap;
	MapComponent currentMap;
	MapComponent nextMap;

	int mapIndex = 0;

};
