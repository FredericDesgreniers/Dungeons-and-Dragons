#pragma once
#include "entity.h"
#include "dice.h"
#include "Item.h"
#include "ItemContainer.h"
#include "Strategy.h"
#include <fstream>
#include <iostream>

class Strategy;
/**
 * Extends entity, meant for anything that has health and is "living"
 */
class LivingEntity :public Entity {
public:
	/**
	 * Create default LivingEntity given a char to display
	 */
	LivingEntity(char c);
	/**
	 * Create a living entity with attributes but non name
	 */
	LivingEntity(char c, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int level);
	/**
	 * Create a living entity given attributes and name
	 */
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

	bool interact(Map* map, Entity* entity) override;

	void reset();

	static LivingEntity * loadLivingEntity(std::string name);

	bool saveLivingEntity();

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

	void setPlayer(bool value);


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
	std::string toString() {
	
		return "Name: " + name + "\nLevel: " + to_string(level) +"\nBase:\nSTR: " + std::to_string(getStrength()) + ", DEX: " + std::to_string(getDexterity()) + ", CON: " + std::to_string(getConstitution()) +
			"\nINT: " + std::to_string(getIntelligence()) + ", WIS: " + std::to_string(getWisdom()) + ", CHA: " + std::to_string(getCharisma()) +
			"\nEffective:\nSTR: " + std::to_string(effectiveAbilityScores[0]) + ", DEX: " + std::to_string(effectiveAbilityScores[1]) +
			", CON: " + std::to_string(effectiveAbilityScores[2]) + "\nINT: " + std::to_string(effectiveAbilityScores[3]) + ", WIS: " +
			std::to_string(effectiveAbilityScores[4]) + ", CHA: " + std::to_string(effectiveAbilityScores[5]) + 
			"\nAC: " + std::to_string(armorClass) + ", Max Health:" + to_string(maxHealth) + 
			"\nDamage Bonus:" + to_string(damageBonus) + ", Attack bonus:" + to_string(attackBonus) + ", Attacks per turn:" + to_string(attacksPerTurn) +
			"\nSave vs. Fortitude: " + to_string(savingThrows[0]) + ", Save vs Reflex: " + to_string(savingThrows[1]) + ", Save vs Will: " + to_string(savingThrows[2]) + "\n";
			;
		}
	
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

	int getAttacksRemaining();
	
	~LivingEntity();

	void levelUp();

	int rollInitiative();

	int rollDamage();

	int rollAttack();

	void resetAttacks();

	int getInitiative();

	bool getTurnFinished();
	void setTurnFinished(bool tf);

	void setStrategy(Strategy* strategy);

	void doStrategy(Map* map);

	bool getHostile();

	void setHostile(bool hostile);

	bool isPlayer();
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
	* Armor class calculated from the total armor on equipped items. Updated on equip/unequip
	*/
	int armorClass;

	int attacksRemaining;

	int initiative;

	bool turnFinished;

	bool hostile;

	bool player;

	Strategy* strategy;
};


