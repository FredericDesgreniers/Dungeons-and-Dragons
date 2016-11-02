#include "Campaign.h"

Campaign::Campaign(std::string name): name(name)
{
	
}


Map* Campaign::getFirstMap()
{
	if (maps.size() > 0)
		return maps[0];
	else
		return new Map(25, 25);
}
