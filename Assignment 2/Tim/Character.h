//! @file 
//! @brief Header file for the Character class 
//!

#pragma once
#include "dice.h"
#include "Subject.h"
/**
 * 
 */

 //!  Character class 
 /*!
 Character class for both player characters and monsters. Contains ability scores, level, 
 current and max health with appropriate accessors and mutators. For this assignment, some aspects of character class used in project 
 but not included in assignment 1, such as equipped items, were removed from the class to reduce dependencies and streamline testing of 
 the observer class. 

 Derived from Subject class for Attach(), Detatch(), Notify(), and list of observers.
 Dice class is used for randomizing character stats when using the default constructor
 */
class Character : public Subject
{
public:
	Character();
	Character(int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int lvl);

	/**
	* Gets max Character health
	*/
	int getMaxHealth();

	/**
	 * Get current health
	 */
	int getHealth();

	/**
	 * Hit Character for some damage 
	 */
	bool hit(int damage);

	/**
	* Get level as int
	*/
	int getLevel();
	/**
	* Get Strength as int
	*/
	int getStrength();
	/**
	* Get dexterity as int
	*/
	int getDexterity();
	/**
	* Get constitution as int
	*/
	int getConstitution();
	/**
	* Get inteligence as int
	*/
	int getIntelligence();
	/**
	* Get wisdom as int
	*/
	int getWisdom();
	/**
	* Get charisma as int
	*/
	int getCharisma();

	/**
	* Set level as int
	*/
	void setLevel(int value);
	/**
	* Set Strength as int
	*/
	void setStrength(int value);
	/**
	* Set dexterity as int
	*/
	void setDexterity(int value);
	/**
	* Set constitution as int
	*/
	void setConstitution(int value);
	/**
	* Set inteligence as int
	*/
	void setIntelligence(int value);
	/**
	* Set wisdom as int
	*/
	void setWisdom(int value);
	/**
	* Set charisma as int
	*/
	void setCharisma(int value);



	/**
	* Return array holding Character's ability scores
	*/
	int* getAbilityScoreArray();

	std::string toString() {
	
		return "LVL:" + std::to_string(getLevel()) + ", STR:" + std::to_string(getStrength()) + ", DEX:" + std::to_string(getDexterity()) + ", CON:" + std::to_string(getConstitution()) +
			", INT:" + std::to_string(getIntelligence()) + ", WIS:" + std::to_string(getWisdom()) + ", CHA:" + std::to_string(getCharisma());
		}
	


private:
	int maxHealth;
	int health;
	/**
	* Character's level
	*/
	int level;
	/**
	* Character's ability scores (str,dex,con,int,wis,cha)
	*/
	int abilityscores[6];
};