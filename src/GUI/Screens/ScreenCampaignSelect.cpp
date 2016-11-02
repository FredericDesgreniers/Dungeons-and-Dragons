#include "ScreenCampaignSelect.h"

#include "ScreenCharacterSelect.h"
#include "../Renderer.h"


ScreenCampaignSelect::ScreenCampaignSelect(Game* game) : Screen(game)
{
	Button* defaultCampaignButton = new Button("Default Campaign",&Renderer::FONT_ROBOTO, 100,300,0,0);
	defaultCampaignButton->setFontColor(255, 255, 255, 255);
	defaultCampaignButton->adjustButtonDimensions();
	defaultCampaignButton->addOnClick_callback([this](Component* comp, int x, int y)
	{
		Campaign* campaign = new Campaign("Default");

		Map* map = new Map(25,25);
		map->setTile(new MapTile(SPAWNTILE), 0, 0);
		map->setTile(new MapTile(ENDTILE), 24, 24);
		campaign->addMap(map);

		Screen* screen = new ScreenCharacterSelect(this->game, campaign);
		screen->setBackButton(this);
		this->game->getGuiManager()->setScreen(screen);
	});

	addComponent(defaultCampaignButton);
}

void ScreenCampaignSelect::render()
{
	Screen::render();
}
