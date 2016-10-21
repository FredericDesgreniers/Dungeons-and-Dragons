//! @file 
//! @brief Implementation file for the DiceTest class  
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
#include "Dice.h"
using namespace CppUnit;

//! Test Class for the Dice class
class DiceTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(DiceTest);
	CPPUNIT_TEST(testDiceRollInputValidity); //test the lower bound of the returned value 
	CPPUNIT_TEST(testDiceRollingBounds); //test the upper bound of the returned value 
	CPPUNIT_TEST(testMultipleDiceInput); //test the validity of multiple die input
	CPPUNIT_TEST(testMultipleDiceResult); //test the result of multiple die roll
	CPPUNIT_TEST_SUITE_END();
protected:
	void testDiceRollInputValidity();
	void testDiceRollingBounds();
	void testMultipleDiceInput();
	void testMultipleDiceResult();
};

//! cppunit test cases registration
CPPUNIT_TEST_SUITE_REGISTRATION(DiceTest);

//! test method for role function of the Dice class 
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


//! test method for role function of the Dice class 
//! Test Case: the upperbound of all values returned from roll function
void DiceTest::testDiceRollingBounds()
{
	int result = 0;

	for (int j = 1; j <= 1000; j++) {
		result = Dice::roll("1d4");
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
//! Test Case: the validity of multiple die input
void DiceTest::testMultipleDiceInput()
{
	int result = 0;

	result = Dice::roll("4d6+2");
	CPPUNIT_ASSERT(result > 0);
	result = Dice::roll("4x6+2");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("2d8+4");
	CPPUNIT_ASSERT(result > 0);
	result = Dice::roll("xd6+2");
	CPPUNIT_ASSERT(result == -1);
	result = Dice::roll("2d20");
	CPPUNIT_ASSERT(result > 0);
	result = Dice::roll("2d2w");
	CPPUNIT_ASSERT(result == -1);
}

//! test method for roll function of the Dice class 
//! Test Case: the result of multiple die roll
void DiceTest::testMultipleDiceResult()
{
	int result = 0;

	for (int i = 1; i <= 1000; i++) {
		result = Dice::roll("3d4+1");
		CPPUNIT_ASSERT(result >= 4);
		CPPUNIT_ASSERT(result <= 13);
	}

	for (int i = 1; i <= 1000; i++) {
		result = Dice::roll("4d6+2");
		CPPUNIT_ASSERT(result >= 6);
		CPPUNIT_ASSERT(result <= 26);
	}

	for (int i = 1; i <= 1000; i++) {
		result = Dice::roll("2d8");
		CPPUNIT_ASSERT(result >= 2);
		CPPUNIT_ASSERT(result <= 16);
	}

	for (int i = 1; i <= 1000; i++) {
		result = Dice::roll("3d10+2");
		CPPUNIT_ASSERT(result >= 5);
		CPPUNIT_ASSERT(result <= 32);
	}

	for (int i = 1; i <= 1000; i++) {
		result = Dice::roll("2d12+4");
		CPPUNIT_ASSERT(result >= 6);
		CPPUNIT_ASSERT(result <= 28);
	}

	for (int i = 1; i <= 1000; i++) {
		result = Dice::roll("2d20");
		CPPUNIT_ASSERT(result >= 2);
		CPPUNIT_ASSERT(result <= 40);
	}

	for (int i = 1; i <= 1000; i++) {
		result = Dice::roll("3d100+15");
		CPPUNIT_ASSERT(result >= 18);
		CPPUNIT_ASSERT(result <= 315);
	}
}
