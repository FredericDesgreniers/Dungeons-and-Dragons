//! @file 
//! @brief Implementation file for the MapTest class  
//!

#include "stdafx.h"
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include "Map.h"
#include "MapView.h"
using namespace CppUnit;

//! Test Class for the Map and MapView classes
class MapTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(MapTest);
	CPPUNIT_TEST(testAttachMapToMapView);
	CPPUNIT_TEST(testMovePlayer);
	CPPUNIT_TEST_SUITE_END();
protected:
	void testAttachMapToMapView();
	void testMovePlayer();
};

//! cppunit test cases registration
CPPUNIT_TEST_SUITE_REGISTRATION(MapTest);

//! test method for the behavior of the Map and MapView classes
//! Test Case: attaching a Map subject to a MapView observer
//! Assertion: the MapView's subject will be the Map
void MapTest::testAttachMapToMapView()
{
	Map *testMap = new Map();
	MapView *mapView = new MapView(testMap);

	CPPUNIT_ASSERT(mapView->getSubject() == testMap);

	delete mapView;
	delete testMap;
}

//! test method for the behavior of the Map and MapView classes
//! Test Case: moving the Player on the Map
//! Assertion: the Player's end coordinate will not be the same as its initial one
//! Assertion: the Player's end coordinate will be the same the destination tile's coordinate
void MapTest::testMovePlayer()
{
	cout << endl;

	for (int i = 0; i < 100; i++)
	{
		Map *testMap = new Map();
		MapView *mapView = new MapView(testMap);

		testMap->generateMap();

		Coordinate* initialPlayerCoordinate = testMap->getPlayerCoordinate();
		Tile* destinationTile = (testMap->getWidth() <= testMap->getHeight()) ?
			testMap->getTile(initialPlayerCoordinate->getX(), initialPlayerCoordinate->getY() - 1) :
			testMap->getTile(initialPlayerCoordinate->getX() + 1, initialPlayerCoordinate->getY());

		testMap->movePlayer(destinationTile);

		CPPUNIT_ASSERT(initialPlayerCoordinate != testMap->getPlayerCoordinate());
		CPPUNIT_ASSERT(destinationTile->getCoordinate() == testMap->getPlayerCoordinate());

		delete mapView;
		delete testMap;

		cout << "---" << endl << endl;
	}
}

