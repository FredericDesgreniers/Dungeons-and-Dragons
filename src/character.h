#pragma once

#include <string>

#include "LivingEntity.h"

/**
 * Character class
 */
class Character:public LivingEntity
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
	 * Make sure character has abilities within the acceptable range
	 * 
	 * The character is validated if the ability scores are all within the range of [3-18]s
	 */
	bool validateNewCharacter();

	/**
	* Output string to ostream using <<
	*/
	inline std::string toString(){
		return "str:" + std::to_string(getStrength()) + ", dex:" + std::to_string(getDexterity()) + ", cons:" + std::to_string(getConsitution()) + ", intel:" + std::to_string(getIntelligence()) + ", wisd:" + std::to_string(getWisdom()) + ", chari:" + std::to_string(getCharisma());

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

	int* getAbilityScoreArray();

};

