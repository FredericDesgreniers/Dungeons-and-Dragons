//! @file 
//! @brief Header file for Character class  
//!
//! Extends the abstract character class for Decorator pattern
#pragma once
#include "stdlib.h"
#include "time.h"
#include <string>
#include "AbstractCharacter.h"
#include "CharacterDecorator.h"

/**
* Character class
*/
class Character : public AbstractCharacter
{

private:
	/**
	* Characters level
	*/
	int level;
	/**
	* Characters hitpoint
	*/
	int hitpoints;

	/**
	* Characters ability scores (str,dex,cons,intel,wisd,chari, armorclass, damage, attack)
	*/
	int abilityscores[9];



public:
	/**
	* Level constructor
	* Assigns random ability scores
	*/
	Character(int level);
	/**
	* Ability Score Constructor
	* Assigns ability scores to character
	*
	* As per the game rules, each ability is generated in the [3-18] range
	*/

	Character(int str, int dex, int cons, int intel, int wisd, int chari, int armor, int damage, int attack);
	/**
	* Get modifer from ability score.
	*
	* The modifier is calculated as per game rules using (score-10)/2
	*/
	int getModifier(int);

	/**
	* Hit character for x hp.
	*
	* Deduces the health
	*/
	void hit(int);

	/**
	* Make sure character has abilities within the acceptable range
	*
	* The character is validated if the ability scores are all within the range of [3-18]s
	*/
	bool validateNewCharacter();

	/**
	* Output String
	*/
	std::string toString();

	/**
	* Get level as int
	*/
	int getLevel();

	/**
	* Get hit points as int
	*/
	int getHitPoints();

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
	int getConsitution();

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
	* Get ability score array
	*/
	int* getAbilityScoreArray();

	/**
	* Get armor class as int
	*/
	int getArmorClass();

	/**
	* Get damage as int
	*/
	int getDamage();

	/**
	* Get attack as int
	*/
	int getAttack();

	/**
	* Get the equipped items as an array
	*/
	bool* getEquipped();
	/**
	* set strength
	*/
	void setStrength(int str);

	/**
	* set dexterity
	*/
	void setDexterity(int dex);

	/**
	* set constitution 
	*/
	void setConsitution(int cons);

	/**
	* set intelligence
	*/
	void setIntelligence(int intel);

	/**
	* set wisdom
	*/
	void setWisdom(int wis);

	/**
	* set charisma
	*/
	void setCharisma(int cha);

	/**
	* set armor
	*/
	void setArmorClass(int arm);

	/**
	* set damage
	*/
	void setDamage(int dmg);
	
	/**
	* set attack
	*/
	void setAttack(int atk);

	/**
	* display inventory
	*/
	std::string inventoryDisplay();

	/**
	* bool array of equipped items
	*/
	bool equipped[7];

};