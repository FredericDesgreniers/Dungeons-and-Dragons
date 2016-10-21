//! @file 
//! @brief Implementation file for the DiceTest class  
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
#include "Dice.h"
using namespace CppUnit;

//! Test Class for the Dice class
class DiceTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(DiceTest);
	CPPUNIT_TEST(testDiceRollInputValidity); //test the lower bound of the returned value 
	CPPUNIT_TEST(testDiceRollingBounds); //test the upper bound of the returned value 
	CPPUNIT_TEST(testInvalidDiceTypes); //test the upper bound of the returned value 
	CPPUNIT_TEST(testMultipleDice); //test the upper bound of the returned value 
	CPPUNIT_TEST_SUITE_END();
protected:
	void testDiceRollInputValidity();
		void testDiceRollingBounds();
		void testInvalidDiceTypes();
		void testMultipleDice();
};

//! cppunit test cases registration
CPPUNIT_TEST_SUITE_REGISTRATION(DiceTest);

//! test method for roll function of the Dice class 
//! Test Case: the the validity of input string
void DiceTest::testDiceRollInputValidity()
{
	int result = 0;
	
	// test that if the string is valid, the result is calculated
	result = Dice::roll("4d20");
	CPPUNIT_ASSERT(result > 0);
	result = Dice::roll("3d10+1");
	CPPUNIT_ASSERT(result > 0);

	//test that is the string is invalid, roll() returns -1
	result = Dice::roll("4d");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("d20");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("420");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("4d20+");
	CPPUNIT_ASSERT(result == -1);
}


//! test method for roll function of the Dice class 
//! Test Case: the upperbound of all values returned from roll function
void DiceTest::testDiceRollingBounds()
{
	int result = 0;
	for (int j = 1; j <= 1000; j++) {
		result= Dice::roll("1d4");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 4);
	}
	for (int j = 1; j <= 1000; j++) {
		result = Dice::roll("1d6");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 6);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d8");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 8);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d10");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 10);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d12");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 12);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d20");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 20);
	}
	for (int j = 1; j <= 1000; j++) {
		int numbers = Dice::roll("1d100");
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 100);
	}
}


//! test method for roll function of the Dice class 
//! Test Case: rolling dice of invalid types (ie not d4, 6, 8, 10, 12, 20, 100)
void DiceTest::testInvalidDiceTypes()
{
	int result = 0;
	result = Dice::roll("2d9");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("1d102");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("4d17");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("1d11");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("1d62");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("1d10000");
}

//! test method for roll function of the Dice class 
//! Test Case: rolling multiple dice in one function call
void DiceTest::testMultipleDice()
{
	for (int j = 1; j <= 500; j++) {
		int result = Dice::roll("2d6");
		CPPUNIT_ASSERT(result >= 2);
		CPPUNIT_ASSERT(result <= 12);
	}

	for (int j = 1; j <= 500; j++) {
		int result = Dice::roll("3d8");
		CPPUNIT_ASSERT(result >= 3);
		CPPUNIT_ASSERT(result <= 24);
	}

	for (int j = 1; j <= 500; j++) {
		int result = Dice::roll("4d10");
		CPPUNIT_ASSERT(result >= 4);
		CPPUNIT_ASSERT(result <= 40);
	}

	for (int j = 1; j <= 500; j++) {
		int result = Dice::roll("5d12");
		CPPUNIT_ASSERT(result >= 5);
		CPPUNIT_ASSERT(result <= 60);
	}

	for (int j = 1; j <= 500; j++) {
		int result = Dice::roll("6d20");
		CPPUNIT_ASSERT(result >= 6);
		CPPUNIT_ASSERT(result <= 120);
	}

	for (int j = 1; j <= 500; j++) {
		int result = Dice::roll("7d100");
		CPPUNIT_ASSERT(result >= 7);
		CPPUNIT_ASSERT(result <= 700);
	}
}

