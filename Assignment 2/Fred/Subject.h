#pragma once
#include <vector>
#include "Observer.h"
/**
 * Subject takes care of managing observers and notifying them
 */
class Subject
{
public:
	/**
	 * Register an observer on the subject
	 * Return false if observer is already registered
	 */
	bool registerObserver(Observer* observer);

	/**
	 * Unregister an observer
	 * returns false if observer was never registered
	 */
	bool unregisterObserver(Observer* observer);

	/**
	 * Notify all observers of change in subject
	 */
	void notifyObservers();

	/**
	 * Get pointer to observer vector
	 */
	std::vector<Observer*>* getObservers();

private:
	std::vector<Observer*> observers;
};
