#pragma once

#include <string>

#include "LivingEntity.h"
#include "dice.h"
#include <fstream>
#include <iostream>

/**
 * Character class that extends LivingEntity. Should only be used to the playable character
 */
class Character:public LivingEntity
{


private:


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


	/*
	 * Loads a character from file given a name. (Do not suply an file extension with the name)
	 */
	static Character* Character::loadCharacter(std::string name);

	/**
	 * Save a chracter to file given a name and a character instance. Name  should be without file extension
	 */
	static bool saveCharacter(std::string name, Character * character);

	SDL_Color getDisplayColor();

};

