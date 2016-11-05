#include "Subject.h"

std::vector<Observer*>* Subject::getObservers()
{
	return &observers;
}

void Subject::notifyObservers()
{
	//go through the observers and notify them
	for (Observer* ob : observers)
		ob->notify();
}

bool Subject::registerObserver(Observer* observer)
{
	//check to make sure we only add an observer once
	if (unregisterObserver(observer))
		return false;
	//add observer
	observers.push_back(observer);

	//return successfull
	return true;
}

bool Subject::unregisterObserver(Observer* observer)
{
	//go through the list ob observers, no real way to sort or make this  < O(n)
	for (int i = 0; i < observers.size(); i++)
	{
		//check if this is the obser that should be removed
		if (observer == observers[i])
		{
			//remove observer at position i
			observers.erase(observers.begin() + i);

			//return that an observer has been found
			return true;
		}
	}
	//this only gets reached when the observer isn't in the list
	return false;
}



