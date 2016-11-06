//! @file 
//! @brief Header file for Character class  
//!
//! Character is the concrete subject
#pragma once
#include "stdlib.h"
#include "time.h"
#include <string>
#include "Subject.h"

/**
* Character class
*/
class Character : public Subject
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
	* Characters ability scores     (str,dex,cons,intel,wisd,chari)
	*/
	int abilityscores[6];

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

	Character(int str, int dex, int cons, int intel, int wisd, int chari);
	/**
	* Get modifer from ability score.
	*
	* The modifier is calculated as per game rules using (score-10)/2
	*/
	int getModifier(int);

	/**
	* Hit character for x hp.
	*
	* Deduces the health and notify the observer that something has changed
	*/
	void hit(int);

	/**
	* Make sure character has abilities within the acceptable range
	*
	* The character is validated if the ability scores are all within the range of [3-18]s
	*/
	bool validateNewCharacter();

	/**
	* Output string to ostream using <<
	*/
	inline std::string Character::toString() {
		return "str:" + std::to_string(getStrength()) + ", dex:" + std::to_string(getDexterity()) + ", cons:" + std::to_string(getConsitution()) + ", intel:" + std::to_string(getIntelligence()) + ", wisd:" + std::to_string(getWisdom()) + ", chari:" + std::to_string(getCharisma()) + ", HP:" + std::to_string(getHitPoints());

	}

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
	* set strength and notify the observer that something has changed
	*/
	void setStrength(int str);

	/**
	* set dexterity and notify the observer that something has changed
	*/
	void setDexterity(int dex);

	/**
	* set constitution and notify the observer that something has changed
	*/
	void setConsitution(int cons);

	/**
	* set intelligence and notify the observer that something has changed
	*/
	void setIntelligence(int intel);

	/**
	* set wisdom and notify the observer that something has changed
	*/
	void setWisdom(int wis);

	/**
	* set charisma and notify the observer that something has changed
	*/
	void setCharisma(int cha);
};