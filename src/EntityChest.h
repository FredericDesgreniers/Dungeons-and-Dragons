#pragma once

#include "entity.h"
#include "ItemContainer.h"

/**
* Chest entity with loot container.
*/
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
	/**
	 * Container to store things in
	 */
	ItemContainer* container;
};
