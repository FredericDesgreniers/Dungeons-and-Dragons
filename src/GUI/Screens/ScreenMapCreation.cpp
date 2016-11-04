#include "ScreenMapCreation.h"

ScreenMapCreation::ScreenMapCreation(Game* game) : Screen(game)
{
	height = 10;
	width = 10;

	nameInput = new TextField("TestMap", 250, 100, 100, 20);
	nameInput->setFontSize(15);

	Button* moreWidthBtn = new Button("Width+", &Renderer::FONT_ROBOTO, 400, 200, 100, 30);
	moreWidthBtn->adjustButtonDimensions();
	Button* lessWidthBtn = new Button("Width-", &Renderer::FONT_ROBOTO, 400, 250, 100, 30);
	lessWidthBtn->adjustButtonDimensions();
	Button* moreHeightBtn = new Button("Height+", &Renderer::FONT_ROBOTO, 400, 300, 100, 30);
	moreHeightBtn->adjustButtonDimensions();
	Button* lessHeightBtn = new Button("Height-", &Renderer::FONT_ROBOTO, 400, 350, 100, 30);
	lessHeightBtn->adjustButtonDimensions();

	Button* backBtn = new Button("Back", &Renderer::FONT_ROBOTO, 100, 600, 100, 30);
	backBtn->adjustButtonDimensions();

	Button* confirmBtn = new Button("Confirm", &Renderer::FONT_ROBOTO, 300, 600, 100, 30);
	confirmBtn->adjustButtonDimensions();

	addComponent((new Label("Width", &Renderer::FONT_ROBOTO, 100, 175, 1, 1))->setFontSize(15)->adjustDimensions());
	addComponent((new Label("Height", &Renderer::FONT_ROBOTO, 100, 200, 1, 1))->setFontSize(15)->adjustDimensions());
	
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

}

void ScreenMapCreation::render()
{
	Renderer::drawString("Map Editor", Renderer::FONT_ROBOTO.get(24), 250, 0, 1, { 255,255,255,255 });

	Renderer::drawString("Name", Renderer::FONT_ROBOTO.get(16), 100, 100, 1, { 255,255,255,255 });

	Renderer::drawString(std::to_string(height), Renderer::FONT_ROBOTO.get(16), 250, 175, 1, { 255,255,255,255 });
	Renderer::drawString(std::to_string(width), Renderer::FONT_ROBOTO.get(16), 250, 200, 1, { 255,255,255,255 });

	Screen::render();
}

void ScreenMapCreation::setWidth(int value) {
	width = std::max(10, std::min(value, 25));
}

void ScreenMapCreation::setHeight(int value) {
	height = std::max(10, std::min(value, 25));
}

void ScreenMapCreation::createMap() {

	map = new Map(nameInput->getText(), width, height);

	MapBuilder::saveToFile(map->getName(), map);
	cout << *map << endl;

	delete map;

}

