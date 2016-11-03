#include "LivingEntity.h"

LivingEntity::LivingEntity(char c):Entity(c)
{
	maxHealth = 100;
	health = 100;
}


bool LivingEntity::hit(int damage)
{
	health -= damage;
	if (health > maxHealth)
		health = maxHealth;
	return health <= 0;
}
