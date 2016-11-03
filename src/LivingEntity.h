#pragma once
#include "entity.h"

class LivingEntity :public Entity {
public:
	LivingEntity(char c);
	int getMaxHealth()
	{
		return maxHealth;
	}

	int getHealth()
	{
		return health;
	}

	bool hit(int damage);

private:
	int maxHealth;
	int health;
};