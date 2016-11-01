#pragma once
#include "Style.h"
#include "Map.h"

class MapComponent : public Style {
public:
	MapComponent(Map* map, int x, int y, int width, int height);
	void render() override;
	void tick() override;
	void renderDebug() override;

private:
	Map* map;
};