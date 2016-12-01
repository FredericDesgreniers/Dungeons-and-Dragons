#include "ScreenMapCreation.h"
#include "../../Monster.h"
#include "../../Wizard.h"
#include "../../EntityChest.h"
#include "../../Pathfinder.h"
#include "../../LivingEntity.h"
#include <Windows.h>
#include <fileapi.h>

ScreenMapCreation::ScreenMapCreation(Game* game) : Screen(game)
{
	map = new Map("", 10, 10);

	height = 10;
	width = 10;

	storedEntity = nullptr;
	storedTile = nullptr;
	storedItem = "";

	nameInput = new TextField("TestMap", 125, 75, 100, 20);
	nameInput->setFontSize(15);

	mapSelect = new MapSelect(40, 170, 200, 400);
	mapSelect->setVisible(true);

	Button* moreWidthBtn = new Button("+", &Renderer::FONT_ROBOTO, 425, 68, 30, 30);
	moreWidthBtn->adjustButtonDimensions();
	Button* lessWidthBtn = new Button("-", &Renderer::FONT_ROBOTO, 385, 68, 30, 30);
	lessWidthBtn->adjustButtonDimensions();
	Button* moreHeightBtn = new Button("+", &Renderer::FONT_ROBOTO, 625, 68, 30, 30);
	moreHeightBtn->adjustButtonDimensions();
	Button* lessHeightBtn = new Button("-", &Renderer::FONT_ROBOTO, 585, 68, 30, 30);
	lessHeightBtn->adjustButtonDimensions();

	Button* generateBtn = new Button("Generate new", &Renderer::FONT_ROBOTO, 50, 125, 100, 30);
	generateBtn->adjustButtonDimensions();

	Button* loadBtn = new Button("Load map", &Renderer::FONT_ROBOTO, 250, 125, 100, 30);
	loadBtn->adjustButtonDimensions();

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
		mapSelect->setVisible(false);
	});
	mapSelect->addOnMapClick_callback([this](Map* newMap)
	{
		if (newMap == nullptr)
		{
			cout << "no such file" << endl;
			mapComp->setVisible(false);
			tileMapComp->setVisible(false);
			entityMapComp->setVisible(false);
			return;
		}
		this->mapSelect->setVisible(false);
		delete map;
		this->nameInput->setText(newMap->getName());
		setMap(newMap);

		setHeight(newMap->getHeight());
		setWidth(newMap->getWidth());


		mapComp->setMap(newMap);
		if (!mapComp->isVisible())
		{
			mapComp->setVisible(true);
			tileMapComp->setVisible(true);
			entityMapComp->setVisible(true);
		}
	});
	loadBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		Map* newMap = MapBuilder::loadFromFile(nameInput->getText())->get();
		mapSelect->setVisible(true);
		
		mapComp->setVisible(false);
		tileMapComp->setVisible(false);
		entityMapComp->setVisible(false);

		mapSelect->reloadMaps();

	});

	tileMap = new Map(1, 10);
	entityMap = new Map(1, 10);

	tileMap->setTile(new MapTile(TILE_WALL), 0, 2);
	tileMap->setTile(new MapTile(SPAWNTILE), 0, 0);
	tileMap->setTile(new MapTile(ENDTILE), 0, 1);

	LivingEntity* friendlyEntity = new LivingEntity('F');
	friendlyEntity->setHostile(false);
	friendlyEntity->setStrategy(new FriendlyStrategy());
	friendlyEntity->setDisplayColor(255, 255, 0, 255);
	LivingEntity* hostileEntity = new LivingEntity('H');
	hostileEntity->setHostile(true);
	hostileEntity->setStrategy(new HostileStrategy());
	hostileEntity->setDisplayColor(255, 0, 255, 255);
	EntityChest* chestEntity = new EntityChest();
	chestEntity->setDisplayColor(0, 255, 255, 255);

	entityMap->spawnEntity(friendlyEntity, 0, 0);
	entityMap->spawnEntity(hostileEntity, 0, 1);
	entityMap->spawnEntity(chestEntity, 0, 2);
	
	char search_path[200];
	sprintf_s(search_path, "%s*.*", "items/");
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path, &fd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		int y = 0;
		do
		{
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				const std::string name = std::string(fd.cFileName).substr(0, strlen(fd.cFileName) - 3);

				Button* itemButton = new Button(name, &Renderer::FONT_ROBOTO, 550, 170 + y, 1, 1);
				itemButton->setFontSize(15)->adjustDimensions();
				itemButton->addOnClick_callback([this](Component* comp, int x, int y)
				{
					storedEntity = nullptr;
					storedTile = nullptr;
					storedItem = ((Button*)comp)->getText();
				});
				addComponent(itemButton);

				y += 45;

			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}

	mapComp = new MapComponent(map, 50, 170, 325, 325);
	addComponent(mapComp);
	mapComp->setVisible(false);

	tileMapComp = new MapComponent(tileMap, 410, 170, 35, 325);
	addComponent(tileMapComp);
	tileMapComp->setVisible(false);

	entityMapComp = new MapComponent(entityMap, 480, 170, 35, 325);
	addComponent(entityMapComp);
	entityMapComp->setVisible(false);

	mapComp->addOnTileClickedCallback([this](Map* map, int x, int y)
	{
		if (storedEntity != nullptr)
		{
			map->setTile(new MapTile(0), x, y);
			map->spawnEntity(storedEntity, x, y);
		}
		
		if (storedTile != nullptr)
		{
			if (map->getEntity(x, y))
			{
				map->removeEntity(x, y);
			}
			map->setTile(new MapTile(storedTile->getId()),x,y);
		}

		if (storedItem != "")
		{
			if (map->getEntity(x, y) != nullptr && map->getEntity(x, y)->getRenderChar() == 'B')
			{
				for (int i = 0; i < map->itemList.size(); i++)
				{
					int boxX;
					int boxY;
					std::stringstream ss(map->itemList.at(i));
					ss >> boxX >> boxY;

					if (x == boxX && boxY == y)
					{
						cout << "box already contains an item" << endl;
						std::string test = map->itemList.at(i);
						int count = std::count(test.begin(), test.end(), ' ');

						if (count > ((EntityChest*)map->getEntity(x, y))->getContainer()->getSize())
						{
							cout << "box is full" << endl;
							return;
						}

						map->itemList.at(i) += " " + storedItem;
						cout << "item added to box" << endl;
						return;
					}
				}
				cout << "placed item in box" << endl;
				map->itemList.push_back(std::to_string(x) + " " + std::to_string(y) + " " + storedItem);
			}
			else
			{
				cout << "not a box" << endl;
			}
		}
	});

	tileMapComp->addOnTileClickedCallback([this](Map* map, int x, int y)
	{
		storedItem = "";
		storedEntity = nullptr;
		storedTile = map->getTile(x, y);
	});

	entityMapComp->addOnTileClickedCallback([this](Map* map, int x, int y)
	{
		storedItem = "";
		storedTile = nullptr;
		storedEntity = map->getEntity(x, y);
	});
	addComponent(mapSelect);
	addComponent(backBtn);
	addComponent(moreWidthBtn);
	addComponent(lessWidthBtn);
	addComponent(moreHeightBtn);
	addComponent(lessHeightBtn);
	addComponent(nameInput);
	addComponent(confirmBtn);
	addComponent(generateBtn);
	addComponent(loadBtn);
}

void ScreenMapCreation::render()
{
	Renderer::drawString("Map Editor", Renderer::FONT_ROBOTO.get(24), 250, 20, 1, { 255,255,255,255 });

	Renderer::drawString("Name", Renderer::FONT_ROBOTO.get(16), 50, 75, 1, { 255,255,255,255 });

	Renderer::drawString(std::to_string(height), Renderer::FONT_ROBOTO.get(16), 600, 75, 1, { 255,255,255,255 });
	Renderer::drawString(std::to_string(width), Renderer::FONT_ROBOTO.get(16), 400, 75, 1, { 255,255,255,255 });

	Screen::render();
}

void ScreenMapCreation::setMap(Map* newMap)
{
	map = newMap;
}

void ScreenMapCreation::setWidth(int value) {
	width = max(10, min(value, 25));
}

void ScreenMapCreation::setHeight(int value) {
	height = max(10, min(value, 25));
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

	MapBuilder::saveToFile(nameInput->getText(), map);
	std::cout << "Map saved" << std::endl;
}

bool ScreenMapCreation::validateMap()
{
	bool entryPoint = false;
	bool exitPoint = false;
	int entryX, entryY;
	int endX, endY;

	for (int i = 0; i < map->getWidth(); i++) {
		for (int j = 0; j < map->getHeight(); j++) {

			if (map->getTile(i, j)->getId() == 2)
			{
				if (!entryPoint)
				{
					entryPoint = true;
					entryX = i;
					entryY = j;
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
				endX = i;
				endY = j;
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

	Pathfinder pathfinder(map, endX, endY);

	std::vector<Node*>* path = pathfinder.getPath(entryX, entryY);
	if( abs((*path)[0]->x - endX)<=1 && (abs((*path)[0]->y-endY) <=1))
	{
		delete path;
		return true;
	}else
	{
		delete path;
		return false;
	}

	
}
