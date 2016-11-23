//! @file 
//! @brief Header file for NimbleBuilder class
#pragma once
#include "LivingEntityBuilder.h"
/**
* Concrete builder for "Nimble" type fighters.See LivingEntityBuilder for detailed function descriptions.
*/
class NimbleBuilder :
	public LivingEntityBuilder
{
public:
	/**
	* Set stats for nimble fighter.
	* Ability scores are distributed according to the following priority: DEX>CON>STR>INT>CHA>WIS.
	*/
	void buildAbilityScores();
	/**
	* Equip items for a nimble fighter. Includes basic equipment and a dagger.
	*/
	void buildEquipped();
	/**
	* Set name for a nimble fighter. Currently sets name to "Nimble Fighter" but could be used to select
	* from a list of appropriate names.
	*/
	void buildName();

};

