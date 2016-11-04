#pragma once
#include "Style.h"
#include "../../Map.h"
/**
 * Component used to display a map
 */
class MapComponent : public Style {
public:
	/**
	 * Call with to display, the position and the dimensions
	 */
	MapComponent(Map* map, int x, int y, int width, int height);
	/**
	 * Used to render the map
	 */
	void render() override;
	void renderEmpty();
	void tick() override;
	void renderDebug() override;
	/**
	 * Sets preview mode
	 * 
	 * if preview mode is false, the map will change colors on hover
	 */
	void setPreviewMode(bool previewMode);

	/**
	 * Called when map is clicked
	 */
	void click(int x, int y) override;
	/**
	* Set the draw distance
	*/
	void setDrawDistance(double d);

	/**
	 * Add callback function for when a tile is clicked
	 * Callback function should accept Map object, positionX and positionY ints
	 */
	void addOnTileClickedCallback(std::function<void(Map*, int, int)> func);
private:
	Map* map;
	bool previewMode;
	double drawDistance = 5;
	std::vector<std::function<void(Map*, int, int)>> onTileClick_callbacks;
};