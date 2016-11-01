#pragma once
#include "Style.h"
#include "Map.h"

class MapComponent : public Style {
public:
	MapComponent(Map* map, int x, int y, int width, int height);
	void render() override;
	void tick() override;
	void renderDebug() override;
	void setPreviewMode(bool previewMode) {
		this->previewMode = previewMode;
	}

	void click(int x, int y) override;

	void addOnTileClickedCallback(std::function<void(Map*, int, int)> func)
	{
		onTileClick_callbacks.push_back(func);
	}

private:
	Map* map;
	bool previewMode;

	std::vector<std::function<void(Map*, int, int)>> onTileClick_callbacks;
};