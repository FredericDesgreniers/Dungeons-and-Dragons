#include "ScreenMain.h"
#include "ScreenCharacterCreation.h"
#include "ScreenMapCreation.h"
#include "ScreenItemCreation.h"

#include "ScreenCampaignSelect.h"

#include "../Components/TextField.h"
#include "../Renderer.h"
#include "ScreenCampaignCreation.h"


ScreenMain::ScreenMain(Game* game) : Screen(game)
{
	Button* playBtn = new Button("Play", &Renderer::FONT_ROBOTO, 100, 100, 100, 30);

	playBtn->adjustButtonDimensions();

	playBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		ScreenCampaignSelect* screen_campaign_select = new ScreenCampaignSelect(this->game);
		screen_campaign_select->setBackButton(this);
		this->game->getGuiManager()->setScreen(screen_campaign_select);
	});

	Button* createMapBtn = new Button("Create Map", &Renderer::FONT_ROBOTO, 100, 160, 200, 30);

	createMapBtn->adjustButtonDimensions();

	createMapBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		Screen* screen = this->game->getGuiManager()->setScreen(new ScreenMapCreation(this->game));
		Renderer::addVoidScreen(screen);
		std::cout << "Go to Map Creation screen!" << std::endl;
	});

	Button* charEditorBtn = new Button("Character Editor", &Renderer::FONT_ROBOTO, 100, 220, 100, 30);

	charEditorBtn->adjustButtonDimensions();

	charEditorBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		Screen* screen = this->game->getGuiManager()->setScreen(new ScreenCharacterCreation(this->game));
		Renderer::addVoidScreen(screen);
		
		std::cout << "Go to Character Editor!" << std::endl;
	});

	Button* campEditorBtn = new Button("Campaign Editor", &Renderer::FONT_ROBOTO, 100, 280, 100, 30);

	campEditorBtn->adjustButtonDimensions();
	campEditorBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		Screen* campaignEditorScreen = new ScreenCampaignCreation(this->game);
		Screen* screen = this->game->getGuiManager()->setScreen(campaignEditorScreen);
		campaignEditorScreen->setBackButton(this);

		std::cout << "Go to Campaign Editor!" << std::endl;
	});

	// Item Editor
	Button* itemEditorBtn = new Button("Item Editor", &Renderer::FONT_ROBOTO, 100, 340, 100, 30);

	itemEditorBtn->adjustButtonDimensions();

	itemEditorBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		// new screen item creation obj
		ScreenItemCreation* screen_item_creation = new ScreenItemCreation(this->game);

		// back btn
		screen_item_creation->setBackButton(this);


		this->game->getGuiManager()->setScreen(screen_item_creation);
	});

	addComponent(playBtn);
	addComponent(createMapBtn);
	addComponent(charEditorBtn);
	addComponent(campEditorBtn);
	addComponent(itemEditorBtn);
}

void ScreenMain::render()
{
	Screen::render();
}


