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

ItemType Item::getItemType() {
  return this->ItemType;
}

void Item::setItemType(ItemType iType) {
  this->ItemType = iType;
}

int Item::getStrBoost() {
  return this->strBoost;
}

void Item::setStrBoost(int strB) {
  this->strBoost = strB;
}

int Item::getDexBoost() {
  return this->dexBoost;
}

void Item::setDexBoost(int dexB) {
  this->dexBoost = dexB;
}

int Item::getConBoost() {
  return this->conBoost;
}

void Item::setConBoost(int conB) {
  this->conBoost = conB;
}

int Item::getIntBoost() {
  return this->intBoost;
}

void setIntBoost(int intB) {
  this->intBoost = intB;
}

int getWisBoost() {
  return this->strBoost;
}

void setWisBoost(int wisB) {
  this->wisBoost = wisB;
}

int getChaBoost() {
  return this->chaBoost;
}

void setChaBoost(int chaB {
  this->chaBoost = chaB;
}

int getAtkBoost() {
  return this->atkBoost;
}

void setAtkBoost(int atkB) {
  this->atkBoost = atkB;
}

int getDmgBoost() {
  return this->dmgBoost;
}

void setDmgBoost(int dmgB) {
  this->dmgBoost = dmgB;
}

int getArmBoost()
{
  return this->armBoost;
}

void setArmBoost(int armB) {
  this->armBoost = armB;
}
