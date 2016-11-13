#pragma once
#include "Screen.h"
#include "../../Campaign.h"
#include "../Components/ButtonList.h"

/**
 * Select a camapign from a list of created campaigns
 */
class ScreenCampaignSelect : public Screen
{
public:
	ScreenCampaignSelect(Game* game);

	
	Campaign* campaign;
	ButtonList* campaignSelect;

	/**
	*Render method override for screen
	*/
	void render() override;

private:
	
};
