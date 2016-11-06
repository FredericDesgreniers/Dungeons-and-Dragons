#pragma once

/**
 * \brief Observer gets notified when subject changes
 */
class Observer
{
public:
	/**
	 * \brief Trigger when subject changed
	 */
	virtual void notify();
};