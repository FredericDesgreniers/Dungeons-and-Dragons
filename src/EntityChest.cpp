#include "EntityChest.h"

EntityChest::EntityChest():Entity('B')
{
	
}

ItemContainer* EntityChest::getContainer()
{
	return &container;
}
