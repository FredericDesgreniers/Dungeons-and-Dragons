#pragma once
#include "entity.h"
/**
 * Extends entity, meant for anything that has health and is "living"
 */
class LivingEntity :public Entity {
public:
	LivingEntity(char c);
	/**
	 * Gets max entity health
	 */
	int getMaxHealth();

	/**
	 * Get current healths
	 */
	int getHealth();

	/**
	 * Hit entity for some damage 
	 */
	bool hit(int damage);

private:
	int maxHealth;
	int health;
};