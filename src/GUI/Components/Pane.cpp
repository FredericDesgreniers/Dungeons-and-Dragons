#include "Pane.h"

Pane::Pane(int x, int y, int width, int height):Style(x,y,width,height)
{
	
}

void Pane::click(int x, int y)
{
	Style::click(x, y);
	for (Component* c : subComponents)
	{
		if (c->isVisible())
		c->click(x - c->getPositionX(), y - c->getPositionY());
	}
}

void Pane::clearComponents()
{
	subComponents.clear();
}

void Pane::keyPressed(SDL_Keycode keycode)
{
	Style::keyPressed(keycode);
	for (Component* c : subComponents)
	{
		if (c->isVisible())
		c->keyPressed(keycode);
	}
}

void Pane::renderDebug()
{
	Style::renderDebug();
	for (Component* c : subComponents)
	{
		if (c->isVisible())
		c->renderDebug();
	}
}

void Pane::addComponent(Component* comp)
{
	comp->setPositionX(comp->getPositionX() + getPositionX());
	comp->setPositionY(comp->getPositionY() + getPositionY());
	subComponents.push_back(comp);
}

void Pane::render()
{
	Style::render();
	for(Component* c:subComponents)
	{
		if(c->isVisible())
		c->render();
	}
}

void Pane::tick()
{
	Style::tick();
	for (Component* c : subComponents)
	{
		if (c->isVisible())
		c->tick();
	}
}



Pane::~Pane()
{
	for (Component* c : subComponents)
	{
		delete c;
	}
}
