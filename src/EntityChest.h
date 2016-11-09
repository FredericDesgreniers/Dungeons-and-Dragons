#pragma once

#include "entity.h"
#include "ItemContainer.h"

class EntityChest:public Entity
{
public:
	/**
	 * Create default chest
	 */
	EntityChest();

	/**
	 * Get chest container
	 */
	ItemContainer* getContainer();
private:
	ItemContainer* container;
};
