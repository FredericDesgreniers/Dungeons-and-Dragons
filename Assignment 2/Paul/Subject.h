#pragma once

#include "Observer.h"
#include <list>
using namespace std;

class Observer;

class Subject 
{
private:
	list<Observer*> *_oberservers;

public:
	Subject();
	~Subject();

	// child classes define these
	virtual void Attach(Observer* obs);
	virtual void Detach(Observer * obs);
	virtual void Notify();
};
