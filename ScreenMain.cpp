#include "ScreenMain.h"
#include "Renderer.h"

ScreenMain::ScreenMain(Game* game) : Screen(game)
{
	Button* playBtn = new Button(0, "Play", 100, 100, 100, 30);

	playBtn->setBackgroundColor_both(255, 255, 255, 255);

	playBtn->setBorderColor(255, 255, 255, 255);
	playBtn->setBorderColor_hover(255, 0, 0, 255);
	playBtn->setBorderSize(5);



	playBtn->setPadding(10);

	addButton(playBtn);
}

void ScreenMain::onButtonClicked(Button* b)
{
	
}

void ScreenMain::render()
{
	Screen::render();
}


