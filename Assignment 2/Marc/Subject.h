//! @file 
//! @brief Header file for the Subject class.
//!
#pragma once
#include "Observer.h"
#include <list>
using namespace std;

//! class that represents an abstract observable Subject, its attributes and its behavior towards its Observers
class Subject 
{

private:

	list<Observer*> *_observers;

public:

	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
	Subject();
	~Subject();

};
