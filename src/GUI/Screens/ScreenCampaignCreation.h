#pragma once
#include "Screen.h"
#include "../../Campaign.h"
#include "../Components/MapSelect.h"

class ScreenCampaignCreation:public Screen
{

private:

	Campaign* campaign;
	

public:

	ScreenCampaignCreation(Game* game);
	MapSelect* campaignPreview;

};
