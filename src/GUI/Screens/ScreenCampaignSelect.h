#pragma once
#include "Screen.h"
#include "../../Campaign.h"
#include "../Components/ButtonList.h"


class ScreenCampaignSelect : public Screen
{
public:
	ScreenCampaignSelect(Game* game);
	Campaign* campaign;
	ButtonList* campaignSelect;
	void render() override;

private:
	
};
