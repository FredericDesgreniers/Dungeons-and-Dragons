#pragma once
#include "Screen.h"

/**
 * Main menu screen
 */
class ScreenMain : public Screen
{
public:
	/*(*
	 * Main menu screen given a game
	 */
	ScreenMain(Game* game);

	/**
	 * Override render method from screen
	 */
	void render() override;
};
