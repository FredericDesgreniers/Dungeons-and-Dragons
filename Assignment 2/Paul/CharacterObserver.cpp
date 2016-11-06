//! @file 
//! @brief Implementation file for the CharacterObserver class
//!
#include "CharacterObserver.h"
#include "Character.h"
#include <iostream>
using namespace std;

CharacterObserver::CharacterObserver() {};

CharacterObserver::CharacterObserver(Character* c)
{
	_subject = c;
	// attaches the subject to the observer
	_subject->Attach(this);
}

CharacterObserver::~CharacterObserver()
{
	// detaches the subject to the observer
	_subject->Detach(this);
}

void CharacterObserver::Update()
{
	// call for display()
	display();
}

void CharacterObserver::display()
{
	// outputs the character scores with toString() method defined there
	cout << "Update from Observer pattern: " << _subject->toString() << endl;
}

Character* CharacterObserver::getSubject()
{
	return _subject;
}