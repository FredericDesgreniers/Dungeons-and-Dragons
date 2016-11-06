#include "ScreenCampaignCreation.h"
#include "../Components/MapSelect.h"
#include "../Renderer.h"
#include "../Components/TextField.h"

ScreenCampaignCreation::ScreenCampaignCreation(Game* game):Screen(game)
{
	int wx, wy;
	SDL_GetWindowSize(Renderer::window, &wx, &wy);
	MapSelect* ms = new MapSelect(50,60,wx/2,wy-100);
	addComponent(ms);

	TextField* nameField = new TextField("Campaign1", 10,10,300,40);
	addComponent(nameField);
}
