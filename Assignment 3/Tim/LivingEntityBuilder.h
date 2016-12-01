//! @file 
//! @brief Header file for LivingEntityBuilder class
#pragma once
#include "game/LivingEntity.h"
#include "game/dice.h"
#include <algorithm>

/**
* Abstract class that acts as blueprint for all concrete LivingEntityBuilder classes. 
* Implements some functions common to all children.
* 
*/
class LivingEntityBuilder
{
public:
	/**
	* Return the created character
	*/
	LivingEntity* getLivingEntity() { return m_livingEntity; }
	/**
	* Create a generic blank character. Instantiates a LivingEntity using the default LivingEntity constructor
	*/
	void createNewLivingEntity() { m_livingEntity = new LivingEntity; }
	/**
	* Roll the character's ability scores. Rolls 4d6 and subtracts the lowest result. Repeats 6 times to create an array
	* of ability scores, then distributes them appropriately based on the concrete builder used. 
	* Roll hitpoints and set secondary stats based on ability score distribution.
	*/
	virtual void buildAbilityScores() = 0;
	/**
	* Equip the character with basic items. Currently all archetypes use the same equipment except
	* for weapons. This may be expanded upon to equip different types of armor for each 
	* archetype and add level scaling.
	*/
	virtual void buildEquipped() = 0;
	
	/**
	* Give the created character an appropriate name for the chosen archetype. 
	*/
	virtual void buildName() = 0;

	/**
	* Set the level of the concrete builder. All created characters will be created at this level (default is 1)
	*/
	void setLevel(int lvl) { level=lvl;}
	

protected:
	/**
	* The living entity being built
	*/
	LivingEntity* m_livingEntity;
	/**
	* The level at which to create new characters
	*/
	int level=1;
};

