#include "Pane.h"

Pane::Pane(int x, int y, int width, int height):Style(x,y,width,height)
{
	
}

void Pane::click(int x, int y)
{
	Style::click(x, y);
	for (Component* c : subComponents)
	{
		c->click(x - c->getPositionX(), y - c->getPositionY());
	}
}


void Pane::keyPressed(SDL_Keycode keycode)
{
	Style::keyPressed(keycode);
	for (Component* c : subComponents)
	{
		c->keyPressed(keycode);
	}
}

void Pane::renderDebug()
{
	Style::renderDebug();
	for (Component* c : subComponents)
	{
		c->renderDebug();
	}
}


void Pane::render()
{
	Style::render();
	for(Component* c:subComponents)
	{
		c->render();
	}
}

void Pane::tick()
{
	Style::tick();
	for (Component* c : subComponents)
	{
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
