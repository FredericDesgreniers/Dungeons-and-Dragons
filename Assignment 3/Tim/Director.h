//! @file 
//! @brief Header file for Director class

#pragma once
#include "LivingEntityBuilder.h"
#include "game/LivingEntity.h"

/**
* Director class for LivingEntityBuilder. Manages the construction of characters by concrete livingEntityBuilder classes.
* Stores a level value which is applied to any livingEntityBuilder set as active. 
*/
class Director {
public:
	/**
	* Default constructor. Sets level to 1.
	*/
	Director();
	/**
	* Constructor with level argument.
	*/
	Director(int lvl);
	/**
	* Set a concrete LivingEntityBuilder to use for construction.
	*/
	void setLivingEntityBuilder(LivingEntityBuilder* livingEntityBuilder);
	/**
	* Set the level of the director and apply it to the active builder if applicable.
	*/
	void setLevel(int lvl);
	/**
	* Return a livingEntity created by livingEntityBuilder
	*/
	LivingEntity* getLivingEntity() {return m_LivingEntityBuilder->getLivingEntity();}
	
	/**
	* Construct a living entity using livingEntityBuilder
	*/
	void constructLivingEntity();

private:
	/**
	* The concrete LivingEntityBuilder to use in construction
	*/
	LivingEntityBuilder* m_LivingEntityBuilder;
	/**
	* The level at which to construct characters
	*/
	int level;
};

