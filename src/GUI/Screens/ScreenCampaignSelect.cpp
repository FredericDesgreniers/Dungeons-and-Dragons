#include "ScreenCampaignSelect.h"

#include "ScreenCharacterSelect.h"
#include "../Renderer.h"
#include "../Components/ButtonList.h"


ScreenCampaignSelect::ScreenCampaignSelect(Game* game) : Screen(game)
{
	campaignSelect = new ButtonList(200, 200, 300, 250);
	addComponent(campaignSelect);

	campaignSelect->getCurrentButton()->addOnClick_callback([this](Component* comp, int x, int y)
	{
		campaign = Campaign::loadCampaign(campaignSelect->getCurrentButton()->getText());
		Screen* screen = new ScreenCharacterSelect(this->game, campaign);
		this->game->getGuiManager()->setScreen(screen);
	});
}

void ScreenCampaignSelect::render()
{
	Screen::render();
}
