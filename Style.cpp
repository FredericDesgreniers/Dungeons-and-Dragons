#include "Style.h"
#include "Renderer.h"

Style::Style(SDL_Rect rect) : dimensions(rect)
{
	
}
Style::Style(int x, int y, int w, int h)
{
	dimensions.x = x;
	dimensions.y = y;
	dimensions.w = w;
	dimensions.h = h;
}


void Style::drawDefaultStyle(bool hover)
{
	drawBackground(hover);
	drawBorder(hover);
}

void Style::drawBackground(bool hover)
{
	//draw background
	if (hover)
		Renderer::setColor(backgroundColor_hover);
	else
		Renderer::setColor(backgroundColor);

	Renderer::RenderRect(dimensions.x, dimensions.y, dimensions.w, dimensions.h);

}

void Style::drawBorder(bool hover)
{
	if (borderSize <= 0)
		return;

	//draw background
	if (hover)
		Renderer::setColor(borderColor_hover);
	else
		Renderer::setColor(borderColor);

	for (int i = 1; i <= borderSize; i++)
		Renderer::RenderRectOutline(dimensions.x-i, dimensions.y-i, dimensions.w+i*2, dimensions.h+i*2);

}


