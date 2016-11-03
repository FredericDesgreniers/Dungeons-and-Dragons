//! @file 
//! @brief Header file for the Observer class.
//!
#pragma once

//! class that represents an abstract Observer, its attributes and its behavior
class Observer {

protected:

	Observer();

public:

	~Observer();
	virtual void update() = 0;

};
