//! @file 
//! @brief Header file for the Subject prototype class 
//!

#pragma once
#include "Observer.h"
#include <list>
using namespace std;

//Needs to have a forward reference due to 
//circular reference between Observer and Subject
class Observer;

//!  Subject prototype class
/*!
Prototype for subject functionality. 
*/
class Subject {
  public:
	/**
	 * Attack observer s
	 */
	virtual void Attach(Observer* o);
	/**
	 * Detach observer
	 */
	virtual void Detach(Observer* o);
	/**
	 * notify observers of change
	 */
	virtual void Notify();
	Subject();
	~Subject();
  private:
	/**
	 * List of observers
	 */
	list<Observer*> *_observers;
};
