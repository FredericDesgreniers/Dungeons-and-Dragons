#pragma once
#include <vector>
#include "Observer.h"
/**
 * \brief Subject takes care of managing observers and notifying them
 */
class Subject
{
public:
	/**
	 * \brief Register an observer on the subject
	 * Return false if observer is already registered
	 */
	bool registerObserver(Observer* observer);

	/**
	 * \brief Unregister an observer
	 * returns false if observer was never registered
	 */
	bool unregisterObserver(Observer* observer);

	/**
	 * \brief Notify all observers of change in subject
	 */
	void notifyObservers();

	/**
	 * \brief Get pointer to observer vector
	 */
	std::vector<Observer*>* getObservers();

private:
	std::vector<Observer*> observers;
};
