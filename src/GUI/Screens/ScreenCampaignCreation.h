#pragma once
#include "Screen.h"
#include "../../Campaign.h"
#include "../Components/MapSelect.h"
#include "../../MapBuilder.h"
#include "../Components/TextField.h"

class ScreenCampaignCreation:public Screen
{

private:

	Campaign* campaign;
	
public:

	ScreenCampaignCreation(Game* game);
	MapSelect* campaignPreview;
	TextField* nameField;

	void setCampaign(Campaign* newCampaign);

};
