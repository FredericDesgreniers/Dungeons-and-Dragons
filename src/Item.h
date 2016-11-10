#pragma once

#include <string>
#include <iostream>
#include "Subject.h"

/**
 * Class used for representing an item
 */
class Item : public Subject
{

public:
	/**
	*Enum type used to differentiate items
	*/
	enum ItemType {
		HELMET, // int, wis, armor class
		ARMOR,  // armor class
		SHIELD, // armor class
		RING,   // str, con, wis, cha, armor class.
		BELT,   // con, str
		BOOTS,  // armor class, dex
		WEAPON  // attack, damage
	};

	/**
	*Default constructor
	*/
	Item();

	/**
	*Copy constructor
	*/
	Item(Item * item);

	/**
	*Constructor taking all Item member variables
	*/
	Item(std::string name, ItemType iType, int str, int dex, int con, int intl, int wis, int cha, int atk, int dmg, int arm);

	/**
	*Destructor
	*/
	~Item();
	
	/**
	*Loads an item from a .it file and returns a pointer to it
	*/
	static Item* loadItem(std::string name);

	/**
	*Takes an item and a file name and writes the data members of this item to the file
	*/
	static bool saveItem(std::string name, Item* item);

	/**
	*Returns the name of the item as a String
	*/
	std::string getName();

	/**
	*Sets the item name to a passed string
	*and calls Notify()
	*/
	void setName(std::string iName);

	/**
	*Returns the item type as a ItemType enum type
	*/
	ItemType getItemType();

	/**
	*Sets the type of the item to a passed ItemType enum
	*and calls Notify()
	*/
	void setItemType(ItemType iType);

	/**
	*Returns the strength boost as an int
	*/
	int getStrBoost();

	/**
	*Sets the strength boost to a passed int
	*and calls Notify()
	*/
	void setStrBoost(int strB);

	/**
	*Returns the dexterity boost as an int
	*/
	int getDexBoost();

	/**
	*Sets the dexterity boost to a passed int
	*and calls Notify()
	*/
	void setDexBoost(int dexB);

	/**
	*Returns the constitution boost as an int
	*/
	int getConBoost();

	/**
	*Sets the constitution boost to a passed int
	*and calls Notify()
	*/
	void setConBoost(int conB);

	/**
	*Returns the intelligence boost as an int
	*/
	int getIntBoost();

	/**
	*Sets the intelligence boost to a passed int
	*and calls Notify()
	*/
	void setIntBoost(int intB);

	/**
	*Returns the wisdom boost as an int
	*/
	int getWisBoost();

	/**
	*Sets the wisdom boost to a passed int
	*and calls Notify()
	*/
	void setWisBoost(int wisB);

	/**
	*Returns the charisma boost as an int
	*/
	int getChaBoost();

	/**
	*Sets the charisma boost to a passed int
	*and calls Notify()
	*/
	void setChaBoost(int chaB);

	/**
	*Returns the attack boost as an int
	*/
	int getAtkBoost();

	/**
	*Sets the attack boost to a passed int
	*and calls Notify()
	*/
	void setAtkBoost(int atkB);

	/**
	*Returns the damage boost as an int
	*/
	int getDmgBoost();

	/**
	*Sets the damage boost to a passed int
	*and calls Notify() 
	*/
	void setDmgBoost(int dmgB);

	/**
	*Returns the armor class boost as an int
	*/
	int getArmBoost();

	/**
	*Sets the armor class boost to a passed int
	*and calls Notify()
	*/
	void setArmBoost(int armB);

	/**
	*Checks for the validity of the boost assignment
	*It cannot be < 0 and > 5. CheckValidity() is called 
	*before each setter can assign values.
	*Returns 0 if the boost is unallowed
	*/
	int checkValididty(int boost);

	/**
	*Displays all data members of an Item object
	*/
	std::string toString();

	/**
	*Takes an ItemType enum and returns the corresponding string
	*/
	static std::string displayType(Item::ItemType iType);

	/**
	*Takes a string an returns the corresponding ItemType
	*/
	static Item::ItemType stringToType(std::string type);

	/**
	*Returns an item pointer to a newly created random Item with a specified level
	*/
	static Item* generateRandomItem(int level);

	/**
	*Generates a random item with a type and a level and returns a pointer to that item
	*/
	static Item* generateRandomItem(ItemType type, int level);
	
	/**
	*Checks for data members values and reassigns them if needed in case of 
	*unallowed values.
	*/
	void validateItem(Item* it);

private:

	/**
	*String holding the name of the item
	*/
	std::string itemName;

	/**
	*ItemType enum type holding the type of the item
	*/
	ItemType type;

	/**
	*Int holding the strength boost
	*/
	int strBoost;

	/**
	*Int holding the dexterity boost
	*/
	int dexBoost;

	/**
	*Int holding the constitution boost
	*/
	int conBoost;

	/**
	*Int holding the intelligence boost
	*/
	int intBoost;

	/**
	*Int holding the wisdom boost
	*/
	int wisBoost;

	/**
	*Int holding the charisma boost
	*/
	int chaBoost;

	/**
	*Int holding the attack boost
	*/
	int atkBoost;

	/**
	*Int holding the damage boost
	*/
	int dmgBoost;

	/**
	*Int holding the armor class boost
	*/
	int armBoost;
};
