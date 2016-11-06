#include "ScreenCampaignCreation.h"
#include "../Components/MapSelect.h"

ScreenCampaignCreation::ScreenCampaignCreation(Game* game):Screen(game)
{
	MapSelect* ms = new MapSelect(0,0,300,500);
	addComponent(ms);
}
