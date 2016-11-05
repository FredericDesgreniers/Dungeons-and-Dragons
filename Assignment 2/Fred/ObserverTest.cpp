//! @file 
//! @brief Implementation file for the Character Testing class  
//!
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
using namespace CppUnit;
#include "character.h"

//! Test Class for the Character class
class ObserverTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(ObserverTest);
	CPPUNIT_TEST(testAddObserver);
	CPPUNIT_TEST(testAddBadObserver);
	CPPUNIT_TEST(testRemoveObserver);
	CPPUNIT_TEST(testRemoveBadObserver);
	CPPUNIT_TEST_SUITE_END();
protected:
	/**
	 * test method to test adding new observer to a subject
	 * Test Case: The observer should be added to the subject and returned true
	 * Test Item: Subject::RegisterObserver() 
	*/
	void testAddObserver();
	/**
	* test method to test removing a registered observer from subject
	* Test Case: The observer should be removed from subject and returned true
	* Test Item: Subject::UnregisterObserver()
	*/
	void testRemoveObserver();
	/**
	* test method to test removing a non-registered observer from subject
	* Test Case: Subject shoudl no nothing and return false
	* Test Item: Subject::UnregisterObserver()
	*/
	void testRemoveBadObserver();
	/**
	* test method to test adding an existing observer to the subject
	* Test Case: The observer should not be added to the subject and returned false
	* Test Item: Subject::RegisterObserver()
	*/
	void testAddBadObserver();
};

//! test case registration
CPPUNIT_TEST_SUITE_REGISTRATION(ObserverTest);

void ObserverTest::testAddObserver()
{
	Character c(1);
	Observer o;
	CPPUNIT_ASSERT(c.registerObserver(&o));
}

void ObserverTest::testAddBadObserver()
{
	Character c(1);
	Observer o;
	c.registerObserver(&o);
	CPPUNIT_ASSERT(!c.registerObserver(&o));
}

void ObserverTest::testRemoveObserver()
{
	Character c(1);
	Observer o;
	c.registerObserver(&o);
	CPPUNIT_ASSERT(c.unregisterObserver(&o));
}

void ObserverTest::testRemoveBadObserver()
{
	Character c(1);
	Observer o;
	CPPUNIT_ASSERT(!c.unregisterObserver(&o));
}

