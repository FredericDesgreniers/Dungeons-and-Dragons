#include "Subject.h"
#include "Observer.h"

Subject::Subject() 
{
	_oberservers = new list<Observer*>;
}

Subject::~Subject() 
{
	delete _oberservers;
}

void Subject::Attach(Observer* o) 
{
	_oberservers->push_back(o);
}

void Subject::Detach(Observer* o) 
{
	_oberservers->remove(o);
}

void Subject::Notify() 
{
	list<Observer*>::iterator i = _oberservers->begin();

	while (i != _oberservers->end())
	{
		(*i)->Update();
		++i;
	}
}
