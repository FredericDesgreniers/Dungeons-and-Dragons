//! @file 
//! @brief Implementation file for the MapView class  
//!
#pragma once
#include "stdafx.h"
#include "MapView.h"
#include <iostream>
using namespace std;

//! Custom constructor
//! @param Map : a pointer to the map to be observed
MapView::MapView(Map* map)
{
	_subject = map;
	_subject->Attach(this);
}

//! Deconstructor
MapView::~MapView()
{
	_subject->Detach(this);
}

//! The update function, called every time the subject notifies
void MapView::update()
{
	display();
}

//! Prints the current state of the observed map to the console
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