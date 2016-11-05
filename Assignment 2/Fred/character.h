#pragma once
#include "stdlib.h"
#include "time.h"
#include <string>
#include "Subject.h"

/**
 * Character class
 */
class Character:public Subject
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
	* Output string to ostream using <<
	*/
	inline std::string toString(){
		return "Level: "+std::to_string(level)+"\n str:" + std::to_string(getStrength()) + "\n dex:" + std::to_string(getDexterity()) + "\n cons:" + std::to_string(getConsitution()) + "\n intel:" + std::to_string(getIntelligence()) + "\n wisd:" + std::to_string(getWisdom()) + "\n chari:" + std::to_string(getCharisma());

	}

	/**
	 * Get level as int
	 */
	int getLevel()
	{
		return level;
	}
	/**
	 * Set level
	 */
	void setLevel(int level);

	/**
	 * Get hit points as int
	 */
	int getHitPoints()
	{
		return hitpoints;
	}
	/**
	 * Set hitpints
	 */
	void setHitPoints(int hitpoints);

	/**
	 * Get Strength as int
	 */
	int getStrength()
	{
		return abilityscores[0];
	} 
	/**
	 *Set strength
	 */
	void setStrength(int strength);
	/**
	 * Get dexterity as int
	 */
	int getDexterity()
	{
		return abilityscores[1];
	}
	/**
	 * Set dexterity
	 */
	void setDexterity(int dexterity);
	/**
	 * Get constitution as int
	 */
	int getConsitution()
	{
		return abilityscores[2];
	} 
	/**
	 * Set constitution
	 */
	void setConstitution(int constitution);
	/**
	 * Get inteligence as int
	 */
	int getIntelligence()
	{
		return abilityscores[3];
	} 
	/**
	 * Setr intelligence
	 */
	void setIntelligence(int intelligence);
	/**
	 * Get wisdom as int
	 */
	int getWisdom()
	{
		return abilityscores[4];
	} 
	/**
	 * Set wisdom
	 */
	void setWisdom(int wisdom);
	/**
	 * Get charisma as int
	 */
	int getCharisma()
	{
		return abilityscores[5];
	}
	/**
	 * Set charisma
	 */
	void setCharisma(int charisma);

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
};

