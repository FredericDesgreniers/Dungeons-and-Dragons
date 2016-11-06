#include "MapComponent.h"
#include "../Renderer.h"
#include "CharacterComponent.h"
#include "../../Monster.h"
#include "../../Wizard.h"

MapComponent::MapComponent(Map* map, int x, int y, int width, int height):map(map), Style(x,y,width,height) {

}

void MapComponent::setMap(Map* map)
{
	this->map = map;
}

void MapComponent::render() {
	drawDefaultStyle();
	if (map == nullptr)
		return;
	int mapWidth = map->getWidth();
	int mapHeight = map->getHeight();
	//calculate tile width
	int tileWidth = getWidth() / mapWidth;
	int tileHeight = getHeight() / mapHeight;

	//get mosue position
	int mx, my;
	SDL_GetMouseState(&mx, &my);

	//get character from maps
	Character* c = map->getCharacter();

	//go through map tiles
	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapHeight; j++) {

			if (c != nullptr)
			{
				//get distance from character to tile
				int distance = c->realDistanceTo(i, j);
				if (distance > drawDistance) {//determine if tile is close enough for render
					continue;
				}
			}
			
			// calculate x and y position relative to screen
			int x= i*tileWidth + getPositionX();
			int y = j*tileHeight + getPositionY();

			//is mouse hovering a tile?
			bool hover;
			if (previewMode)
				hover = false;
			else
			{
				hover = mx > x && mx < x + tileWidth && my>y && my < y + tileHeight;
			}
				
			MapTile* tile = map->getTile(i, j);
			/**
			 * Set color depending on tile ID
			 */
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
			//Render tile
			Renderer::RenderRect(x, y, tileWidth, tileHeight);

			// render tile outline
			if (hover)
			{
				Renderer::setColor(255, 255, 255, 255);
			}
			else
			{
				Renderer::setColor(10, 10, 10, 255);
			}
			
			Renderer::RenderRectOutline(x,y,tileWidth,tileHeight);

			//get entity at tile location
			Entity* entity = map->getEntity(i,j);
			if (entity != nullptr)
			{

				SDL_Color color;
				//set Entity car chracter dependin on type of entity
				if (dynamic_cast<Monster*>(entity)) {
					if(dynamic_cast<Wizard*>(entity)) 
					{
						color = { 0,0,255,255 };
					}else{
						color = { 255,200,0,255  }; 

					}
				}
				else if (dynamic_cast<Character*>(entity)) {
					color = { 255,255,0,255 };
				}
				else {
					color = { 255,0,255,255 };
				}
				
				//render entity chracter
				Renderer::drawString(std::string(1, entity->getRenderChar()), Renderer::FONT_ROBOTO.get(tileHeight), x+2, y-3,1,color);
				//if entity is living, render health bar
				if(LivingEntity* le = dynamic_cast<LivingEntity*>(entity)){
					Renderer::setColor(255, 0, 0, 255);
					double healthBar = (static_cast<double>(le->getHealth()) / static_cast<double>(le->getMaxHealth()));
					
					Renderer::RenderRect(x, y, healthBar*(tileWidth-2)+2,5);
					Renderer::setColor(0, 0, 0, 255);
					Renderer::RenderRectOutline(x,y,tileWidth,5);
				
				}
			}
			
		}
	}
	//Go through all entities
	for (int i = 0; i < map->getEntities()->size(); i++)
	{
		Entity* e = (*(map->getEntities()))[i];

		if (e == nullptr)
		{
			continue;
		}

		//Draw wizard spell things
		if(Wizard* wiz = dynamic_cast<Wizard*> (e))
		{
			if(wiz->getSpellProgress() > 0)
			{
				Renderer::setColor(255, 255 - wiz->getSpellProgress() * 2.5, 255 - wiz->getSpellProgress() * 2.5,255);
				
				int x1 = wiz->getPositionX()*tileWidth + getPositionX() + tileWidth / 2;
				int y1 = wiz->getPositionY()*tileHeight + getPositionY() + tileHeight / 2;
				int x2 = c->getPositionX()*tileWidth + getPositionX() + tileWidth / 2;
				int y2 = c->getPositionY()*tileHeight + getPositionY() + tileHeight / 2;
				Renderer::drawLine(x1-2,y1,x2,y2);
				Renderer::drawLine(x1+2,y1,x2,y2);
				Renderer::drawLine(x1,y1-2,x2,y2);
				Renderer::drawLine(x1,y1+2,x2,y2);
				Renderer::drawLine(x1,y1,x2,y2);
			}
		}
	}
}


void MapComponent::tick() {
	if (map == nullptr)
		return;
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
	Style::click(x, y);
	if (map == nullptr)
		return;
	int mapWidth = map->getWidth();
	int mapHeight = map->getHeight();

	int tileWidth = getWidth() / mapWidth;
	int tileHeight = getHeight() / mapHeight;
	//get tile clicked
	int tileX = x / tileWidth;
	int tileY = y / tileHeight;

	//make sure it's valid tile
	if (tileX >= 0 && tileY >= 0 && tileX < mapWidth && tileY < mapHeight) {

		//call backs
		for (int i = 0; i < onTileClick_callbacks.size(); i++)
		{
			onTileClick_callbacks[i](map, tileX, tileY);
		}
	}

	
}
