//! @file 
//! @brief Header file for LivingEntity class

#pragma once
#include "dice.h"
#include "Item.h"
#include "ItemContainer.h"
// #include "Subject.h"

/**
 * Extends entity, meant for anything that has health and is "living"
 */
class LivingEntity //:public Entity, public Subject 
{
public:
	LivingEntity();
	/**
	 * Create default LivingEntity given a char to display
	 */
	LivingEntity(char c);
	/**
	 * Create a living entity with attributes but no name
	 */
	LivingEntity(char c, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int level);
	/**
	 * Create a living entity with attributes and name
	 */
	LivingEntity(char c, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int level, std::string cname);

	/**
	* Returns max entity health
	*/
	int getMaxHealth();

	/**
	 * Returns current health
	 */
	int getHealth();

	/**
	* Return the entity's armor class rating
	*/
	int getArmorClass();

	/**
	* Return the entity's name
	*/
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
	int getConstitution();
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
	* Get attack bonus as an int
	*/
	int getAttackBonus();

	/**
	* Return the entity's max attacks per round.
	*/
	int getAttacksPerTurn();


	/**
	*  Set entity name
	* @param 
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
	void setMaxHealth(int value);
	void setHealth(int value);
	/**
	* Set charisma as int
	*/
	void setCharisma(int value);


	/**
	* Return the array holding antity's ability scores after item modifications
	*/
	int* getEffectiveAbilityScoreArray();
	/**
	* Return array holding entity's ability scores
	*/
	int* getAbilityScoreArray();

	ItemContainer* getBackpack();

	int getSavingThrow(int save);

	/**
	* Equip an item. Returns previously equipped item if one exists, nullptr otherwise
	*/
	Item* equip(Item* toEquip);
	/**
	 * Equip a series of basic items
	 */
	void equipBasic();
	/**
	 * Output equiped items to console
	 */
	void outputEquipped();
	/**
	 * Unequip an item at a certain slot. Returns the item located there. 
	 */
	Item* unequip(int itemSlot);

	/**
	* Output a description of the Entity's ability scores and other statistics, both base and effective. 
	*/
	std::string toString();
	
	/**
	* Return an array of pointers to the Entity's equipped Items
	*/
	Item** getEquippedItems();
	
	/**
	* Copy the stats and items from one LivingEntity to another. Used mainly for loading characters in the character creation screen
	*/
	bool copyStats(LivingEntity* from);
	
	/**
	* Get modifer from ability score.
	*
	* The modifier is calculated as per game rules using (score-10)/2
	*/
	int getModifier(int stat);

	/**
	* Return number of attacks remaining for the round
	*/
	int getAttacksRemaining();

	~LivingEntity();

	/**
	* Level up the entity by 1 level. See levelUp(int levels)
	*/
	void levelUp();

	/**
	* Level up the entity by a number of levels. Rolls hit dice to increase HP (+ constitution bonus). 
	* Increases attack bonus, saving throws, and number of attacks if applicable.
	*/
	void levelUp(int levels);

	int rollInitiative();
	/**
	* Roll damage for a successful attack. Uses damage and damage bonus.
	*/
	int rollDamage();

	/**
	* Roll an attack and decrements attacksPerTurn. Attack bonus is reduced by 5 for each subsequent attack
	* When attacksRemaining reaches 0, the entity can no longer attack until resetAttacks is called.
	*/
	int rollAttack();

	/**
	* Reset the entity's remaining attacks to attacksPerTurn. Called each combat round.
	*/
	void resetAttacks();


private:
	/**
	* The Entity's max Hit Points
	*/
	int maxHealth;
	/**
	* The Entity's current Hit Points. 
	*/
	int health;
	/**
	* The Entity's name. Also used in the filename when saving a Entity.
	*/
	std::string name;
	
	/**
	* The Entity's attack bonus which is added to the total after damage rolls
	*/
	int damageBonus;
	/**
	* The Entity's attack bonus which is added to attack rules to determine if hits are successful.
	*/
	int attackBonus;
	/**
	* The Entity's effective damage in dice notation.
	*/
	string damage;
	
	/**
	* The entity's attacks per turn, which is calculated based on level
	*/
	int attacksPerTurn;
	
	/**
	* An array holding pointers to an Entitys equipped items.
	* Contains one slot for each item type. Items are added/removed using the equip and unequip functions
	*/
	Item* equipped[7];
	/**
	* The backpack ItemContainer containing items which are not equipped.
	* A container storing items the Entity is carrying but which are not equipped.
	*/
	ItemContainer* backpack;

	/**
	* Update the Entity's efffective stats and ability scores.
	* This includes the effectiveAbilityScores array as well as damage bonus,
	* attack bonus, armor class
	*/
	void updateStats();

	
	/**
	* Entity's level
	*/
	int level;
	/**

	/**
	* Entity's ability scores (str,dex,cons,intel,wisd,chari)
	*/
	int abilityscores[6];

	/**
	* Entity's ability scores after item bonuses. Updated whenever the entity's stats change or 
	* when items are equipped/unequipped
	*/
	int effectiveAbilityScores[6];

	/**
	* Entity's saving throws, calculated based on level (possibly class in the future)
	*/
	int savingThrows[3];

	/**
	* Armor class calculated from the total armor on equipped items. Updated on equip/
	*/
	int armorClass;

	/**
	* Number of attacks remaining for the current combat round
	*/
	int attacksRemaining;
};


