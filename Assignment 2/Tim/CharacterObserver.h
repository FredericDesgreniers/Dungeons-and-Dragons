//! @file 
//! @brief Header file for the CharacterObserver class 
//!

#pragma once
#include "Observer.h"
#include "Character.h"

//!  CharacterObserver class 
/*!
CharacterObserver class attaches to a Character object and received notifications when changes occur in the Character.
For testing and demonstration purposes, when the Character Object calls notify() and the Update() function in this
class is called, the Observer will output updated information about the character state to show that it has been notified.

Derived from Observer class.
*/
class CharacterObserver :
	public Observer
{
public:
	/**
	Default constructor, initializes empty CharacterObserver.
	*/
	CharacterObserver();

	/**
	Constructor that takes a pointer to a character object as argument and attaches the observer
	to that object.
	*/

	CharacterObserver(Character* s);

	/**
	Destructor which detaches the observer from Character subject 
	*/
	~CharacterObserver();

	/**
	Function called when a Character object the observer is attached to calls Notify()
	Sets the updated bool to true (for CPPUnit testing purposes) and calls display() function
	*/
	void Update();

	/**
	Outputs information about the Character object this observer is attached to.
	*/
	void Display();
	/**
	Bool used for CPPunit testing. Initialized to false and set to true when Update() is called.

	Used in tests to check whether or not observers are correctly notified on changes to subject
	*/
	bool updated;

private:

	/**
	The Character subject that the observer is attached to
	*/
	Character* _subject;
};

