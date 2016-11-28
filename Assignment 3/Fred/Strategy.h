#pragma once
#include "LivingEntity.h"
class LivingEntity;
class Map;
/**
 * Strategy class.
 * 
 * This is used to implement strategies for entities on a map
 */
class Strategy
{
public:
	/**
	 * Do the specified strategy
	 */
	virtual void doStrategy(Map* map, LivingEntity* le);
};

/**
 * A friendly strategy.
 * 
 * Entity goes towards the player but does not attack
 */
class FriendlyStrategy :public Strategy
{
public:
	void doStrategy(Map* map, LivingEntity* le);
};
/**
 * A hostile strategy
 * 
 * Entity goes towards a player and attacks if close enough
 */
class HostileStrategy :public Strategy
{
public:
	void doStrategy(Map* map, LivingEntity* le);
};
/**
 * A character strategy
 * 
 * Entity moves / interacts depding on output
 */
class CharacterStrategy :public Strategy
{
public:
	void doStrategy(Map* map, LivingEntity* le);
};