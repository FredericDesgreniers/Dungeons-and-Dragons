#include "Screen.h"
#include "Renderer.h"

Screen::Screen(Game* game):game(game)
{

}

void Screen::render()
{

	for(Component* comp:components)
	{
		comp->render();
	}

}

void Screen::tick()
{
	for (Component* comp : components)
		comp->tick();
}




void Screen::click(int x, int y)
{
	for (Component* c : components)
		if (c->isInBounds(x, y))
		{
			c->click(x - c->getPositionX(), y - c->getPositionY());
		}
		
}

Screen::~Screen()
{
	Renderer::destroyTexture(titleText);
}

