#include "MapComponent.h"
#include "Renderer.h"


MapComponent::MapComponent(Map* map, int x, int y, int width, int height):map(map), Style(x,y,width,height) {

}

void MapComponent::render() {
	int mapWidth = map->getWidth();
	int mapHeight = map->getHeight();

	int tileWidth = getWidth() / mapWidth;
	int tileHeight = getHeight() / mapHeight;
	int mx, my;
	SDL_GetMouseState(&mx, &my);


	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapHeight; j++) {
			int x= i*tileWidth + getPositionX();
			int y = j*tileHeight + getPositionY();

			bool hover = mx > x && mx < x + tileWidth && my>y && my < y + tileHeight;
			if (hover)
				Renderer::setColor(255, 255, 255, 255);
			else
				Renderer::setColor(200,200,200,255);
			Renderer::RenderRect(x, y, tileWidth, tileHeight);

			Renderer::setColor(100, 100, 100, 255);
			Renderer::RenderRectOutline(x,y,tileWidth,tileHeight);
			

		}
	}
}

void MapComponent::tick() {

}

void MapComponent::renderDebug() {

}
