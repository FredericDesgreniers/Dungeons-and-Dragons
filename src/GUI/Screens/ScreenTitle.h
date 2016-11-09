#pragma once
#include "Screen.h"
/**
 * Title screen for game
 */
class ScreenTitle : public Screen
{
public:
	/**
	 * Constructor given game
	 */
	ScreenTitle(Game* game);
	/**
	 * Override render method
	 */
	void render() override;
	/**
	 * overrude tick method
	 */
	void tick() override;
private:
	long ticksSinceStart;
	Button* button;
};
