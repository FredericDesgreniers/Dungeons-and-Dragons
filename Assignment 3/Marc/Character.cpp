//! @file 
//! @brief Implementation file for the Character class  
//!
#pragma once
#include "stdafx.h"
#include "Character.h"
#include <iostream>
#include <sstream>
using namespace std;

//! Default constructor
Character::Character()
{
	name = "";
	strength = 0;
	constitution = 0;
	dexterity = 0;
	intelligence = 0;
	charisma = 0;
	wisdom = 0;
}

//! Custom constructor
Character::Character(std::string name, int strength, int constitution, int dexterity, int intelligence, int charisma, int wisdom)
{
	this->name = name;
	this->strength = strength;
	this->constitution = constitution;
	this->dexterity = dexterity;
	this->intelligence = intelligence;
	this->charisma = charisma;
	this->wisdom = wisdom;
}

//! gets all the equipment from this character and its decorations
//! @return a concatenated string containing all the character's equipment
std::string Character::getEquipment()
{
	return "Equipment:";
}

//! gets the actual stats of the character
//! @return a string detailing the character's actual stats
std::string Character::getStats()
{
	std::stringstream stream;
	stream <<
		"strength: " << strength << endl <<
		"constitution: " << constitution << endl <<
		"dexterity: " << dexterity << endl <<
		"intelligence: " << intelligence << endl <<
		"charisma: " << charisma << endl <<
		"wisdom: " << wisdom;
	return stream.str();
}

//! Checks if an item can be equipped in an equipment slot
//! @param EquipmentSlot : the equipement slot of the item to be equipped
//! @return a bool indicating if the item can be equipped or not on the character
bool Character::validateEquipmentSlot(EquipmentSlot equipmentSlot)
{
	return true;
}
