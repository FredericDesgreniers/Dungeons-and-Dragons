#pragma once
#include "Screen.h"
#include "../../Campaign.h"
/**
 * Screen to select a character to play on a campaign
 */
class ScreenCharacterSelect:public Screen
{
public:
	/**
	 * Constructor to select a player given a game instance and a campaign to play
	 */
	ScreenCharacterSelect(Game* game, Campaign* campaign);

	/**
	 * Render override for screen
	 */
	void render() override;

private:
	Campaign* campaign;
};
