//! @file 
//! @brief Implementation file for the Item class  
//!
#pragma once
#include "stdafx.h"
#include "Item.h"
#include <iostream>
#include <sstream>
using namespace std;

//! Default constructor
Item::Item() : CharacterDecorator(nullptr, EquipmentSlot::None)
{
	this->name = "";
	this->slot = EquipmentSlot::None;
	this->strBonus = 0;
	this->conBonus = 0;
	this->dexBonus = 0;
	this->intBonus = 0;
	this->chaBonus = 0;
	this->wisBonus = 0;
}

//! Custom constructor
Item::Item(std::string name, EquipmentSlot slot, int strBonus, int conBonus, int dexBonus, int intBonus, int chaBonus, int wisBonus) : CharacterDecorator(nullptr, slot)
{
	this->name = name;
	this->slot = slot;
	this->strBonus = strBonus;
	this->conBonus = conBonus;
	this->dexBonus = dexBonus;
	this->intBonus = intBonus;
	this->chaBonus = chaBonus;
	this->wisBonus = wisBonus;
}

//! Lists the equipmentt of a decorated character
//! @return a string representing the whole equipement of a decorated character
std::string Item::getEquipment()
{ 
	std::string tempStr = CharacterDecorator::getEquipment();

	tempStr += tempStr.back() == ':' ? " " : ", ";
	tempStr += name;

	return tempStr;
}

//! Checks if an item can be equipped in an equipment slot
//! @param EquipmentSlot : the equipement slot of the item to be equipped
//! @return a bool indicating if the item can be equipped or not
bool Item::validateEquipmentSlot(EquipmentSlot equipmentSlot)
{
	if (slot == equipmentSlot)
	{
		return false;
	}

	return CharacterDecorator::validateEquipmentSlot(equipmentSlot);
}

//! Lists the actual stats of a decorated character
//! @return a string listing the actual stats of a decorated character
std::string Item::getStats()
{
	std::stringstream stream;
	stream <<
		"strength: " << CharacterDecorator::getStrenght() + strBonus << endl <<
		"constitution: " << CharacterDecorator::getConstitution() + conBonus << endl <<
		"dexterity: " << CharacterDecorator::getDexterity() + dexBonus << endl <<
		"intelligence: " << CharacterDecorator::getIntelligence() + intBonus << endl <<
		"charisma: " << CharacterDecorator::getCharisma() + chaBonus << endl <<
		"wisdom: " << CharacterDecorator::getWisdom() + wisBonus;
	return stream.str();
}