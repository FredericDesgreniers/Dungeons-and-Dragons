//! @file 
//! @brief Implementation file for the EquipmentWidget namespace  
//!
#include "stdafx.h"
#include "EquipmentWidgets.h"

namespace EquipmentWidgets
{
	//! equips an item to a character
	//! @param Character* : a pointer to the character to decorate
	//! @param Item* : a pointer to the item to equip
	//! @return the resulting character
	Character* equipItem(Character *character, Item *item)
	{
		if (character->validateEquipmentSlot(item->getSlot()))
		{
			item->setDecoratedCharacter(character);
			character = item;
		}

		return character;
	}

	// removes an item from a slot on a character
	//! @param Character : a pointer to the original character that will be affected
	//! @param Character : a pointer to the character that directly affected by the removal
	//! @param EquipmentSlot : the equipment slot to remove an item from
	//! @return the resulting character
	Character* removeItemFromSlot(Character *original, Character *character, Character::EquipmentSlot equipmentSlot)
	{
		if (character->isCharacter())
		{
			return original;
		}

		Character *testSelf = ((Item*)character)->getSelf();
		Character *testItem = ((Item*)character)->getDecoratedCharacter();
		Character *testItemChild = ((Item*)testItem)->getDecoratedCharacter();

		if (testSelf->getSlot() == equipmentSlot)
		{
			return testItem;
		}
		else if (testItem->getSlot() == equipmentSlot)
		{
			((Item*)testSelf)->setDecoratedCharacter(testItemChild);
			return original;
		}

		return removeItemFromSlot(original, testItem, equipmentSlot);
	}
}