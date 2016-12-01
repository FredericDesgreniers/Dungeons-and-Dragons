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
	 * Simluate a map tick for this entity given a map and a pathfinder to where the entity should go
	 */
	void simulate(Map* map, Pathfinder* pathfinder) override;

	/**
	 * Get progress of currently casting spell
	 */
	int getSpellProgress();

	SDL_Color getDisplayColor();
private:
	int spellProgress;
};
