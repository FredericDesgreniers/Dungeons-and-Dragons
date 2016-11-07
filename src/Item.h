#pragma once

#include <string>
#include <iostream>


class Item
{

public:
	enum ItemType {
		HELMET, // int, wis, armor class
		ARMOR,  // armor class
		SHIELD, // armor class
		RING,   // str, con, wis, cha, armor class.
		BELT,   // con, str
		BOOTS,  // armor class, dex
		WEAPON  // attack, damage
	};

	Item();
	Item(Item * item);
	// Item with all member variables.
	Item(std::string name, ItemType iType, int str, int dex, int con, int intl, int wis, int cha, int atk, int dmg, int arm);


	~Item();
	
	static Item* loadItem(std::string name);
	static bool saveItem(std::string name, Item* item);

	std::string getName();
	void setName(std::string iName);

	ItemType getItemType();
	void setItemType(ItemType iType);

	int getStrBoost();
	void setStrBoost(int strB);

	int getDexBoost();
	void setDexBoost(int dexB);

	int getConBoost();
	void setConBoost(int conB);

	int getIntBoost();
	void setIntBoost(int intB);

	int getWisBoost();
	void setWisBoost(int wisB);

	int getChaBoost();
	void setChaBoost(int chaB);

	int getAtkBoost();
	void setAtkBoost(int atkB);

	int getDmgBoost();
	void setDmgBoost(int dmgB);

	int getArmBoost();
	void setArmBoost(int armB);

	int checkValididty(int boost);

	std::string toString();

	static std::string displayType(Item::ItemType iType);

	static Item::ItemType stringToType(std::string type);

private:


	// items all have a name
	std::string itemName;
	// and a type
	ItemType type;

	// The boosts are restricted by the item type
	// items can boost the 6 bases ability scores
	int strBoost;
	int dexBoost;
	int conBoost;
	int intBoost;
	int wisBoost;
	int chaBoost;

	// and attack, damage or armor class
	int atkBoost;
	int dmgBoost;
	int armBoost;


};
