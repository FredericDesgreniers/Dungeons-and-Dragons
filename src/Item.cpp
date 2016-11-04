#include "Item.h"


Item::Item()
{

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

	case (ARMOR || SHIELD):
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

	if (checkValididty(strB))
	{
		this->strBoost = strB;
	}
}

int Item::getDexBoost() {
	return this->dexBoost;
}

void Item::setDexBoost(int dexB) {

	if (checkValididty(dexB))
	{
		this->dexBoost = dexB;
	}
}

int Item::getConBoost() {
	return this->conBoost;
}

void Item::setConBoost(int conB) {

	if (checkValididty(conB))
	{
		this->conBoost = conB;
	}
}

int Item::getIntBoost() {
	return this->intBoost;
}

void Item::setIntBoost(int intB) {

	if (checkValididty(intB))
	{
		this->intBoost = intB;
	}
}

int Item::getWisBoost() {
	return this->strBoost;
}

void Item::setWisBoost(int wisB) {

	if (checkValididty(wisB))
	{
		this->wisBoost = wisB;
	}
}

int Item::getChaBoost() {
	return this->chaBoost;
}

void Item::setChaBoost(int chaB) {

	if (checkValididty(chaB))
	{
		this->chaBoost = chaB;
	}
}

int Item::getAtkBoost() {
	return this->atkBoost;
}

void Item::setAtkBoost(int atkB) {

	if (checkValididty(atkB))
	{
		this->atkBoost = atkB;
	}
}

int Item::getDmgBoost() {
	return this->dmgBoost;
}

void Item::setDmgBoost(int dmgB) {

	if (checkValididty(dmgB))
	{
		this->dmgBoost = dmgB;
	}
}

int Item::getArmBoost()
{
	return this->armBoost;
}

void Item::setArmBoost(int armB) {

	if (checkValididty(armB))
	{
		this->armBoost = armB;
	}
}

bool Item::checkValididty(int boost)
{
	if (boost < 0 || boost > 5) {
		std::cout << "Item boost can only be 1-5, unallowed boost assignment" << std::endl;
		return false;
	}
	else {
		return true;
	}
}

inline std::string Item::toString() {
	std::string str = "\t" + getName() + "\nType: " + displayType(getItemType())
		+ "\nStr: " + std::to_string(getStrBoost())
		+ "\nDex: " + std::to_string(getDexBoost())
		+ "\nCon: " + std::to_string(getConBoost())
		+ "\nInt: " + std::to_string(getIntBoost())
		+ "\nWis: " + std::to_string(getWisBoost())
		+ "\nCha: " + std::to_string(getChaBoost())
		+ "\nArm: " + std::to_string(getArmBoost())
		+ "\nDmg: " + std::to_string(getDmgBoost())
		+ "\nAtk: " + std::to_string(getAtkBoost());

	return str;
}

inline std::string Item::displayType(Item::ItemType iType) {
	
	switch (iType)
	{
	case HELMET: return "Helmet"; 
		break;
	case ARMOR:  return "Armor";
		break;
	case SHIELD: return "Shield"; 
		break;
	case RING:   return "Ring";     
		break;
	case BOOTS:  return "Boots";   
		break;
	case BELT:   return "Belt";
		break;
	case WEAPON: return "Weapon";
		break;
	default: return "This item type is not allowed"; 
		break;
	}
}


/**int main()
{
	// Item::ItemType n = Item::WEAPON;
	std::string s = "Hi";


	Item* it = new Item(s, Item::HELMET, 3, 3, 3, 3, 3, 3, 3, 3, 3);

	std::cout << it->toString() << std::endl;

	delete(it);
	it = NULL;
}**/
