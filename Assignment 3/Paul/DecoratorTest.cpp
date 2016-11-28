//! @file 
//! @brief Implementation file for the Decorator Testing class  
//!
//! Runs two test cases to evaluate the Decorator Pattern

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
#include "AbstractCharacter.h"
#include "CharacterDecorator.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"
#include "Weapon.h"
#include <iostream>



//! Test Class for the Character class
class DecoratorTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(DecoratorTest);
	CPPUNIT_TEST(testUpdate);
	CPPUNIT_TEST(testInventory);
	CPPUNIT_TEST_SUITE_END();
protected:
	void testUpdate();
	void testInventory();
};

//! test case registration
CPPUNIT_TEST_SUITE_REGISTRATION(DecoratorTest);

//! test method for the Observer pattern
//! Test case: decorates character and verifies the scores are right
//! Assertion: the AbstractCharacter is decorated corretly
void DecoratorTest::testUpdate()
{
	AbstractCharacter *c = new Character(1, 1, 1, 1, 1, 1, 1, 1, 1);

	// adding a Helmet booting intelligence, armor class and wisdom by 1
	c = new Helmet(c, 1, 1, 1);

	CPPUNIT_ASSERT(c->getIntelligence() == 2);
	CPPUNIT_ASSERT(c->getWisdom() == 2);
	CPPUNIT_ASSERT(c->getArmorClass() == 2);

	delete c;
}


//! test method to test the changes to a character's scores and hitpoints
//! Test Case: Decorator now allowing multiple items worn
//! Assertion: The abstractCharacter is decorated corretly
void DecoratorTest::testInventory()
{
	AbstractCharacter *c = new Character(1, 1, 1, 1, 1, 1, 1, 1, 1);

	c = new Armor(c, 1);

	// trying to add a second armor, will display a messahe
	c = new Armor(c, 1);

	c = new Shield(c, 1);

	// trying to add a second shield, will display a message
	c = new Shield(c, 1);


	// we added 4 items but only two will be allowed and have an effect on the scores
	CPPUNIT_ASSERT(c->getArmorClass() == 3);

	delete c;
}