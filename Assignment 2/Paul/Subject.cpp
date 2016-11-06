//! @file
//! @brief Implementation file for Subject class
//!

#include "Observer.h"

Subject::Subject() 
{
	// creates a new subject object and a new list to hold observers
	_oberservers = new list<Observer*>;
}

Subject::~Subject() 
{
	delete _oberservers;
}

void Subject::Attach(Observer* o) 
{
	// adds the observer to the list
	_oberservers->push_back(o);
}

void Subject::Detach(Observer* o) 
{
	// removes the observer reference from the list
	_oberservers->remove(o);
}


void Subject::Notify() 
{
	// iterator set to begining of the list
	list<Observer*>::iterator i = _oberservers->begin();

	// calls notify on all list members
	while (i != _oberservers->end())
	{
		(*i)->Update();
		++i;
	}
}
