//! @file
//! @brief Header file for Subject class
//!
//! Subject is the abstract subject

#pragma once

#include "Observer.h"
#include <list>
using namespace std;

// forward reference
class Observer;

//! Class implementation for subject in observer pattern and abstract functions for concrete subject
class Subject 
{
private:
	//! Observers are stored in a list as a member cariable
	list<Observer*> *_oberservers;

public:
	//! Default constructor
	Subject();

	//! Destructor
	~Subject();

	//! Attaches an observer to a subject
	virtual void Attach(Observer* obs);

	//! Detaches an observer from a subject
	virtual void Detach(Observer* obs);

	//! Notify all observers of the subject state
	virtual void Notify();

};
