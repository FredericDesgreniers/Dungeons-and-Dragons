#include "MapComponent.h"
#include "../Renderer.h"
#include "CharacterComponent.h"


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

			bool hover;
			if (previewMode)
				hover = false;
			else
				hover = mx > x && mx < x + tileWidth && my>y && my < y + tileHeight;

			MapTile* tile = map->getTile(i, j);

			switch(tile->getId())
			{
			case TILE_WALL:
				Renderer::setColor(20, 20, 20, 255);
				break;
			case TILE_EMPTY:
				Renderer::setColor(150, 150, 150, 255);
				break;
			case SPAWNTILE:
				Renderer::setColor(0, 255, 0, 255);
				break;
			case ENDTILE:
				Renderer::setColor(255, 0, 0, 255);
			}

			Renderer::RenderRect(x, y, tileWidth, tileHeight);

			Renderer::setColor(10, 10, 10, 255);
			Renderer::RenderRectOutline(x,y,tileWidth,tileHeight);

			Entity* entity = map->getEntity(i,j);
			if (entity != nullptr)
			{
				Renderer::drawString(std::string(1, entity->getRenderChar()), Renderer::FONT_ROBOTO.get(tileHeight), x, y,1,{255,255, 0,255});
			}
			

		}
	}
}

void MapComponent::tick() {

}

void MapComponent::renderDebug() {
	Style::renderDebug();
}


void MapComponent::click(int x, int y)
{
	int mapWidth = map->getWidth();
	int mapHeight = map->getHeight();

	int tileWidth = getWidth() / mapWidth;
	int tileHeight = getHeight() / mapHeight;

	int tileX = x / tileWidth;
	int tileY = y / tileHeight;

	if (tileX >= 0 && tileY >= 0 && tileX < mapWidth && tileY < mapHeight) {

		for (int i = 0; i < onTileClick_callbacks.size(); i++)
		{
			onTileClick_callbacks[i](map, tileX, tileY);
		}
	}

	Style::click(x,y);
}
