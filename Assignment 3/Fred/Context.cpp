#include "Context.h"

Context::Context(Strategy* s):strategy(s)
{
	
}
void Context::setStrategy(Strategy* s)
{
	strategy = s;
}

void Context::doStrategy(LivingEntity* le)
{
	if(strategy != nullptr)
	{
		strategy->doStrategy(nullptr, le);
	}
}

