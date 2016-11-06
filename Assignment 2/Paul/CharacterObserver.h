//! @file 
//! @brief Header file for the CharacterObserver class
//!
//! CharacterObserver is the concrete observer
#pragma once
#include "Observer.h"
#include "Character.h"

class CharacterObserver : public Observer
{
public:
	//! Default constructor
	CharacterObserver();

	//! Constructor
	CharacterObserver(Character* c);

	//! Destructor
	~CharacterObserver();
	
	//! Update method
	//! Outputs all the scores from the Character object whenever somehting has changed
	void Update();

	//! Display method
	//! Displays the scores of the object, display() is called in update();
	void display();

	//! returns the subject
	Character* getSubject();

private:
	//! member variable pointer
	Character *_subject;
};
