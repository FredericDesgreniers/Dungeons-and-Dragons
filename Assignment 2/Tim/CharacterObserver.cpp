//! @file 
//! @brief Implementation file for the CharacterObserver class
//!

#include "CharacterObserver.h"



CharacterObserver::CharacterObserver()
{
}


CharacterObserver::CharacterObserver(Character* s){
	_subject = s;
	_subject->Attach(this);
}


void CharacterObserver::Update()
{
	updated = true; // For cppunit testing only
	Display();
}


void CharacterObserver::Display()
{
	std::cout << "Level:" << _subject->getLevel() << ", Health:" << _subject->getHealth() << "/" << _subject->getMaxHealth() <<
		", STR:" << _subject->getStrength() << ", DEX:" << _subject->getDexterity() << ", CON:" << _subject->getConstitution() <<
		", INT:" << _subject->getIntelligence() << ", WIS:" << _subject->getWisdom() << ", CHA:" << _subject->getCharisma() << endl;

}


CharacterObserver::~CharacterObserver()
{
	_subject->Detach(this);
	_subject=nullptr;
}
