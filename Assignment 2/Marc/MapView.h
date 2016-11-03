//! @file 
//! @brief Header file for the MapView class.
//!
#pragma once
#include "Map.h"
#include "Observer.h"

//! class that represents a concrete observer MapView, its attributes and its behavior towards its observed Subject
class MapView : public Observer
{

private:

	Map *_subject;

public:

	MapView(Map* map);
	~MapView();
	void update();
	void display();

	Map* getSubject() { return _subject; }

};
