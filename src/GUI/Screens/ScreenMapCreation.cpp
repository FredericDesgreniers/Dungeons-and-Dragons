#include "ScreenMapCreation.h"

ScreenMapCreation::ScreenMapCreation(Game* game) : Screen(game)
{
	height = 10;
	width = 10;

	storedEntity = nullptr;
	storedTile = nullptr;

	nameInput = new TextField("TestMap", 125, 75, 100, 20);
	nameInput->setFontSize(15);

	Button* moreWidthBtn = new Button("+", &Renderer::FONT_ROBOTO, 425, 68, 30, 30);
	moreWidthBtn->adjustButtonDimensions();
	Button* lessWidthBtn = new Button("-", &Renderer::FONT_ROBOTO, 385, 68, 30, 30);
	lessWidthBtn->adjustButtonDimensions();
	Button* moreHeightBtn = new Button("+", &Renderer::FONT_ROBOTO, 625, 68, 30, 30);
	moreHeightBtn->adjustButtonDimensions();
	Button* lessHeightBtn = new Button("-", &Renderer::FONT_ROBOTO, 585, 68, 30, 30);
	lessHeightBtn->adjustButtonDimensions();

	Button* generateBtn = new Button("Generate", &Renderer::FONT_ROBOTO, 50, 125, 100, 30);
	generateBtn->adjustButtonDimensions();

	Button* backBtn = new Button("Back", &Renderer::FONT_ROBOTO, 100, 600, 100, 30);
	backBtn->adjustButtonDimensions();

	Button* confirmBtn = new Button("Confirm", &Renderer::FONT_ROBOTO, 300, 600, 100, 30);
	confirmBtn->adjustButtonDimensions();

	addComponent((new Label("Width", &Renderer::FONT_ROBOTO, 300, 75, 1, 1))->setFontSize(15)->adjustDimensions());
	addComponent((new Label("Height", &Renderer::FONT_ROBOTO, 500, 75, 1, 1))->setFontSize(15)->adjustDimensions());
	
	backBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		delete map;

		Screen* screen = this->game->getGuiManager()->setScreen(new ScreenMain(this->game));
		Renderer::addVoidScreen(screen);
		std::cout << "Back to main menu!" << std::endl;
	});

	moreWidthBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		setWidth(width + 1);
		std::cout << "Width +" << std::endl;
	});

	lessWidthBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		setWidth(width - 1);
		std::cout << "Width -" << std::endl;
	});

	moreHeightBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		setHeight(height + 1);
		std::cout << "Height +" << std::endl;
	});

	lessHeightBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		setHeight(height - 1);
		std::cout << "Height -" << std::endl;
	});

	confirmBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{	
		saveMap();
	});

	generateBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		std::cout << "Map Instantiated" << std::endl;
		createMap();
	});

	map = new Map("", 10, 10);
	tileMap = MapBuilder::loadFromFile("tileSelection")->get();
	entityMap = MapBuilder::loadFromFile("entitySelection")->get();

	mapComp = new MapComponent(map, 50, 160, 400, 400);
	addComponent(mapComp);
	mapComp->setVisible(false);

	tileMapComp = new MapComponent(tileMap, 500, 160, 40, 400);
	addComponent(tileMapComp);
	tileMapComp->setVisible(false);

	entityMapComp = new MapComponent(entityMap, 600, 160, 40, 400);
	addComponent(entityMapComp);
	entityMapComp->setVisible(false);

	mapComp->addOnTileClickedCallback([this](Map* map, int x, int y)
	{
		if (storedEntity != nullptr)
		{
			map->getTile(x, y)->setId(0);
			map->spawnEntity(storedEntity, x, y);
		}
		
		if (storedTile != nullptr)
		{
			if (map->getEntity(x, y))
			{
				map->removeEntity(x, y);
			}
			map->getTile(x, y)->setId(storedTile->getId());
		}
	});

	tileMapComp->addOnTileClickedCallback([this](Map* map, int x, int y)
	{
		storedEntity = nullptr;

		storedTile = map->getTile(x, y);
	});

	entityMapComp->addOnTileClickedCallback([this](Map* map, int x, int y)
	{
		storedTile = nullptr;

		storedEntity = map->getEntity(x, y);
	});

	addComponent(backBtn);
	addComponent(moreWidthBtn);
	addComponent(lessWidthBtn);
	addComponent(moreHeightBtn);
	addComponent(lessHeightBtn);
	addComponent(nameInput);
	addComponent(confirmBtn);
	addComponent(generateBtn);
}

void ScreenMapCreation::render()
{
	Renderer::drawString("Map Editor", Renderer::FONT_ROBOTO.get(24), 250, 20, 1, { 255,255,255,255 });

	Renderer::drawString("Name", Renderer::FONT_ROBOTO.get(16), 50, 75, 1, { 255,255,255,255 });

	Renderer::drawString(std::to_string(height), Renderer::FONT_ROBOTO.get(16), 600, 75, 1, { 255,255,255,255 });
	Renderer::drawString(std::to_string(width), Renderer::FONT_ROBOTO.get(16), 400, 75, 1, { 255,255,255,255 });

	Screen::render();
}

void ScreenMapCreation::setWidth(int value) {
	width = std::max(10, std::min(value, 25));
}

void ScreenMapCreation::setHeight(int value) {
	height = std::max(10, std::min(value, 25));
}

void ScreenMapCreation::createMap() {

	if (map != NULL)
	{
		delete map;
	}

	map = new Map(nameInput->getText(), width, height);

	mapComp->setMap(map);
	mapComp->setVisible(true);
	tileMapComp->setVisible(true);
	entityMapComp->setVisible(true);
}

void ScreenMapCreation::saveMap() {

	if (map == NULL || !validateMap())
	{
		return;
	}

	MapBuilder::saveToFile(map->getName(), map);
	std::cout << "Map saved" << std::endl;
}

bool ScreenMapCreation::validateMap()
{
	bool entryPoint = false;
	bool exitPoint = false;

	for (int i = 0; i < map->getWidth(); i++) {
		for (int j = 0; j < map->getHeight(); j++) {

			if (map->getTile(i, j)->getId() == 2)
			{
				if (!entryPoint)
				{
					entryPoint = true;
					continue;
				}
				else
				{
					cout << "warning: more than one entry point" << endl;
					return false;
				}
			}

			if (!exitPoint && map->getTile(i, j)->getId() == 3)
			{
				exitPoint = true;
				continue;
			}
		}
	}

	if (!entryPoint)
	{
		cout << "warning: no entry point" << endl;
		return false;
	}

	if (!exitPoint)
	{
		cout << "warning: no exit point" << endl;
		return false;
	}

	return true;
}
