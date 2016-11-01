#include "ScreenCharacterCreation.h"
#include "Renderer.h"
#include "screenMain.h"
#include "Map.h"
#include "MapComponent.h"

ScreenCharacterCreation::ScreenCharacterCreation(Game* game) : Screen(game)
{	
	Renderer::drawString("comp 345 team project", Renderer::FONT_ROBOTO.get(24), 190, 170, 1, { 100,100,100,255 });

	Renderer::drawString("Test", Renderer::FONT_ROBOTO.get(48), 100, 500, 1, { 100,100,100,255 });


	Button* backBtn = new Button("Back", &Renderer::FONT_ROBOTO, 100, 300, 100, 30);

	backBtn->setFontColor(255, 255, 255, 255);

	backBtn->setBackgroundColor_both(255, 255, 255, 0);

	backBtn->setFontUnderlineColor_hover(255, 255, 255, 255);
	backBtn->setFontUnderline_hover(1);

	backBtn->setPadding(10);

	backBtn->adjustButtonDimensions();

	backBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		Screen* screen = this->game->getGuiManager()->setScreen(new ScreenMain(this->game));
		Renderer::addVoidScreen(screen);
		std::cout << "Back to main menu!" << std::endl;
	});


	addComponent(backBtn);
}

void ScreenCharacterCreation::render()
{
	Screen::render();
}


