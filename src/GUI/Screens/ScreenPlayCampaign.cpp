#include "ScreenPlayCampaign.h"


ScreenPlayCampaign::ScreenPlayCampaign(Game* game, Campaign* campaign, Character* character) :Screen(game), campaign(campaign), character(character)
{
	currentmap = campaign->getFirstMap();
	map_component = new MapComponent(currentmap, 0, 0, 450, 450);
	addComponent(map_component);

	character_component = new CharacterComponent(character, 500, 30, 200, 500);
	character_component->setBorderSize(1);
	character_component->setBorderColor_both(150, 150, 140, 255);
	character_component->setPadding(10, 10, 10, 10);
	addComponent(character_component);

	currentmap->spawnEntity(character, 0, 0);

}

void ScreenPlayCampaign::keyPressed(SDL_Keycode code)
{
	switch (code)
	{
	case(SDLK_w) : {
		if (currentmap->moveEntity(character, character->getPositionX(), character->getPositionY() - 1) != nullptr) {

		}
		break;
	}
	case(SDLK_s) : {
		if (currentmap->moveEntity(character, character->getPositionX(), character->getPositionY() + 1) != nullptr) {

		}
		break;
	}
	case(SDLK_a) : {
		if (currentmap->moveEntity(character, character->getPositionX()-1, character->getPositionY()) != nullptr) {

		}
		break;
	}
	case(SDLK_d) : {
		if (currentmap->moveEntity(character, character->getPositionX()+1, character->getPositionY()) != nullptr) {

		}
		break;
	}
	}
}


void ScreenPlayCampaign::render()
{
	Screen::render();

}

