#pragma once
#include "Style.h"

/**
 * A component that houses more components
 * Kind of like a mini-Screen
 */
class Pane:public Style
{
public:
	Pane(int x, int y, int width, int height);

	/**
	 * Add component to pane, will automtically adjust the position
	 * So create the component with an x,y relative to this pane
	 */
	void addComponent(Component* comp);
	
	void render() override;
	void tick() override;
	void click(int x, int y) override;
	void keyPressed(SDL_Keycode keycode) override;
	void renderDebug() override;

	~Pane();
private:
	std::vector<Component*> subComponents;
};
