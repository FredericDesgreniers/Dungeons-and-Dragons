//! @file 
//! @brief Implementation file for Item class

#include "Item.h"
#include <iostream>
#include <fstream>
#include <time.h>

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


Item::Item(Item* item)
{
	itemName = item->getName();
	type = item->getItemType();
	strBoost = item->getStrBoost();
	dexBoost = item->getDexBoost();
	conBoost = item->getConBoost();
	chaBoost = item->getChaBoost();
	atkBoost = item->getAtkBoost();
	dmgBoost = item->getDmgBoost();
	intBoost = item->getIntBoost();
	wisBoost = item->getWisBoost();
	armBoost = item->getArmBoost();

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

Item* Item::loadItem(std::string name)
{
	Item* it;
	std::fstream itemFile("items/" + name + ".it");

	if (itemFile.is_open())
	{
		std::string readArray[11] = {"", "", "", "", "", "", "", "", "", "", ""};
		std::string line = "";

		int i = 0;
		while (std::getline(itemFile, line))
		{
			readArray[i] = line;
			i++;
		}

		Item::ItemType type = stringToType(readArray[1]);

	
		it = new Item(readArray[0], type, std::stoi(readArray[2]), std::stoi(readArray[3]), std::stoi(readArray[4]), std::stoi(readArray[5]), std::stoi(readArray[6]),
			std::stoi(readArray[7]), std::stoi(readArray[8]), std::stoi(readArray[9]), std::stoi(readArray[10]));

		std::cout << "load item from " << name << ".it" << std::endl;
		//std::cout << it->toString() << std::endl;
	}
	else
	{
		std::cout << "Unable to read item file, returning nullptr" << std::endl;
		it = nullptr;
	}
	return it;
}

bool Item::saveItem(std::string name, Item* item)
{
	std::fstream itemFile;
	itemFile.open("items/" + name + ".it", std::ios::out);

	if (itemFile.is_open())
	{
		itemFile << item->getName() << std::endl << item->displayType(item->getItemType()) << std::endl << item->getStrBoost() << std::endl
			<< item->getDexBoost() << std::endl << item->getConBoost() << std::endl << item->getIntBoost() << std::endl
			<< item->getWisBoost() << std::endl << item->getChaBoost() << std::endl << item->getAtkBoost() << std::endl
			<< item->getDmgBoost() << std::endl << item->getArmBoost();

		itemFile.flush();
		itemFile.close();
	}
	else
	{
		std::cout << "Unable to open file for writing" << std::endl;
		return false;
	}

	std::cout << "Item saved to " + name + ".it" << std::endl;
	return true;
}



std::string Item::getName() {
	return this->itemName;
}

void Item::setName(std::string iName) {
	this->itemName = iName;
	//Notify();
}

Item::ItemType Item::getItemType() {
	return type;
}

void Item::setItemType(ItemType iType) {
	this->type = iType;
	//Notify();
}

int Item::getStrBoost() {
	return this->strBoost;
}

void Item::setStrBoost(int strB) {
		this->strBoost = checkValididty(strB);
		//Notify();
}

int Item::getDexBoost() {
	return this->dexBoost;
}

void Item::setDexBoost(int dexB) {
	this->dexBoost = checkValididty(dexB);
	//Notify();

}

int Item::getConBoost() {
	return this->conBoost;
}

void Item::setConBoost(int conB) {
	this->conBoost = checkValididty(conB);
	//Notify();

}

int Item::getIntBoost() {
	return this->intBoost;
}

void Item::setIntBoost(int intB) {

	this->intBoost = checkValididty(intB);
	//Notify();

}

int Item::getWisBoost() {
	return this->wisBoost;
}

void Item::setWisBoost(int wisB) {
	this->wisBoost = checkValididty(wisB);
	//Notify();
}

int Item::getChaBoost() {
	return this->chaBoost;
}

void Item::setChaBoost(int chaB) {
	this->chaBoost = checkValididty(chaB);
	//Notify();
}

int Item::getAtkBoost() {
	return this->atkBoost;
}

void Item::setAtkBoost(int atkB) {
	this->atkBoost = checkValididty(atkB);
	//Notify();
}

int Item::getDmgBoost() {
	return this->dmgBoost;
}

void Item::setDmgBoost(int dmgB) {
	this->dmgBoost = checkValididty(dmgB);
	//Notify();
}

int Item::getArmBoost() {
	return this->armBoost;
}

void Item::setArmBoost(int armB) {
	this->armBoost = checkValididty(armB);
	//Notify();
}



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

std::string Item::toString() 
{

	std::string str = "\t" + getName() + "\nType: " + displayType(getItemType());
	int boost=0;
	
	boost = getStrBoost();
	if (boost > 0)
		str += "\nStrength:      +" + std::to_string(boost);
	boost = getDexBoost();
	if (boost > 0)
		str += "\nDexterity:     +" + std::to_string(boost);
	boost = getConBoost();
	if (boost > 0)
		str += "\nConstitution:  +" + std::to_string(boost);
	boost = getIntBoost();
	if (boost > 0)
		str += "\nIntelligence:  +" + std::to_string(boost);
	boost = getWisBoost();
	if (boost > 0)
		str += "\nWisdom:        +" + std::to_string(boost);
	boost = getChaBoost();
	if (boost > 0)
		str += "\nCharisma:      +" + std::to_string(boost);
	boost = getArmBoost();
	if (boost > 0)
		str += "\nArmor class:   +" + std::to_string(boost);
	boost = getDmgBoost();
	if (boost > 0)
		str += "\nDamage:        +" + std::to_string(boost);
	boost = getAtkBoost();
	if (boost > 0)
		str += "\nAttack:        +" + std::to_string(boost);

	return str;
}

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

Item::ItemType Item::stringToType(std::string type)
{
	if (type.compare("Helmet") == 0) {
		return HELMET;
	} else if (type.compare("Armor") == 0) {
		return ARMOR;
	} else if (type.compare("Shield") == 0) {
		return SHIELD;
	} else if (type.compare("Ring") == 0) {
		return RING;
	} else if (type.compare("Belt") == 0) {
		return BELT;
	} else if (type.compare("Boots") == 0) {
		return BOOTS;
	} else if (type.compare("Weapon") == 0) {
		return WEAPON;
	}
	else
	{
		std::cout << "Cannot convert this string to an item type" << std::endl;
		return ItemType::ARMOR;
	}
}
Item* Item::generateRandomItem(ItemType type, int level)
{
	Item* it;
	srand(time(NULL));

	int scores[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < 9; i++)
	{
		if (level >= 1 && level <= 2)
		{
			scores[i] = 1;
		}
		else if (level >= 3 && level <= 6)
		{
			scores[i] = rand() % 2 + 1;
		}
		else if (level >= 7 && level <= 10)
		{
			scores[i] = rand() % 3 + 1;
		}
		else if (level >= 11 && level <= 14)
		{
			scores[i] = rand() % 4 + 1;
		}
		else if (level >= 15 && level <= 18)
		{
			scores[i] = rand() % 5 + 1;
		}
		else if (level > 18)
		{
			scores[i] = 5;
		}
		else
		{
			std::cout << "Invalid level provided for random item creation" << std::endl;
			return it = new Item();
		}
	}

	std::string name = displayType(type);

	it = new Item(name, type, scores[0], scores[1], scores[2], scores[3], scores[4], scores[5], scores[6], scores[7], scores[8]);
	return it;
}

Item* Item::generateRandomItem(int level)
{
	ItemType type = static_cast<ItemType>(rand() % 6 + 1);
	return generateRandomItem(type, level);
}

void Item::validateItem(Item* it)
{
	switch (it->getItemType())
	{

	case HELMET:

		strBoost = 0;
		dexBoost = 0;
		conBoost = 0;
		chaBoost = 0;
		atkBoost = 0;
		dmgBoost = 0;
		break;

	case (ARMOR):
	case (SHIELD):
		
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

		dexBoost = 0;
		intBoost = 0;
		atkBoost = 0;
		dmgBoost = 0;
		break;

	case BELT:

		dexBoost = 0;
		intBoost = 0;
		wisBoost = 0;
		chaBoost = 0;
		atkBoost = 0;
		dmgBoost = 0;
		armBoost = 0;
		break;

	case WEAPON:

		strBoost = 0;
		dexBoost = 0;
		conBoost = 0;
		intBoost = 0;
		wisBoost = 0;
		chaBoost = 0;
		armBoost = 0;
		break;

	case BOOTS:
		atkBoost = 0;
		dmgBoost = 0;
		strBoost = 0;
		conBoost = 0;
		intBoost = 0;
		wisBoost = 0;
		chaBoost = 0;
		break;

	default:
		std::cout << "This item type is not allowed" << std::endl;
		break;
	}
	
}



