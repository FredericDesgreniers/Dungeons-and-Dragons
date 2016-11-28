//! @file 
//! @brief Header file for Character class  
//!
//! Character is the concrete subject
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
	* Characters ability scores     (str,dex,cons,intel,wisd,chari, armorclass, damage, attack)
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
		return "Character scores:\nStr:          "
			+ std::to_string(getStrength()) + "\nDex:          "
			+ std::to_string(getDexterity()) + "\nCons:         "
			+ std::to_string(getConsitution()) + "\nIntel:        "
			+ std::to_string(getIntelligence()) + "\nWisd:         "
			+ std::to_string(getWisdom()) + "\nChari:        "
			+ std::to_string(getCharisma()) + "\nArmor class:  "
			+ std::to_string(getArmorClass()) + "\nDamage:       "
			+ std::to_string(getDamage()) + "\nAttack:       "
			+ std::to_string(getAttack()) + "\nHP:           "
			+ std::to_string(getHitPoints()) + "\n";
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

	bool* getEquipped();
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

	void setArmorClass(int arm);


	void setDamage(int dmg);


	void setAttack(int atk);

	std::string inventoryDisplay();

	bool equipped[7];
};