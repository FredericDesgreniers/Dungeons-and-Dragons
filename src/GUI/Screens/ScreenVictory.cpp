#include "ScreenVictory.h"
#include "../Renderer.h"
#include "screenMain.h"

ScreenVictory::ScreenVictory(Game* game):Screen(game)
{
	Label* label = new Label("You won!", &Renderer::FONT_ROBOTO, 30, 30, 0, 0);
	label->adjustDimensions();

	Button* next = new Button("Play Again?",&Renderer::FONT_ROBOTO,30,150,0,0);
	next->adjustButtonDimensions();

	next->addOnClick_callback([this](Component*, int, int){
			Renderer::addVoidScreen(this->game->getGuiManager()->setScreen(new ScreenMain(this->game)));
		});

	addComponent(label);
	addComponent(next);
}
