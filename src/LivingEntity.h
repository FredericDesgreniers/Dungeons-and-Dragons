#pragma once
#include "entity.h"
#include "dice.h"
#include "Item.h"
/**
 * Extends entity, meant for anything that has health and is "living"
 */
class LivingEntity :public Entity {
public:
	LivingEntity(char c);
	LivingEntity(char c, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int level);
	LivingEntity(char c, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int level, std::string cname);


	/**
	* Gets max entity health
	*/
	int getMaxHealth();

	/**
	 * Get current health
	 */
	int getHealth();

	std::string getName();


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
	*  Set entity name
	*/
	void setName(std::string cname);

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
	void setConstitution(int value);
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



	int* getEffectiveAbilityScoreArray();
	/**
	* Return array holding entity's ability scores
	*/
	int* getAbilityScoreArray();

	/**
	* Equip an item. Returns previously equipped item if one exists, nullptr otherwise
	*/
	Item* equip(Item* toEquip);

	void outputEquipped();
	Item* unequip(int itemSlot);

	std::string toString() {
	
		return "Name: " + name + "\nSTR:" + std::to_string(getStrength()) + ", DEX:" + std::to_string(getDexterity()) + ", CON:" + std::to_string(getConsitution()) +
			", INT:" + std::to_string(getIntelligence()) + ", WIS:" + std::to_string(getWisdom()) + ", CHA:" + std::to_string(getCharisma()) +
			"\nEffective:\n" + "STR:" + std::to_string(effectiveAbilityScores[0]) + ", DEX:" + std::to_string(effectiveAbilityScores[1]) +
			", CON:" + std::to_string(effectiveAbilityScores[2]) + ", INT:" + std::to_string(effectiveAbilityScores[3]) + ", WIS:" +
			std::to_string(effectiveAbilityScores[4]) + ", CHA:" + std::to_string(effectiveAbilityScores[5]) + "\nAC:" + std::to_string(armorClass) +
			", Damage Bonus:" + to_string(damageBonus) + ", Attack bonus:" + to_string(attackBonus) + "\n";

		}
	
	Item** getEquippedItems();


private:
	int maxHealth;
	int effectiveMaxHealth;
	int health;
	std::string name;
	int damageBonus;
	int attackBonus;
	string damage;
	Item* equipped[7];


	bool updateStats();
	
	/**
	* Entity's level
	*/
	int level;
	/**

	/**
	* Entity's ability scores (str,dex,cons,intel,wisd,chari)
	*/
	int abilityscores[6];
	int effectiveAbilityScores[6];
	int armorClass;
};