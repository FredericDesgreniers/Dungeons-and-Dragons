//! @file 
//! @brief Implementation file for the Character Testing class  
//!

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
using namespace CppUnit;
#include "Character.h"
#include "CharacterObserver.h"


//! Test Class for the Character class
class CharacterTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(CharacterTest);
	CPPUNIT_TEST(testAttach);
	CPPUNIT_TEST(testScoreUpdate);
	CPPUNIT_TEST_SUITE_END();
protected:
	void testAttach();
	void testScoreUpdate();
};

//! test case registration
CPPUNIT_TEST_SUITE_REGISTRATION(CharacterTest);

//! test method for the Observer pattern
//! Test case: attaching a Character to a Character Observer
//! Assertion: the CharacterObserver's subject is the Character
void CharacterTest::testAttach()
{
	Character* goku = new Character(1, 1, 1, 1, 1, 1);
	CharacterObserver* o = new CharacterObserver(goku);

	CPPUNIT_ASSERT(o->getSubject() == goku);

	delete o;
	delete goku;
}


//! test method to test the changes to a character's scores and hitpoints
//! Test Case: setters() and hit(), call to these should trigger re display of the object with Observer pattern
//! Assertion: the values have changed and Observer is attached
void CharacterTest::testScoreUpdate()
{
	Character* goku = new Character(10, 10, 10, 10, 10, 10);
	CharacterObserver* o = new CharacterObserver(goku);

	// each call will redisplay the character scores
	goku->setCharisma(5);
	goku->setDexterity(12);
	goku->setConsitution(7);
	goku->hit(6);

	// we assert that the scores have changed
	CPPUNIT_ASSERT(goku->getCharisma() == 5);
	CPPUNIT_ASSERT(goku->getDexterity() == 12);
	CPPUNIT_ASSERT(goku->getConsitution() == 7);
	CPPUNIT_ASSERT(goku->getHitPoints() == (4));
	CPPUNIT_ASSERT(o->getSubject() == goku);

	delete o;
	delete goku;
}