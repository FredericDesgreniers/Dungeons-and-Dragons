#pragma once

#include "entity.h"
#include "ItemContainer.h"

class EntityChest:public Entity
{
public:
	EntityChest();

	ItemContainer* getContainer();
private:
	ItemContainer* container;
};
