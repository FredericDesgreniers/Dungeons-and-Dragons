#include "ScreenMapCreation.h"

ScreenMapCreation::ScreenMapCreation(Game* game) : Screen(game)
{
	height = 10;
	width = 10;

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
		std::cout << "Map saved:" << std::endl;
		saveMap();
	});

	generateBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		std::cout << "Map Instantiated:" << std::endl;
		createMap();
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
	cout << *map << endl;

	MapComponent* mapComp = new MapComponent(map, 50, 150, map->getWidth(), map->getHeight());
	addComponent(mapComp);
}

void ScreenMapCreation::saveMap() {

	if (map == NULL)
	{
		return;
	}

	MapBuilder::saveToFile(map->getName(), map);

	delete map;

}

