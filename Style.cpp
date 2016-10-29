#include "Style.h"
#include "Renderer.h"

Style::Style(int width, int height) : Component(width, height)
{
	
}
Style::Style(int x, int y, int w, int h) : Component(x, y, w, h)
{

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

	Renderer::RenderRect(dimensions.x-padding_left, dimensions.y-padding_top, dimensions.w+padding_left+padding_right, dimensions.h+padding_top+padding_bottom);

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
		Renderer::RenderRectOutline(dimensions.x-padding_left-i, dimensions.y-padding_top-i, dimensions.w+i*2+padding_right+padding_left, dimensions.h+i*2+padding_top+padding_bottom);

}

