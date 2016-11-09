#pragma once
#include "Screen.h"
#include "../../Campaign.h"

/**
 * Select a camapign from a list of created campaigns
 */
class ScreenCampaignSelect : public Screen
{
public:
	ScreenCampaignSelect(Game* game);


	/**
	 *Render method override for screen
	 */
	void render() override;

private:
	Campaign* campaign;
};
