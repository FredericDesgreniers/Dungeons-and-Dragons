#pragma once
#include "LivingEntity.h"

/**
 * An entity that seeks out the player to kill him
 */
class Monster:public LivingEntity
{
public:
	Monster();

	
	/**
	 * Simulate monster Ai. Goes towards player if player is close, otherwise goes in random directions
	 */
	void simulate(Map* map, Pathfinder* pathfinder) override;

	/**
	 * Called when it gets interacted with
	 * If Entity is a Character, monster will take damage
	 */
	bool interact(Map* map, Entity* entity) override;

protected:
	Monster(char c);
};
