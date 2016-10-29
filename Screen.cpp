#include "Screen.h"
#include "Renderer.h"

Screen::Screen(Game* game):game(game)
{

}

void Screen::render()
{
	SDL_Rect text_rect;
	text_rect.x = 0;
	text_rect.y = 0;
	text_rect.w = 100;
	text_rect.h = 40;

	Renderer::RenderTexture(titleText, &text_rect);

	for(Component* comp:components)
	{
		comp->render();
	}

}

void Screen::tick()
{
	
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

