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
	inline std::string toString() {
		return "str:" + std::to_string(getStrength()) + ", dex:" + std::to_string(getDexterity()) + ", cons:" + std::to_string(getConsitution()) + ", intel:" + std::to_string(getIntelligence()) + ", wisd:" + std::to_string(getWisdom()) + ", chari:" + std::to_string(getCharisma()) + ", HP:" + std::to_string(getHitPoints());

	}

	/**
	* Get level as int
	*/
	int getLevel()
	{
		return level;
	}
	/**
	* Get hit points as int
	*/
	int getHitPoints()
	{
		return hitpoints;
	}

	/**
	* Get Strength as int
	*/
	int getStrength()
	{
		return abilityscores[0];
	}
	/**
	* Get dexterity as int
	*/
	int getDexterity()
	{
		return abilityscores[1];
	}
	/**
	* Get constitution as int
	*/
	int getConsitution()
	{
		return abilityscores[2];
	}
	/**
	* Get inteligence as int
	*/
	int getIntelligence()
	{
		return abilityscores[3];
	}
	/**
	* Get wisdom as int
	*/
	int getWisdom()
	{
		return abilityscores[4];
	}
	/**
	* Get charisma as int
	*/
	int getCharisma()
	{
		return abilityscores[5];
	}
	/**
	* Get ability score array
	*/
	int* getAbilityScoreArray()
	{
		return abilityscores;
	}

	/**
	* set strength and notify the observer that something has changed
	*/
	void setStrength(int str)
	{
		abilityscores[0] = str;
		Notify();
	}

	/**
	* set dexterity and notify the observer that something has changed
	*/
	void setDexterity(int dex)
	{
		abilityscores[1] = dex;
		Notify();
	}

	/**
	* set constitution and notify the observer that something has changed
	*/
	void setConsitution(int cons)
	{
		abilityscores[2] = cons;
		Notify();
	}

	/**
	* set intelligence and notify the observer that something has changed
	*/
	void setIntelligence(int intel)
	{
		abilityscores[3] = intel;
		Notify();
	}

	/**
	* set wisdom and notify the observer that something has changed
	*/
	void setWisdom(int wis)
	{
		abilityscores[4] = wis;
		Notify();
	}

	/**
	* set charisma and notify the observer that something has changed
	*/
	void setCharisma(int cha)
	{
		abilityscores[5] = cha;
		Notify();
	}
};