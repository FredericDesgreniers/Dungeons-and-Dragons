#pragma once
#include "Screen.h"
#include "../../Campaign.h"
#include "../../LivingEntity.h"
#include "../Components/MapComponent.h"
#include "../Components/CharacterComponent.h"
#include "../Components/ItemContainerComponent.h"
#include "../Components/EquipedItemComponent.h"

/**
 * Screen used to play a campaign
 */
class ScreenPlayCampaign: public Screen
{
public:
	/**
	 * Cosntructor to play a campaign given a game, campaign and character
	 */
	ScreenPlayCampaign(Game* game, Campaign* campaign, LivingEntity* character);

	/**
	 * Override screen render method
	 */
	void render() override;
	/**
	 * Override keypress method for game input
	 */
	void keyPressed(SDL_Keycode code) override;
	/**
	 * Display the info for an entity on the screen
	 */
	void displayEntityInfo(Entity* entity);

	void tick();

	~ScreenPlayCampaign();
private:

	Campaign* campaign;
	LivingEntity* character;
	EquipedItemComponent* eiComp;
	Map* currentmap;

	MapComponent* map_component;

	CharacterComponent* otherLivingEntityDisplay;
	EquipedItemComponent* otherLivingEntityDisplay_equipped;

	ItemContainerComponent* chestDisplay;

	CharacterComponent* character_component;
};
