#include "ScreenCampaignCreation.h"
#include "../Components/MapSelect.h"
#include "../Renderer.h"
#include "../Components/TextField.h"

ScreenCampaignCreation::ScreenCampaignCreation(Game* game):Screen(game)
{
	campaign = new Campaign("newCampaign", std::vector<Map*>());

	int wx, wy;
	SDL_GetWindowSize(Renderer::window, &wx, &wy);

	nameField = new TextField("newCampaign", wx / 2, 5, wx / 2 - 50, 30);
	nameField->setFontSize(20);
	addComponent(nameField);

	campaignPreview = new MapSelect(campaign->getMaps(), (wx / 2 - 100 + 150), 50, wx / 2 - 100, wy - 100);

	campaignPreview->setBackgroundColor_both(50, 50, 50, 255);
	campaignPreview->setPadding(10, 10, 10, 10);
	campaignPreview->setBorderColor_both(150, 150, 150, 255);
	campaignPreview->setBorderSize(1);
	addComponent(campaignPreview);
	campaignPreview->addOnMapClick_callback([this](Map* map)
	{
		campaign->removeMap(map);
		campaignPreview->loadMaps(campaign->getMaps());
	});

	MapSelect* mapSelect = new MapSelect(50, 50, wx / 2 - 100, wy - 100);
	mapSelect->setBackgroundColor_both(50, 50, 50, 255);
	mapSelect->setPadding(10, 10, 10, 10);
	mapSelect->setBorderColor_both(150, 150, 150, 255);
	mapSelect->setBorderSize(1);
	addComponent(mapSelect);
	mapSelect->addOnMapClick_callback([this](Map* map)
	{
		campaign->addMap(map);
		campaignPreview->loadMaps(campaign->getMaps());
	});
	
	Button* saveButton = new Button("Save", &Renderer::FONT_ROBOTO, 100, wy - 45, 100, 30);
	saveButton->adjustButtonDimensions();
	addComponent(saveButton);
	saveButton->addOnClick_callback([this](Component* comp, int x, int y)
	{
		campaign->setName(nameField->getText());
		Campaign::saveCampaign(campaign);
	});

	Button* loadButton = new Button("Load", &Renderer::FONT_ROBOTO, 200, wy - 45, 100, 30);
	loadButton->adjustButtonDimensions();
	addComponent(loadButton);
	loadButton->addOnClick_callback([this](Component* comp, int x, int y)
	{
		delete campaign;

		Campaign* newCampaign = Campaign::loadCampaign(nameField->getText());
		setCampaign(newCampaign);

		campaignPreview->loadMaps(campaign->getMaps());
	});
}

void ScreenCampaignCreation::setCampaign(Campaign* newCampaign)
{
	campaign = newCampaign;
}


