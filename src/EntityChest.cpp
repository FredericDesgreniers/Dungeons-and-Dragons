#include "EntityChest.h"

EntityChest::EntityChest() :Entity('B')
{
	container = new ItemContainer("Chest", 20);
}

ItemContainer* EntityChest::getContainer()
{
	return container;
}
