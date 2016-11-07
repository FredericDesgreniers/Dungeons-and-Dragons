#include "ScreenCampaignSelect.h"

#include "ScreenCharacterSelect.h"
#include "../Renderer.h"
#include "../Components/MapSelect.h"


ScreenCampaignSelect::ScreenCampaignSelect(Game* game) : Screen(game)
{


	MapSelect* mapSelect = new MapSelect(200, 0, 300, 800);
	mapSelect->addOnMapClick_callback([this](Map* map)
	{
		Campaign* campaign = new Campaign(map->getName());
		campaign->addMap(map);
		Screen* screen = new ScreenCharacterSelect(this->game, campaign);
		screen->setBackButton(this);
		this->game->getGuiManager()->setScreen(screen);
	});

	addComponent(mapSelect);


}

void ScreenCampaignSelect::render()
{
	Screen::render();
}
