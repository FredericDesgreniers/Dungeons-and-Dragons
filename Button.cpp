#include "Button.h"
#include <SDL/SDL.h>
#include "Renderer.h"

Button::Button(int id, std::string text, int x, int y,int width, int height):Style(x, y, width, height), id(id), text(text), x(x), y(y), height(height), width(width)
{
	
	texture = Renderer::CreateTexture(text, Renderer::FONT_ROBOTO_24, { 0,0,0,255 });

}

void Button::render()
{
	int mx, my;

	SDL_GetMouseState(&mx, &my);
	bool hover = isInBounds(mx, my);

	drawDefaultStyle(hover);



	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	Renderer::RenderTexture(texture, &rect);
}

void Button::setFontColor(int r, int g, int b, int a)
{
	Style::setFontColor(r, g, b, a);
	Renderer::destroyTexture(texture);
	texture = Renderer::CreateTexture(text, Renderer::FONT_ROBOTO_24, fontColor);
}

Button::~Button()
{
	Renderer::destroyTexture(texture);
}
