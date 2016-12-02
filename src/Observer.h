//! @file 
//! @brief Header file for the Observer prototype class
//!

#pragma once
#include "Subject.h"

//Needs to have a forward reference due to 
//circular reference between Observer and Subject
class Subject;

//!  Observer prototype class
/*!
Prototype for CharacterObserver class. Ensures CharacterObserver compatibility with Character objects (which inherit from Subject)
*/
class Observer {
public:
	~Observer();
	/**
	 * Update subjects
	 */
	virtual void Update() = 0;
protected:
	Observer();
};
