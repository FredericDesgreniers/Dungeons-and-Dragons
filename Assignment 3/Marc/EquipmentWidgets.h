//! @file 
//! @brief Header file for the EquipmentWidget namespace.
//!
#pragma once
#include "Character.h"
#include "Item.h"

//! namespace that hosts the functions responsible for equipping and remove items from a character
namespace EquipmentWidgets
{
	Character* equipItem(Character *character, Item *item);
	Character* removeItemFromSlot(Character *original, Character *character, Character::EquipmentSlot equipmentSlot);
}
