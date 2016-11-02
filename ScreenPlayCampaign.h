#pragma once
#include "Screen.h"
#include "character.h"
#include "Campaign.h"
#include "MapComponent.h"
#include "CharacterComponent.h"


class ScreenPlayCampaign: public Screen
{
public:
	ScreenPlayCampaign(Game* game, Campaign* campaign, Character* character);
	void render() override;
private:

	Campaign* campaign;
	Character* character;

	Map* currentmap;

	MapComponent* map_component;

	CharacterComponent* character_component;
};
