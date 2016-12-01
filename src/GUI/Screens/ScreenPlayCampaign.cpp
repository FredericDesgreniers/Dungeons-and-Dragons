#include "ScreenPlayCampaign.h"
#include "../../MapBuilder.h"
#include "../Components/EquipedItemComponent.h"
#include "../../EntityChest.h"
#include "ScreenCampaignSelect.h"
#include "../Renderer.h"
#include "screenMain.h"
#include "../Components/ItemContainerComponent.h"
#include "ScreenVictory.h"


ScreenPlayCampaign::ScreenPlayCampaign(Game* game, Campaign* campaign, Character* character) :Screen(game), campaign(campaign), character(character)
{

	currentmap = MapBuilder::loadFromFile(campaign->getMaps().at(campaign->getActiveMapIndex())->getName())->spawnCharacter(character)->spawnScaledContent()->get();

	map_component = new MapComponent(currentmap, 0, 0, 450, 450);
	map_component->setDrawDistance(100);
	addComponent(map_component);

	character_component = new CharacterComponent(character, 500, 0, 200, 500);
	character_component->setBorderSize(1);
	character_component->setBorderColor_both(150, 150, 140, 255);

	addComponent(character_component);

	otherLivingEntityDisplay = new CharacterComponent(character,300,500,200,500);
	otherLivingEntityDisplay->setBorderSize(1);
	otherLivingEntityDisplay->setBorderColor_both(150, 150, 140, 255);

	addComponent(otherLivingEntityDisplay);
	otherLivingEntityDisplay->setVisible(false);

	otherLivingEntityDisplay_equipped = new EquipedItemComponent(character->getEquippedItems(), 520, 500, 200, 500);
	otherLivingEntityDisplay_equipped->setBorderSize(1);
	otherLivingEntityDisplay_equipped->setBorderColor_both(150, 150, 140, 255);

	otherLivingEntityDisplay_equipped->setVisible(false);
	addComponent(otherLivingEntityDisplay_equipped);

	chestDisplay = new ItemContainerComponent(character->getBackpack(), 300, 500, 200, 500);
	chestDisplay->setBorderSize(1);
	chestDisplay->setBorderColor_both(150, 150, 140, 255);

	chestDisplay->setVisible(false);
	addComponent(chestDisplay);

	eiComp = new EquipedItemComponent(character->getEquippedItems(), 500, 220, 200, 500);
	eiComp->setBorderColor_both(150, 150, 140, 255);
	eiComp->setBorderSize(1);

	character->Attach(eiComp);
	addComponent(eiComp);
	eiComp->addOnItemClick_callback([this](Item*, int i)
	{
		Item* item = this->character->unequip(i);
			if(item!=nullptr)
			{
				this->character->getBackpack()->addItem(item);
			}
	});
	ItemContainerComponent* bagDisplay = new ItemContainerComponent(character->getBackpack(),0,475,200,400);
	bagDisplay->setBorderColor_both(150, 150, 140, 255);
	bagDisplay->setBorderSize(1);
	bagDisplay->setPadding(10, 10, 10, 10);
	bagDisplay->addOnItemClick_callback([this](Item* itm, int i)
	{
		Item* item = this->character->getBackpack()->getItemAtIndex(i);
			if(item!=nullptr)
			{
				this->character->equip(item);
				this->character->getBackpack()->removeItemAtIndex(i);
			}
	});
	addComponent(bagDisplay);

	map_component->addOnTileClickedCallback([this](Map* map, int x, int y)
	{
		otherLivingEntityDisplay->setVisible(false);
		otherLivingEntityDisplay_equipped->setVisible(false);
		chestDisplay->setVisible(false);

		Character* chara = this->character;
		Entity* entity = map->getEntity(x, y);
		if (entity != nullptr) {
			if(LivingEntity* livingEntity = dynamic_cast<LivingEntity*>(entity))
			{
					otherLivingEntityDisplay->setLivingEntity(livingEntity);
					otherLivingEntityDisplay->setVisible(true);

					otherLivingEntityDisplay_equipped->setItems(livingEntity->getEquippedItems());
					otherLivingEntityDisplay_equipped->setVisible(true);
			}
			if(EntityChest* chest = dynamic_cast<EntityChest*>(entity))
			{
				chestDisplay->setItemContainer(chest->getContainer());
				chestDisplay->setVisible(true);
			}
			if(!this->character->getTurnFinished()){
				if (chara->distanceTo(entity) <= 1)
				{
					displayEntityInfo(entity);

					if(entity->interact(map, chara))
					{
						this->character->setTurnFinished(true);
					}
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
	if (!character->getTurnFinished()) {
		switch (code)
		{
		case(SDLK_w) : {
			if (currentmap->moveEntity(character, character->getPositionX(), character->getPositionY() - 1) != nullptr) {
				character->setTurnFinished(true);
			}
			break;
		}
		case(SDLK_s) : {
			if (currentmap->moveEntity(character, character->getPositionX(), character->getPositionY() + 1) != nullptr) {
				character->setTurnFinished(true);
			}
			break;
		}
		case(SDLK_a) : {
			if (currentmap->moveEntity(character, character->getPositionX() - 1, character->getPositionY()) != nullptr) {
				character->setTurnFinished(true);
			}
			break;
		}
		case(SDLK_d) : {
			if (currentmap->moveEntity(character, character->getPositionX() + 1, character->getPositionY()) != nullptr) {
				character->setTurnFinished(true);
			}
			break;
		}
		}
	
	if(currentmap->getTile(character->getPositionX(), character->getPositionY())->getId() == ENDTILE)
	{
		std::cout << "Map Finished" << std::endl;
		character->setLevel(character->getLevel() + 1);
		character->saveCharacter(character->getName(), character);
		
		campaign->setActiveMapIndex(campaign->getActiveMapIndex() + 1);

		if (campaign->isCompleted())
		{
			std::cout << "Campaign Finished" << std::endl;
			campaign->setActiveMapIndex(0);
			Screen* victory = new ScreenVictory(game);
			character->Detach(eiComp);
			Renderer::addVoidScreen(game->getGuiManager()->setScreen(victory));
		}
		else
		{
			std::cout << "Move to next map" << std::endl;
			character->Detach(eiComp);
			ScreenPlayCampaign* screen_play_campaign = new ScreenPlayCampaign(game, campaign, character);
			Renderer::addVoidScreen(this->game->getGuiManager()->setScreen(screen_play_campaign));
		}

	}
	}
}


void ScreenPlayCampaign::render()
{
	Screen::render();

}
void ScreenPlayCampaign::tick()
{
	currentmap->simulateMapTick();
}

ScreenPlayCampaign::~ScreenPlayCampaign()
{
	
}
