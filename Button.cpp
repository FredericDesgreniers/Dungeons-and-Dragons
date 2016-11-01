#include "Button.h"
#include <SDL/SDL.h>
#include "Renderer.h"

Button::Button(std::string text, Font* font, int x, int y,int width, int height):Style(x, y, width, height), text(text), font(font)
{

	texture = Renderer::CreateTexture(text, font->get(fontSize), { 0,0,0,255 });
	setFontColor(255, 255, 255, 255);

	setBackgroundColor_both(255, 255, 255, 0);

	setFontUnderlineColor_hover(255, 255, 255, 255);
	setFontUnderline_hover(1);

	setPadding(10);

}

void Button::render()
{
	int mx, my;

	SDL_GetMouseState(&mx, &my);
	bool hover = isInBounds(mx, my);

	drawDefaultStyle(hover);

	Renderer::RenderTexture(texture, &dimensions);

	if(hover && fontUnderline_hover > 0)
	{
		Renderer::setColor(fontUnderlineColor_hover);
		Renderer::drawLine(dimensions.x, dimensions.y + dimensions.h, dimensions.x + dimensions.w, dimensions.y + dimensions.h);

	}else if (fontUnderline > 0)
	{
		Renderer::setColor(fontUnderlineColor);
		Renderer::drawLine(dimensions.x, dimensions.y + dimensions.h, dimensions.x + dimensions.w, dimensions.y + dimensions.h);
	}
}

void Button::setFontColor(int r, int g, int b, int a)
{
	Style::setFontColor(r, g, b, a);
	reloadTexture();
}

void Button::setFontSize(int size)
{
	Style::setFontSize(size);
	reloadTexture();
}

void Button::reloadTexture()
{
	Renderer::destroyTexture(texture);
	texture = Renderer::CreateTexture(text, font->get(fontSize), fontColor);
}


Button::~Button()
{
	Renderer::destroyTexture(texture);
}
