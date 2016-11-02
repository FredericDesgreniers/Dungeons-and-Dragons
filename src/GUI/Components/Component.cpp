#include "Component.h"

#include "../Renderer.h"


Component::Component(int width, int height)
{
	dimensions.w = width;
	dimensions.h = height;
}

Component::Component(int positionX, int positionY, int width, int height) : Component(width, height)
{
	

	dimensions.x = positionX;
	dimensions.y = positionY;
	
}

void Component::render()
{
	
}

void Component::tick()
{
	
}

void Component::renderDebug()
{
	Renderer::setColor(255, inFocus?255:0, 0, 255);
	Renderer::RenderRectOutline(dimensions.x, dimensions.y, dimensions.w, dimensions.h);

}
void Component::keyPressed(SDL_Keycode keycode)
{
	
}
void Component::click(int x, int y)
{
	int mx, my;
	SDL_GetMouseState(&mx, &my);
	if (isInBounds(mx,my)) {
		setInFocus(true);
		for (std::function<void(Component*, int, int)> func : onClick_callbacks)
		{
			func(this, x, y);
		}
	}
	else
	{
		setInFocus(false);
	}
}

Component::~Component()
{
	
}
