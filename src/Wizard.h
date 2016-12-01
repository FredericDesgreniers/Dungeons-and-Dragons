#pragma once
#include "Monster.h"
#include "Map.h"
/**
 * Wizard monster type
 */
class Wizard:public Monster
{
public:
	/**
	 * Create a default wizard
	 */
	Wizard();

	/**
	 * Get progress of currently casting spell
	 */
	int getSpellProgress();

	SDL_Color getDisplayColor();
private:
	int spellProgress;
};
