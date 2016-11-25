#pragma once
#include "Strategy.h"
#include "LivingEntity.h"

class Context
{
public:
	Context(Strategy* s);
	void setStrategy(Strategy* s);
	void doStrategy(LivingEntity* le);
private:
	Strategy* strategy;
};
