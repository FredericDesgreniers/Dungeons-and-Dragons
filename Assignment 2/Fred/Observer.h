#pragma once

/**
 * Observer gets notified when subject changes
 */
class Observer
{
public:
	/**
	 * Trigger when subject changed
	 */
	virtual void notify();
};