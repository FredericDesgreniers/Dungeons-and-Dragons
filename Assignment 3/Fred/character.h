#pragma once
#include "LivingEntity.h"

/**
 * Character class that extends LivingEntity. Should only be used to the playable character
 */
class Character:public LivingEntity
{
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
	Character(int str, int dex, int cons, int intel, int wisd, int chari, int lvl);


	Character(int str, int dex, int cons, int intel, int wisd, int chari, int lvl, std::string cname);




	/**
	 * Make sure character has abilities within the acceptable range
	 * 
	 * The character is validated if the ability scores are all within the range of [3-18]s
	 */

	bool validateNewCharacter();





};

