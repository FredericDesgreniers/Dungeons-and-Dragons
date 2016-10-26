#include "Screen.h"
#include "Renderer.h"

Screen::Screen()
{
	SDL_Color whiteColor = { 255,255,255 };
	titleText = Renderer::CreateTexture("d&d game", Renderer::FONT_ROBOTO_24, whiteColor);

}

void Screen::render()
{
	SDL_Rect text_rect;
	text_rect.x = 0;
	text_rect.y = 0;
	text_rect.w = 100;
	text_rect.h = 40;

	Renderer::RenderTexture(titleText, &text_rect);
}

void Screen::tick()
{
	
}

Screen::~Screen()
{
	Renderer::destroyTexture(titleText);
}

