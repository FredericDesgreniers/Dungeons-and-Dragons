#pragma once

#include "Subject.h"

class Observer
{

protected:
	Observer();

public:
	~Observer();

	// child class defines this function
	virtual void Update() = 0;
};