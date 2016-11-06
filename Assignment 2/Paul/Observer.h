//! @file 
//! @brief Header file for the Observer class
//!
//! Observer is the abstract observer 

#pragma once

#include "Subject.h"

class Observer
{

protected:
	//! default constructor
	Observer();

public:
	//! Destructor
	~Observer();

	//! child class defines this function when class inherited
	virtual void Update() = 0;
};