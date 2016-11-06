#pragma once
#include "stdlib.h"
#include "time.h"
#include <string>
#include "Subject.h"

/**
 *\brief Character class to store information on character
 * Character class
 */
class Character:public Subject
{



public:
	/**
	 * \brief Level constructor
	 * Assigns random ability scores
	 */
	Character(int level);
	/**
	 * \brief Ability Score Constructor
	 * Assigns ability scores to character
	 * 
	 * As per the game rules, each ability is generated in the [3-18] range
	 */
	Character(int str, int dex, int cons, int intel, int wisd, int chari);
	/**
	 * \brief Get modifer from ability score.
	 * 
	 * The modifier is calculated as per game rules using (score-10)/2
	 */
	int getModifier(int);

	/**
	 * \brief Hit character for x hp.
	 * 
	 * Deduces the health 
	 */
	void hit(int);

	/**
	 * \brief Make sure character has abilities within the acceptable range
	 * 
	 * The character is validated if the ability scores are all within the range of [3-18]s
	 */
	bool validateNewCharacter();

	/**
	* \brief Output string to ostream using <<
	*/
	inline std::string toString(){
		return "Level: "+std::to_string(level)+"\n str:" + std::to_string(getStrength()) + "\n dex:" + std::to_string(getDexterity()) + "\n cons:" + std::to_string(getConsitution()) + "\n intel:" + std::to_string(getIntelligence()) + "\n wisd:" + std::to_string(getWisdom()) + "\n chari:" + std::to_string(getCharisma());

	}

	/**
	 * \brief Get level as int
	 */
	int getLevel()
	{
		return level;
	}
	/**
	 * \brief Set level
	 */
	void setLevel(int level);

	/**
	 * \brief Get hit points as int
	 */
	int getHitPoints()
	{
		return hitpoints;
	}
	/**
	 * \brief Set hitpints
	 */
	void setHitPoints(int hitpoints);

	/**
	 * \brief Get Strength as int
	 */
	int getStrength()
	{
		return abilityscores[0];
	} 
	/**
	 *\brief Set strength
	 */
	void setStrength(int strength);
	/**
	 * \brief Get dexterity as int
	 */
	int getDexterity()
	{
		return abilityscores[1];
	}
	/**
	 * \brief Set dexterity
	 */
	void setDexterity(int dexterity);
	/**
	 * \brief Get constitution as int
	 */
	int getConsitution()
	{
		return abilityscores[2];
	} 
	/**
	 * \brief Set constitution
	 */
	void setConstitution(int constitution);
	/**
	 * \brief Get inteligence as int
	 */
	int getIntelligence()
	{
		return abilityscores[3];
	} 
	/**
	 * \brief Setr intelligence
	 */
	void setIntelligence(int intelligence);
	/**
	 * \brief Get wisdom as int
	 */
	int getWisdom()
	{
		return abilityscores[4];
	} 
	/**
	 * \brief Set wisdom
	 */
	void setWisdom(int wisdom);
	/**
	 * \brief Get charisma as int
	 */
	int getCharisma()
	{
		return abilityscores[5];
	}
	/**
	 * \brief Set charisma
	 */
	void setCharisma(int charisma);

	private:
		/**
		* \brief Characters level
		*/
		int level;
		/**
		* \brief Characters hitpoint
		*/
		int hitpoints;

		/**
		* \brief  Characters ability scores     (str,dex,cons,intel,wisd,chari)
		*/
		int abilityscores[6];
};

