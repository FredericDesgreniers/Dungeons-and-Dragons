#pragma once
#include "Screen.h"
/**
 * Screen used to create a campaign from a set of maps
 */
class ScreenCampaignCreation:public Screen
{
public:
	/**
	 * Screen Constructor given a game instance
	 */
	ScreenCampaignCreation(Game* game);
};
