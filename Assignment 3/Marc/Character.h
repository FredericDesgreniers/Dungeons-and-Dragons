//! @file 
//! @brief Header file for the Character class.
//!
#pragma once
#include <string>

//! Class that representes a character, its attributes and behaviors
class Character
{

private:

	std::string name;
	int strength;
	int	constitution;
	int dexterity;
	int intelligence;
	int charisma;
	int wisdom;

public:

	enum EquipmentSlot { None, Head, Chest, Legs, Hands, Feet, Weapon };

	Character();
	Character(std::string name, int strength, int constitution, int dexterity, int intelligence, int charisma, int wisdom);

	virtual std::string getCharName() { return name; }
	virtual std::string getStats();

	virtual EquipmentSlot getSlot() { return EquipmentSlot::None; }
	virtual int getStrenght() { return strength; }
	virtual int getConstitution() { return constitution; }
	virtual int getDexterity() { return dexterity; }
	virtual int getIntelligence() { return intelligence; }
	virtual int getCharisma() { return charisma; }
	virtual int getWisdom() { return wisdom; }

	virtual std::string getEquipment();
	virtual bool validateEquipmentSlot(EquipmentSlot equipmentSlot);

	virtual bool isCharacter() { return true; }
};