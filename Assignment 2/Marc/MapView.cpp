#include "stdafx.h"
#include "MapView.h"
#include <iostream>
using namespace std;

MapView::MapView(Map* map)
{
	_subject = map;
	_subject->Attach(this);
}

MapView::~MapView()
{
	_subject->Detach(this);
}

void MapView::update()
{
	display();
}

void MapView::display()
{
	for (int y = 0; y < _subject->getHeight(); y++)
	{
		for (int x = 0; x < _subject->getWidth(); x++)
		{
			cout << " " << _subject->getTile(x, y)->getEntity() << " ";
		}
		cout << endl;
	}

	cout << endl;
}