//! @file 
//! @brief Header file for TankBuilder class
#pragma once
#include "LivingEntityBuilder.h"
/**
* Concrete builder for "Tank" type fighters.See LivingEntityBuilder for detailed function descriptions.
*/
class TankBuilder :
	public LivingEntityBuilder
{
public:
	/**
	* Set stats for tank fighter.
	* Ability scores are distributed according to the following priority: CON>DEX>STR>INT>CHA>WIS.
	*/
	void buildAbilityScores();
	/**
	* Equip items for a tank fighter. Includes basic equipment and a mace.
	*/
	void buildEquipped();
	/**
	* Set name for a tank fighter. Currently sets name to "Tank Fighter" but could be used to select
	* from a list of appropriate names.
	*/
	void buildName();
};

