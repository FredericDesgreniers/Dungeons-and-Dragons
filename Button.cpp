#include "Button.h"
#include <SDL/SDL.h>
#include "Renderer.h"

Button::Button(int id, std::string text, int x, int y,int width, int height):Style(x, y, width, height), id(id), text(text)
{

	texture = Renderer::CreateTexture(text, Renderer::FONT_ROBOTO_24, { 0,0,0,255 });

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
	Renderer::destroyTexture(texture);
	texture = Renderer::CreateTexture(text, Renderer::FONT_ROBOTO_24, fontColor);
}

Button::~Button()
{
	Renderer::destroyTexture(texture);
}
