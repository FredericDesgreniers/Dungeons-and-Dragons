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

	for(Button* b: buttons)
	{
		b->render();
	}

}

void Screen::tick()
{
	
}

void Screen::onButtonClicked(Button* b)
{
	
}



void Screen::click(int x, int y)
{
	for (Button* b : buttons)
		if (b->isInBounds(x, y))
		{
			onButtonClicked(b);
			return;
		}
		
}

Screen::~Screen()
{
	Renderer::destroyTexture(titleText);
}

