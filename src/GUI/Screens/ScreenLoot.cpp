#include "ScreenLoot.h"
#include "../Components/ItemContainerComponent.h"

ScreenLoot::ScreenLoot(Game* game, ItemContainer* to, ItemContainer* from):Screen(game)
{
	ItemContainerComponent* toContainer = new ItemContainerComponent(to, 0, 0, 300, 900);
	toContainer->addOnItemClick_callback([this,to, from](Item* item, int index)
	{
		if (item != nullptr)
		{
			from->addItem(item);
			to->removeItemAtIndex(index);
		}
	});

	ItemContainerComponent* fromContainer = new ItemContainerComponent(from, 1000, 0, 300, 900);
	fromContainer->addOnItemClick_callback([this, to, from](Item* item, int index)
	{
		if (item != nullptr)
		{
			to->addItem(item);
			from->removeItemAtIndex(index);
		}
	});

	addComponent(toContainer);
	addComponent(fromContainer);
}
