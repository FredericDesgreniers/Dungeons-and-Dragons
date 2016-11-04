#pragma once
#include "entity.h"
#include "dice.h"
/**
 * Extends entity, meant for anything that has health and is "living"
 */
class LivingEntity :public Entity {
public:
	LivingEntity(char c);

	LivingEntity(char c, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int lvl);

	/**
	* Gets max entity health
	*/
	int getMaxHealth();

	/**
	 * Get current health
	 */
	int getHealth();

	/**
	 * Hit entity for some damage 
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
	void setConsitution(int value);
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
	* Return array holding entity's ability scores
	*/
	int* getAbilityScoreArray();


private:
	int maxHealth;
	int health;

	/**
	* Entity's level
	*/
	int level;
	/**

	/**
	* Entity's ability scores (str,dex,cons,intel,wisd,chari)
	*/
	int abilityscores[6];
};