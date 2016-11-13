#pragma once
#include "Screen.h"
#include "../../Campaign.h"
#include "../Components/MapSelect.h"
#include "../../MapBuilder.h"
#include "../Components/TextField.h"

/**
* Screen used to create a campaign from a set of maps
*/
class ScreenCampaignCreation:public Screen
{

private:

	Campaign* campaign;
	
public:
	/**
	 * Screen Constructor given a game instance
	 */
	ScreenCampaignCreation(Game* game);
	MapSelect* campaignPreview;
	TextField* nameField;

	void setCampaign(Campaign* newCampaign);

};
