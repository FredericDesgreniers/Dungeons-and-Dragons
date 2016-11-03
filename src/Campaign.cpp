#include "Campaign.h"

Campaign::Campaign(std::string name): name(name)
{
	
}


std::string Campaign::getFirstMap()
{
	if (maps.size() > 0)
		return maps[0];
	else
		return "default";
}
