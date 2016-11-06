//! @file 
//! @brief Implementation file for the CharacterObserverTest class  
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
#include "Character.h"
#include "CharacterObserver.h"

using namespace CppUnit;

//! Test Class for the CharacterObserver
class characterObserverTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(characterObserverTest);
	CPPUNIT_TEST(testNotifications); //test the lower bound of the returned value 
	CPPUNIT_TEST(testMultipleObservers); //test the upper bound of the returned value 
	CPPUNIT_TEST(testAttachDetach); //test the upper bound of the returned value 
	CPPUNIT_TEST_SUITE_END();
protected:
	void testNotifications();
	void testMultipleObservers();
	void testAttachDetach();
};

//! cppunit test cases registration
CPPUNIT_TEST_SUITE_REGISTRATION(characterObserverTest);

//! test method for character observer class.
//! Test Case: Check that each function in Character that should notify observer does so correctly
void characterObserverTest::testNotifications()
{
	std::cout << "\nRunning testNotifications..." << endl;
	Character* testCharacter = new Character();
	CharacterObserver* testCharacterObserver = new CharacterObserver(testCharacter);

	//Verify observer is notified upon updating Strength
	testCharacter->setStrength(18);
	CPPUNIT_ASSERT(testCharacterObserver->updated);
	testCharacterObserver->updated = false;

	//Verify observer is notified upon updating Dexterity
	testCharacter->setDexterity(18);
	CPPUNIT_ASSERT(testCharacterObserver->updated);
	testCharacterObserver->updated = false;

	//Verify observer is notified upon updating Constitution
	testCharacter->setConstitution(18);
	CPPUNIT_ASSERT(testCharacterObserver->updated);
	testCharacterObserver->updated = false;

	//Verify observer is notified upon updating Intelligence
	testCharacter->setIntelligence(18);
	CPPUNIT_ASSERT(testCharacterObserver->updated);
	testCharacterObserver->updated = false;

	//Verify observer is notified upon updating Wisdom
	testCharacter->setWisdom(18);
	CPPUNIT_ASSERT(testCharacterObserver->updated);
	testCharacterObserver->updated = false;

	//Verify observer is notified upon updating Charisma
	testCharacter->setCharisma(18);
	CPPUNIT_ASSERT(testCharacterObserver->updated);
	testCharacterObserver->updated = false;

	//Verify observer is notified upon updating Level
	testCharacter->setLevel(5);
	CPPUNIT_ASSERT(testCharacterObserver->updated);
	testCharacterObserver->updated = false;

	//Verify observer is notified upon updating Health
	testCharacter->hit(1);
	CPPUNIT_ASSERT(testCharacterObserver->updated);
	testCharacterObserver->updated = false;

	delete(testCharacterObserver);
	delete(testCharacter);
	testCharacterObserver = nullptr;
	testCharacter = nullptr;

	
}


//! test method for character observer class.
//!
//! Test Case: Attach multiple observers to a single Character and ensure all are updated correctly
void characterObserverTest::testMultipleObservers()
{
	std::cout << "\nRunning testMultipleObservers..." << endl;
	Character* testCharacter = new Character(); //Generate random character
	// Attach 3 observers to testCharacter
	CharacterObserver* testCharacterObserver1 = new CharacterObserver(testCharacter);
	CharacterObserver* testCharacterObserver2 = new CharacterObserver(testCharacter);
	CharacterObserver* testCharacterObserver3 = new CharacterObserver(testCharacter);

	//Verify all 3 observers were notified upon changing strength
	testCharacter->setStrength(18);
	CPPUNIT_ASSERT(testCharacterObserver1->updated && testCharacterObserver2->updated && testCharacterObserver3->updated);
	
	testCharacterObserver1->updated = false;
	testCharacterObserver2->updated = false;
	testCharacterObserver3->updated = false;

	//Verify all 3 observers were notified upon changing level
	testCharacter->setLevel(8);
	CPPUNIT_ASSERT(testCharacterObserver1->updated && testCharacterObserver2->updated && testCharacterObserver3->updated);

	delete(testCharacterObserver1);
	delete(testCharacterObserver2);
	delete(testCharacterObserver3);
	delete(testCharacter);
	testCharacterObserver1 = nullptr;
	testCharacterObserver2 = nullptr;
	testCharacterObserver3 = nullptr;
	testCharacter = nullptr;
}


//! test method for character observer class.
//! Test Case: Detach and reattach observer to character both by explicitly calling 
//! attach/detatch functions and by calling the CharacterObserver's constructor/destructor

void characterObserverTest::testAttachDetach()
{
	std::cout << "\nRunning testAttachDetach..." << endl;
	Character* testCharacter = new Character();
	CharacterObserver* testCharacterObserver = new CharacterObserver(testCharacter);

	testCharacter->Detach(testCharacterObserver);
	testCharacter->setCharisma(10); // There should be no output here because no observers are attached
	// Reattach observer to testCharacter
	testCharacter->Attach(testCharacterObserver); 
	
	// Observer updated field should be false since it was detached when changes were made to testCharacter
	CPPUNIT_ASSERT(!testCharacterObserver->updated);

	testCharacter->setDexterity(15); // There should be output here because observer is attached
	// Observer updated field should be true since it was attached when changes were made to testCharacter
	CPPUNIT_ASSERT(testCharacterObserver->updated);

	// Call testCharacterObserver destructor to detach from testCharacter
	delete(testCharacterObserver);
	testCharacterObserver = nullptr;

	testCharacterObserver=new CharacterObserver(testCharacter);// Reattach by constructing a new testCharacterObserver
	testCharacter->setLevel(15); // There should be output here because observer is attached
	// Observer updated field should be true since it was attached when changes were made to testCharacter
	CPPUNIT_ASSERT(testCharacterObserver->updated);


	delete(testCharacterObserver);
	delete(testCharacter);
	testCharacterObserver = nullptr;
	testCharacter = nullptr;
}

