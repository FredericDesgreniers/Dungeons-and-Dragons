#pragma once
#include "entity.h"

class LivingEntity :public Entity {
public:
	LivingEntity(char c);
	int getMaxHealth();

	int getHealth();

	bool hit(int damage);

private:
	int maxHealth;
	int health;
};