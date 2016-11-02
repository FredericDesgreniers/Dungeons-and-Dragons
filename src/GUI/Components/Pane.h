#pragma once
#include "Style.h"

class Pane:public Style
{
public:
	Pane(int x, int y, int width, int height);
	void addComponent(Component* comp)
	{
		comp->setPositionX(comp->getPositionX() + getPositionX());
		comp->setPositionY(comp->getPositionY() + getPositionY());
		subComponents.push_back(comp);
	}

	void render() override;
	void tick() override;
	void click(int x, int y) override;
	void keyPressed(SDL_Keycode keycode) override;
	void renderDebug() override;

	~Pane();
private:
	std::vector<Component*> subComponents;
};
