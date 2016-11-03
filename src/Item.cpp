#include "Item.h"

Item::Item()
{

}

Item::Item(ItemType iType)
{

}

Item::~Item()
{

}


/*
* GETTERS AND SETTERS
*/

string Item::getName() {
  return this->itemName;
}

void Item::setName(string iName) {
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
	
	if(checkValididty(strB)) 
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
	if (0 < boost || boost > 5) {
		cout << "Item boost can only be 1-5, unallowed boost assignment" << endl;
		return false;
	}
	else {
		return true;
	}
}