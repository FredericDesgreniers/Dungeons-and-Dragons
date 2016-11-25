#pragma once
#include "LivingEntity.h"
class LivingEntity;
class Map;
class Strategy
{
public:
	virtual void doStrategy(Map* map, LivingEntity* le);
};


class FriendlyStrategy :public Strategy
{
public:
	void doStrategy(Map* map, LivingEntity* le);
};

class HostileStrategy :public Strategy
{
public:
	void doStrategy(Map* map, LivingEntity* le);
};

class CharacterStrategy :public Strategy
{
public:
	void doStrategy(Map* map, LivingEntity* le);
};