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

void Item::setIntBoost(int intB) {
  this->intBoost = intB;
}

int Item::getWisBoost() {
  return this->strBoost;
}

void Item::setWisBoost(int wisB) {
  this->wisBoost = wisB;
}

int Item::getChaBoost() {
  return this->chaBoost;
}

void Item::setChaBoost(int chaB) {
  this->chaBoost = chaB;
}

int Item::getAtkBoost() {
  return this->atkBoost;
}

void Item::setAtkBoost(int atkB) {
  this->atkBoost = atkB;
}

int Item::getDmgBoost() {
  return this->dmgBoost;
}

void Item::setDmgBoost(int dmgB) {
  this->dmgBoost = dmgB;
}

int Item::getArmBoost()
{
  return this->armBoost;
}

void Item::setArmBoost(int armB) {
  this->armBoost = armB;
}
