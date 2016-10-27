#include "ScreenMain.h"
#include "Renderer.h"

ScreenMain::ScreenMain(Game* game) : Screen(game)
{
	addButton(new Button(0, "Play", 100,100,100,30));
}

void ScreenMain::onButtonClicked(Button* b)
{
	
}

void ScreenMain::render()
{
	Screen::render();
}


