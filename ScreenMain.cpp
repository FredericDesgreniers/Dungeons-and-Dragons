#include "ScreenMain.h"
#include "ScreenCharacterCreation.h"
#include "Renderer.h"
#include "Map.h"
#include "MapComponent.h"
#include "ScreenCampaignSelect.h"

ScreenMain::ScreenMain(Game* game) : Screen(game)
{
	Button* playBtn = new Button("Play", &Renderer::FONT_ROBOTO, 100, 100, 100, 30);

	playBtn->setFontColor(255, 255, 255, 255);

	playBtn->setBackgroundColor_both(255, 255, 255, 0);

	playBtn->setFontUnderlineColor_hover(255, 255, 255, 255);
	playBtn->setFontUnderline_hover(1);

	playBtn->setPadding(10);

	playBtn->adjustButtonDimensions();

	playBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		ScreenCampaignSelect* screen_campaign_select = new ScreenCampaignSelect(this->game);
		Renderer::addVoidScreen(this->game->getGuiManager()->setScreen(screen_campaign_select));
	});

	Button* createMapBtn = new Button("Create Map", &Renderer::FONT_ROBOTO, 100, 160, 200, 30);

	createMapBtn->adjustButtonDimensions();

	createMapBtn->addOnClick_callback([](Component* comp, int x, int y)
	{
		//TODO Create new screen to redirect to
		std::cout << "Go to Map Creation screen!" << std::endl;
	});
	copyStyle(*playBtn, *createMapBtn);

	Button* charEditorBtn = new Button("Character Editor", &Renderer::FONT_ROBOTO, 100, 220, 100, 30);

	charEditorBtn->adjustButtonDimensions();

	charEditorBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		Screen* screen = this->game->getGuiManager()->setScreen(new ScreenCharacterCreation(this->game));
		Renderer::addVoidScreen(screen);
		
		std::cout << "Go to Character Editor!" << std::endl;
	});


	copyStyle(*playBtn, *charEditorBtn);

	/*
	Map* map = new Map(25, 25);
	MapComponent* mapComp = new MapComponent(map, 15, 250, 400, 400);

	mapComp->addOnTileClickedCallback([this](Map* map, int x, int y)
	{
		MapTile* tile = map->getTile(x,y);
		tile->setId(tile->getId() == TILE_EMPTY ? TILE_WALL : TILE_EMPTY);

	});
	
	mapComp->setPadding(10, 10, 10, 10);
	addComponent(mapComp);
	*/
	addComponent(playBtn);
	addComponent(createMapBtn);
	addComponent(charEditorBtn);
	
}

void ScreenMain::render()
{
	Screen::render();
}


