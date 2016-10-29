#include "ScreenTitle.h"
#include "Renderer.h"
#include "ScreenMain.h"

ScreenTitle::ScreenTitle(Game* game) : Screen(game)
{
	button = new Button("ENTER", Renderer::FONT_ROBOTO_24, 200, 400, 0, 0);
	button->adjustButtonDimensions();
	button->setFontColor(255, 255, 255, 255);

	button->setFontUnderline_hover(1);
	button->setFontUnderlineColor_hover(255, 255, 255, 255);

	button->scale(3);


	button->setVisible(false);

	button->addOnClick_callback([this](Component* c, int x, int y)
	{
		Screen* screen = this->game->getGuiManager()->setScreen(new ScreenMain(this->game));
		delete screen;
	});

	addComponent(button);
	
}

void ScreenTitle::render()
{
	Screen::render();
	Uint8 colorProgress;
	if (ticksSinceStart > (255 / 2)) {
		colorProgress = 255;
		
	}
	else
		colorProgress = ticksSinceStart*2;

	Renderer::drawString("Dungeons and Dragons", Renderer::FONT_ROBOTO_24, 100, 100, 2, { colorProgress,colorProgress,colorProgress,255 });
	if(ticksSinceStart > 255/2+20)
	{
		Renderer::drawString("comp 345 team project", Renderer::FONT_ROBOTO_24, 190, 170, 1, { 100,100,100,255 });
		button->setVisible(true);
	}

}


void ScreenTitle::tick()
{
	Screen::tick();
	ticksSinceStart++;
}

