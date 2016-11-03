#include "MapComponent.h"
#include "../Renderer.h"
#include "CharacterComponent.h"
#include "../../Monster.h"

MapComponent::MapComponent(Map* map, int x, int y, int width, int height):map(map), Style(x,y,width,height) {

}

void MapComponent::render() {
	int mapWidth = map->getWidth();
	int mapHeight = map->getHeight();

	int tileWidth = getWidth() / mapWidth;
	int tileHeight = getHeight() / mapHeight;
	int mx, my;
	SDL_GetMouseState(&mx, &my);
	Character* c = map->getCharacter();

	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapHeight; j++) {
			int distance = c->realDistanceTo(i,j);
			if (distance > drawDistance) {
				continue;
			}
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

				SDL_Color color;
				if (dynamic_cast<Monster*>(entity)) {
					color = { 255,200,0,255 };
				}
				else if (dynamic_cast<Character*>(entity)) {
					color = { 255,255,0,255 };
				}
				else {
					color = { 255,0,255,255 };
				}
				

				Renderer::drawString(std::string(1, entity->getRenderChar()), Renderer::FONT_ROBOTO.get(tileHeight), x+2, y-3,1,color);
				if(LivingEntity* le = dynamic_cast<LivingEntity*>(entity)){
					Renderer::setColor(255, 0, 0, 255);
					double healthBar = (static_cast<double>(le->getHealth()) / static_cast<double>(le->getMaxHealth()));
					
					Renderer::RenderRect(x, y, healthBar*(tileWidth-2)+2,5);
				}
			}
			

		}
	}
}

void MapComponent::tick() {

}

void MapComponent::renderDebug() {
	Style::renderDebug();
}

void MapComponent::addOnTileClickedCallback(std::function<void(Map*, int, int)> func)
{
	onTileClick_callbacks.push_back(func);
}

void MapComponent::setPreviewMode(bool previewMode)
{
	this->previewMode = previewMode;
}

void MapComponent::setDrawDistance(double d) {
	drawDistance = d;
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
