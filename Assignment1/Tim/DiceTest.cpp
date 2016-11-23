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

}


//! test method for roll function of the Dice class 
//! Test Case: the upperbound of all values returned from roll function
void DiceTest::testDiceRollingBounds()
{
	int result = 0;
	
	for (int j = 1; j <= 100000; j++) {
		int numbers = Dice::roll("1d10");
		std::cout << to_string(numbers) << endl;;
		result = numbers;
		CPPUNIT_ASSERT(result >= 1);
		CPPUNIT_ASSERT(result <= 10);
	}

}


//! test method for roll function of the Dice class 
//! Test Case: rolling dice of invalid types (ie not d4, 6, 8, 10, 12, 20, 100)
void DiceTest::testInvalidDiceTypes()
{

}

//! test method for roll function of the Dice class 
//! Test Case: rolling multiple dice in one function call
void DiceTest::testMultipleDice()
{
	
}

