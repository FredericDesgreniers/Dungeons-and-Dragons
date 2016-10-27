#include "Button.h"
#include <SDL/SDL.h>
#include "Renderer.h"

Button::Button(int id, std::string text, int x, int y,int width, int height):id(id), text(text), x(x), y(y), height(height), width(width)
{
	texture = Renderer::CreateTexture(text, Renderer::FONT_ROBOTO_24, { 0,0,0,255 });
}

void Button::render()
{
	int mx, my;

	SDL_GetMouseState(&mx, &my);


	if(isInBounds(mx,my))
		Renderer::setColor(217,217,217,255);
	else
		Renderer::setColor(255,255,255,255);

	Renderer::RenderRect(x, y, width, height);

	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	Renderer::RenderTexture(texture, &rect);
}


Button::~Button()
{
	Renderer::destroyTexture(texture);
}
