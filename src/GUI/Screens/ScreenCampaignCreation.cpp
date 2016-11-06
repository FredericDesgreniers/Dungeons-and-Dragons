#include "ScreenCampaignCreation.h"
#include "../Components/MapSelect.h"
#include "../Renderer.h"
ScreenCampaignCreation::ScreenCampaignCreation(Game* game):Screen(game)
{
	int wx, wy;
	SDL_GetWindowSize(Renderer::window, &wx, &wy);
	MapSelect* ms = new MapSelect(50,50,wx/2,wy-100);
	addComponent(ms);
}
