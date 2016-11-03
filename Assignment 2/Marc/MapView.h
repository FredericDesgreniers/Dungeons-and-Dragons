#pragma once
#include "Map.h"
#include "Observer.h"

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
