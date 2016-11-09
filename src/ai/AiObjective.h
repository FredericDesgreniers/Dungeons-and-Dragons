#pragma once


#include "../LivingEntity.h"
class Map;
class LivingEntity;


class AiObjective
{
public:
	AiObjective(double);
	bool getFinished();

	double getRating(Map* map, double aggressivity);

	virtual void runObjective(Map* map);
private:
	bool finished;
	double mentalScale;
};


