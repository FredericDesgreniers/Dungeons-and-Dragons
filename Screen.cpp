#include "Screen.h"
#include "Renderer.h"

Screen::Screen(Game* game):game(game)
{

}


void Screen::render()
{

	for(Component* comp:components)
	{
		if (!comp->isVisible())
			continue;
		comp->render();
	}

}

void Screen::tick()
{
	time = SDL_GetTicks();

	for (Component* comp : components)
		comp->tick();
}


void Screen::reInitialize()
{
	
}


void Screen::click(int x, int y)
{
	for (Component* c : components) {

		if (c->isInBounds(x, y))
		{
			c->click(x - c->getPositionX(), y - c->getPositionY());
		}
	}
		
}

void Screen::renderDebug()
{
	for (Component* comp : components)
	{
		if(!comp->isVisible())
			continue;;
		comp->renderDebug();
	}
}

void Screen::setBackButton(Screen* screen)
{
	backScreen = screen;
	int wWidth, wHeight;
	SDL_GetWindowSize(Renderer::window, &wWidth, &wHeight);

	backButton = new Button("back", &Renderer::FONT_ROBOTO, 15, wHeight - 30, 0, 0);
	backButton->adjustButtonDimensions();
	backButton->setPositionY(wHeight - backButton->getHeight() - 10);

	backButton->addOnClick_callback([this](Component* component, int x, int y)
	{
		backScreen->reInitialize();
		Renderer::addVoidScreen(this->game->getGuiManager()->setScreen(this->backScreen));
		
	});

	addComponent(backButton);
}

Screen::~Screen()
{
	for (Component* c : components)
		delete c;
}

