//! @file 
//! @brief Implementation file for the Subject class  
//!
#pragma once
#include "stdafx.h"
#include "Subject.h"
#include "Observer.h"

//! Constructor
Subject::Subject() 
{
	_observers = new list<Observer*>;
}

//! Deconstructor
Subject::~Subject() 
{
	delete _observers;
	_observers = NULL;
}

//! Attaches an observer to the subject
//! @param Observer* : a pointer to the observer to be attached
void Subject::Attach(Observer* observer) 
{
	_observers->push_back(observer);
};

//! Detaches an observer from the subject
//! @param Observer* : a pointer to the observer to be detached
void Subject::Detach(Observer* observer)
{
	_observers->remove(observer);
};

//! Notifies all of the subject's observers of its current state
void Subject::Notify() 
{
	list<Observer *>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i)
		(*i)->update();
};
