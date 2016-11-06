#include "Item.h"


Item::Item()
{
	itemName = "default";
	type = WEAPON;
	strBoost = 0;
	dexBoost = 0;
	conBoost = 0;
	chaBoost = 0;
	atkBoost = 0;
	dmgBoost = 0;

	intBoost = 0;
	wisBoost = 0;
	armBoost = 0;

};

Item::Item(std::string name, Item::ItemType iType, int str, int dex, int con, int intl, int wis, int cha, int atk, int dmg, int arm)
{
	this->itemName = name;

	switch (iType)
	{
	case HELMET:
		type = iType;
		setIntBoost(intl);
		setWisBoost(wis);
		setArmBoost(arm);
		strBoost = 0;
		dexBoost = 0;
		conBoost = 0;
		chaBoost = 0;
		atkBoost = 0;
		dmgBoost = 0;
		break;

	case (ARMOR):
	case (SHIELD):
		type = iType;
		setArmBoost(arm);
		strBoost = 0;
		dexBoost = 0;
		conBoost = 0;
		intBoost = 0;
		wisBoost = 0;
		chaBoost = 0;
		atkBoost = 0;
		dmgBoost = 0;

		break;

	case RING:
		type = iType;
		setStrBoost(str);
		setConBoost(con);
		setWisBoost(wis);
		setChaBoost(cha);
		setArmBoost(arm);
		dexBoost = 0;
		intBoost = 0;
		atkBoost = 0;
		dmgBoost = 0;
		break;

	case BELT:
		type = iType;
		setStrBoost(str);
		setConBoost(con);
		dexBoost = 0;
		intBoost = 0;
		wisBoost = 0;
		chaBoost = 0;
		atkBoost = 0;
		dmgBoost = 0;
		armBoost = 0;
		break;

	case WEAPON:
		type = iType;
		setAtkBoost(atk);
		setDmgBoost(dmg);
		strBoost = 0;
		dexBoost = 0;
		conBoost = 0;
		intBoost = 0;
		wisBoost = 0;
		chaBoost = 0;
		armBoost = 0;
		break;

	case BOOTS:
		type = iType;
		setDexBoost(dex);
		setArmBoost(arm);
		atkBoost = 0;
		dmgBoost = 0;
		strBoost = 0;
		conBoost = 0;
		intBoost = 0;
		wisBoost = 0;
		chaBoost = 0;
		break;

	default:
		std::cout << "item should be of a certain type" << std::endl;
	}
}


Item::~Item()
{

}


/*
* GETTERS AND SETTERS
*/

std::string Item::getName() {
	return this->itemName;
}

void Item::setName(std::string iName) {
	this->itemName = iName;
}

Item::ItemType Item::getItemType() {
	return this->type;
}

void Item::setItemType(ItemType iType) {
	this->type = iType;
}

int Item::getStrBoost() {
	return this->strBoost;
}

void Item::setStrBoost(int strB) {
		this->strBoost = checkValididty(strB);
}

int Item::getDexBoost() {
	return this->dexBoost;
}

void Item::setDexBoost(int dexB) {
	this->dexBoost = checkValididty(dexB);
	
}

int Item::getConBoost() {
	return this->conBoost;
}

void Item::setConBoost(int conB) {
	this->conBoost = checkValididty(conB);
}

int Item::getIntBoost() {
	return this->intBoost;
}

void Item::setIntBoost(int intB) {
	this->intBoost = checkValididty(intB);
}

int Item::getWisBoost() {
	return this->strBoost;
}

void Item::setWisBoost(int wisB) {
	this->wisBoost = checkValididty(wisB);
}

int Item::getChaBoost() {
	return this->chaBoost;
}

void Item::setChaBoost(int chaB) {
	this->chaBoost = checkValididty(chaB);
}

int Item::getAtkBoost() {
	return this->atkBoost;
}

void Item::setAtkBoost(int atkB) {
	this->atkBoost = checkValididty(atkB);
}

int Item::getDmgBoost() {
	return this->dmgBoost;
}

void Item::setDmgBoost(int dmgB) {
	this->dmgBoost = checkValididty(dmgB);
}

int Item::getArmBoost() {
	return this->armBoost;
}

void Item::setArmBoost(int armB) {
	this->armBoost = checkValididty(armB);
}


// checkValidity()
//
// checks if item is valid
// returns 0 if not between bounds
// else returns value passed
int Item::checkValididty(int boost)
{
	if (boost < 0 || boost > 5) {
		std::cout << "Item boost can only be 1-5, unallowed boost assignment, value will be set to 0" << std::endl;
		return 0;
	}
	else {
		return boost;
	}
}

// displays the item name, type and scores
std::string Item::toString() 
{
	std::string str = "\t" + getName() + "\nType: " + displayType(getItemType())
		+ "\nStrength:      +" + std::to_string(getStrBoost())
		+ "\nDexterity:     +" + std::to_string(getDexBoost())
		+ "\nConstitution:  +" + std::to_string(getConBoost())
		+ "\nIntelligence:  +" + std::to_string(getIntBoost())
		+ "\nWisdom:        +" + std::to_string(getWisBoost())
		+ "\nCharisma:      +" + std::to_string(getChaBoost())
		+ "\nArmor class:   +" + std::to_string(getArmBoost())
		+ "\nDamage:        +" + std::to_string(getDmgBoost())
		+ "\nAttack:        +" + std::to_string(getAtkBoost());

	return str;
}

// C++ does not allow to print enums
// This method takes an ItemType enum and returns a string to display it
std::string Item::displayType(Item::ItemType iType) {
	
	switch (iType)
	{
	case HELMET: 
		return "Helmet"; 
		break;

	case ARMOR:  
		return "Armor";
		break;

	case SHIELD: 
		return "Shield"; 
		break;

	case RING:   
		return "Ring";     
		break;

	case BOOTS:  
		return "Boots";   
		break;

	case BELT:   
		return "Belt";
		break;

	case WEAPON: 
		return "Weapon";
		break;

	default: 
		return "This item type is not allowed"; 
		break;
	}
}
