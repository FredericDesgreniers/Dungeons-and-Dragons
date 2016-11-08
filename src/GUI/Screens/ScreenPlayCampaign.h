#pragma once
#include "Screen.h"
#include "../../Campaign.h"
#include "../../character.h"
#include "../Components/MapComponent.h"
#include "../Components/CharacterComponent.h"
#include "../Components/ItemContainerComponent.h"
#include "../Components/EquipedItemComponent.h"


class ScreenPlayCampaign: public Screen
{
public:
	ScreenPlayCampaign(Game* game, Campaign* campaign, Character* character);
	void render() override;
	void keyPressed(SDL_Keycode code) override;

	void displayEntityInfo(Entity* entity);

private:

	Campaign* campaign;
	Character* character;

	Map* currentmap;

	MapComponent* map_component;

	CharacterComponent* otherLivingEntityDisplay;
	EquipedItemComponent* otherLivingEntityDisplay_equipped;

	ItemContainerComponent* chestDisplay;

	CharacterComponent* character_component;
};
