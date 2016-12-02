#pragma once
#include "Style.h"

/**
 * A component that houses more components
 * Kind of like a mini-Screen
 */
class Pane:public Style
{
public:
	/**
	 * Constructor given an x,y positon and a width, height
	 */
	Pane(int x, int y, int width, int height);

	/**
	 * Add component to pane, will automtically adjust the position
	 * So create the component with an x,y relative to this pane
	 */
	void addComponent(Component* comp);
	/**
	 * Clear sub components, no not call during component loop
	 */
	void clearComponents();
	/**
	 * Override render method
	 */
	void render() override;
	/**
	 * Override tick method
	 */
	void tick() override;
	/**
	 * Override click method
	 */
	void click(int x, int y) override;
	/**
	 * Override key pressed method
	 */
	void keyPressed(SDL_Keycode keycode) override;
	/**
	 * Override renderDebug method
	 */
	void renderDebug() override;

	~Pane();
private:
	/**
	 * Component list of inside the pane
	 */
	std::vector<Component*> subComponents;
};
