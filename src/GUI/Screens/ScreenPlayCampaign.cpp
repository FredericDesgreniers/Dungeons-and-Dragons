#include "ScreenPlayCampaign.h"


ScreenPlayCampaign::ScreenPlayCampaign(Game* game, Campaign* campaign, Character* character) :Screen(game), campaign(campaign), character(character)
{
	currentmap = campaign->getFirstMap();
	map_component = new MapComponent(currentmap, 0, 0, 450, 450);
	addComponent(map_component);

	character_component = new CharacterComponent(character, 500, 0, 200, 500);
	character_component->setBorderSize(1);
	character_component->setBorderColor_both(150, 150, 140, 255);
	character_component->setPadding(10, 10, 10, 10);
	addComponent(character_component);
}

void ScreenPlayCampaign::render()
{
	Screen::render();

}

