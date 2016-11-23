//! @file 
//! @brief BullyBuilder header file

#pragma once
#include "LivingEntityBuilder.h"
/**
* Concrete builder for "Bully" type fighters.See LivingEntityBuilder for detailed function descriptions.
*/
class BullyBuilder :
	public LivingEntityBuilder
{
public:
	/**
	* Set stats for bully fighter. 
	* Ability scores are distributed according to the following priority: STR>CON>DEX>INT>CHA>WIS.
	*/
	void buildAbilityScores();
	/**
	* Equip items for a bully fighter. Includes basic equipment and a longsword. 
	*/
	void buildEquipped();
	/**
	* Set name for a bully fighter. Currently sets name to "Bully Fighter" but could be used to select
	* from a list of appropriate names.
	*/
	void buildName();
};

