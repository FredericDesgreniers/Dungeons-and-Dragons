#include "ScreenTitle.h"
#include "Renderer.h"
#include "ScreenMain.h"

ScreenTitle::ScreenTitle(Game* game) : Screen(game)
{
	button = new Button("ENTER", &Renderer::FONT_ROBOTO, 200, 400, 0, 0);
	
	button->setFontColor(255, 255, 255, 255);

	button->setFontUnderline_hover(1);
	button->setFontUnderlineColor_hover(255, 255, 255, 255);

	button->setFontSize(60);
	button->adjustButtonDimensions();

	button->setVisible(false);

	button->addOnClick_callback([this](Component* c, int x, int y)
	{
		Screen* screen = this->game->getGuiManager()->setScreen(new ScreenMain(this->game));
		Renderer::addVoidScreen(screen);
	});

	addComponent(button);
	
}

void ScreenTitle::render()
{
	Screen::render();
	Uint8 colorProgress;
	double secondsSinceStart = ((double)time / 1000);


	if (secondsSinceStart > 2) {
		colorProgress = 255;
		
	}
	else
		colorProgress = (secondsSinceStart/2) * 255;

	Renderer::drawString("Dungeons and Dragons", Renderer::FONT_ROBOTO.get(48), 100, 100, 1, { colorProgress,colorProgress,colorProgress,255 });
	if(ticksSinceStart > 255/2+20)
	{
		Renderer::drawString("comp 345 team project", Renderer::FONT_ROBOTO.get(24), 190, 170, 1, { 100,100,100,255 });
		button->setVisible(true);
	}

}


void ScreenTitle::tick()
{
	Screen::tick();
	ticksSinceStart++;
}

