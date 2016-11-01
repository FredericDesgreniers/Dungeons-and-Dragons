#pragma once
#include "Screen.h"
#include "Campaign.h"

class ScreenCampaignSelect : public Screen
{
public:
	ScreenCampaignSelect(Game* game);



	void render() override;

private:
	Campaign* campaign;
};
