#include "ScreenPlayCampaign.h"
#include "../../MapBuilder.h"
#include "../Components/EquipedItemComponent.h"
#include "../../EntityChest.h"
#include "ScreenCampaignSelect.h"
#include "../Renderer.h"


ScreenPlayCampaign::ScreenPlayCampaign(Game* game, Campaign* campaign, Character* character) :Screen(game), campaign(campaign), character(character)
{


	
	currentmap = MapBuilder::loadFromFile(campaign->getFirstMap())->spawnCharacter(character)->get();

	map_component = new MapComponent(currentmap, 0, 0, 450, 450);
	addComponent(map_component);

	character_component = new CharacterComponent(character, 500, 30, 200, 500);
	character_component->setBorderSize(1);
	character_component->setBorderColor_both(150, 150, 140, 255);
	character_component->setPadding(10, 10, 10, 10);
	addComponent(character_component);
	
	EquipedItemComponent* eiComp = new EquipedItemComponent(character->getEquippedItems(), 500, 300, 200, 500);
	eiComp->setBorderColor_both(150, 150, 140, 255);
	eiComp->setBorderSize(1);
	eiComp->setPadding(10, 10, 10, 10);
	addComponent(eiComp);

	map_component->addOnTileClickedCallback([this](Map* map, int x, int y)
	{
		Character* chara = this->character;
		Entity* entity = map->getEntity(x, y);
		if (entity != nullptr) {
			if (chara->distanceTo(entity) <= 1)
			{

				displayEntityInfo(entity);

				if(entity->interact(map, chara))
				{
					map->simulateMapTick();
				}
			}
		}
	});

}
void ScreenPlayCampaign::displayEntityInfo(Entity* entity)
{
	if(LivingEntity* living = dynamic_cast<LivingEntity*>(entity))
	{
		
		//TODO display living entity info

	}else if(EntityChest* chest = dynamic_cast<EntityChest*>(entity))
	{
		//TODO display chest contents
	}
}

void ScreenPlayCampaign::keyPressed(SDL_Keycode code)
{

	switch (code)
	{
	case(SDLK_w) : {
		if (currentmap->moveEntity(character, character->getPositionX(), character->getPositionY() - 1) != nullptr) {
			currentmap->simulateMapTick();
		}
		break;
	}
	case(SDLK_s) : {
		if (currentmap->moveEntity(character, character->getPositionX(), character->getPositionY() + 1) != nullptr) {
			currentmap->simulateMapTick();
		}
		break;
	}
	case(SDLK_a) : {
		if (currentmap->moveEntity(character, character->getPositionX()-1, character->getPositionY()) != nullptr) {
			currentmap->simulateMapTick();
		}
		break;
	}
	case(SDLK_d) : {
		if (currentmap->moveEntity(character, character->getPositionX()+1, character->getPositionY()) != nullptr) {
			currentmap->simulateMapTick();
		}
		break;
	}
	}
	if(currentmap->getTile(character->getPositionX(), character->getPositionY())->getId() == ENDTILE)
	{
		std::cout << "Map Finished" << std::endl;
		character->setLevel(character->getLevel() + 1);
		character->saveCharacter(character->getName(), character);
		Renderer::addVoidScreen(game->getGuiManager()->setScreen(new ScreenCampaignSelect(game)));
		
	}
}


void ScreenPlayCampaign::render()
{
	Screen::render();

}

