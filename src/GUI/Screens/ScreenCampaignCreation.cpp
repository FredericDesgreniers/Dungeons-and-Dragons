#include "ScreenCampaignCreation.h"
#include "../Components/MapSelect.h"
#include "../Renderer.h"
#include "../Components/TextField.h"

ScreenCampaignCreation::ScreenCampaignCreation(Game* game):Screen(game)
{
	int wx, wy;
	SDL_GetWindowSize(Renderer::window, &wx, &wy);
	MapSelect* ms = new MapSelect(50,50,wx/2-100,wy-100);
	addComponent(ms);
	ms->setBackgroundColor_both(50, 50, 50, 255);
	ms->setPadding(10, 10, 10, 10);
	ms->setBorderColor_both(150, 150, 150, 255);
	ms->setBorderSize(1);
	TextField* nameField = new TextField("Campaign1", wx / 2, 5, wx / 2 - 50, 30); 
		nameField->setFontSize(20);
	addComponent(nameField);
}
