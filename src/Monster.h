#pragma once
#include "LivingEntity.h"

class Monster:public LivingEntity
{
public:
	Monster();
	void simulate(Map* map, Pathfinder* pathfinder) override;

	bool interact(Map* map, Entity* entity) override;
};
