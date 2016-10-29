#include "ScreenMain.h"
#include "Renderer.h"

ScreenMain::ScreenMain(Game* game) : Screen(game)
{
	Button* playBtn = new Button( "Play", Renderer::FONT_ROBOTO_24, 100, 100, 100, 30);

	playBtn->setFontColor(255, 255, 255, 255);

	playBtn->setBackgroundColor_both(255, 255, 255, 0);

	playBtn->setFontUnderlineColor_hover(255, 255, 255, 255);
	playBtn->setFontUnderline_hover(1);

	playBtn->setPadding(10);

	playBtn->adjustButtonDimensions();

	playBtn->addOnClick_callback([](Component* comp, int x, int y)
	{
		std::cout << "Play button pressed at relative pos " << x << ", " << y << std::endl;
	});
	
	Button* createMapBtn = new Button("Create Map",Renderer::FONT_ROBOTO_24, 100, 150, 200, 30);

	createMapBtn->adjustButtonDimensions();
	copyStyle(*playBtn, *createMapBtn);

	addComponent(playBtn);
	addComponent(createMapBtn);
}

void ScreenMain::render()
{
	Screen::render();
}


