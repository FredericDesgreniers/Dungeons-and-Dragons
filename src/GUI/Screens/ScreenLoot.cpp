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
	toContainer->setBorderColor_both(255, 255, 255, 255);
	toContainer->setBorderSize(1);

	ItemContainerComponent* fromContainer = new ItemContainerComponent(from, 330, 0, 300, 900);
	fromContainer->addOnItemClick_callback([this, to, from](Item* item, int index)
	{
		if (item != nullptr)
		{
			to->addItem(item);
			from->removeItemAtIndex(index);
		}
	});
	fromContainer->setBorderColor_both(255, 255, 255, 255);
	fromContainer->setBorderSize(1);

	addComponent(toContainer);
	addComponent(fromContainer);
}
