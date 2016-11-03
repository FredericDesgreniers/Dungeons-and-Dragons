#pragma once
#include "Monster.h"
#include "Map.h"
class Wizard:public Monster
{
public:
	Wizard();

	void simulate(Map* map, Pathfinder* pathfinder) override;

	int getSpellProgress();
private:
	int spellProgress;
};
