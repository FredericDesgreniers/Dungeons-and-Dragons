

//! @file 
//! @brief Implementation file for the CharacterBuilderTest class  
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
#include "LivingEntity.h"
#include "LivingEntityBuilder.h"
#include "Director.h"
#include "BullyBuilder.h"
#include "NimbleBuilder.h"
#include "TankBuilder.h"

using namespace CppUnit;

//! Test Class for the Characterbuilder
class characterBuilderTest : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(characterBuilderTest);
	CPPUNIT_TEST(testPriorities); //test that bullies have correct stat priority
	CPPUNIT_TEST(testBounds); //test that tanks have correct stat priority
	CPPUNIT_TEST(testSecondaryStats); //test that tanks have correct stat priority
	CPPUNIT_TEST_SUITE_END();
protected:
	void testPriorities();
	void testSecondaryStats();
	void testBounds();

};

//! cppunit test cases registration
CPPUNIT_TEST_SUITE_REGISTRATION(characterBuilderTest);


//! test method for character builder class.
//! Test Case: Check that characters made with each concrete builder correctly prioritize ability distribution:
//!  Tank: Constitution > Dexterity> Strength > Intelligence > Charisma > Wisdom
//!  Bully: Strength > Constitution > Dexterity > Intelligence > Charisma > Wisdom
//!  Nimble: Dexterity> Constitution > Strength > Intelligence > Charisma > Wisdom
//!  Fails if any lower priority ability score has a higher value than a higher priority score.
void characterBuilderTest::testPriorities()
{

	std::cout << "\nRunning testPriorities..." << endl;
	Director* director = new Director();
	LivingEntityBuilder* tankBuilder = new TankBuilder;
	LivingEntityBuilder* nimbleBuilder = new NimbleBuilder;
	LivingEntityBuilder* bullyBuilder = new BullyBuilder;
	LivingEntity* test;


	// Set director to use tankBuilder 
	director->setLivingEntityBuilder(tankBuilder);
	// Verify that characters created with the tank concrete builder have 
	// ability scores assigned in the correct priority
	for (int i = 0; i < 50; i++) {
		director->constructLivingEntity();
		test = director->getLivingEntity();
		CPPUNIT_ASSERT(test->getConstitution() >= test->getDexterity() &&
			test->getDexterity() >= test->getStrength() &&
			test->getStrength() >= test->getIntelligence() &&
			test->getIntelligence() >= test->getCharisma() &&
			test->getCharisma() >= test->getWisdom()
		);
		delete test;

	}

	// Set director to use nimbleBuilder 
	director->setLivingEntityBuilder(nimbleBuilder);
	// Verify that characters created with the nimble concrete builder have 
	// ability scores assigned in the correct priority
	for (int i = 0; i < 50; i++) {
		director->constructLivingEntity();
		test = director->getLivingEntity();
		CPPUNIT_ASSERT(test->getDexterity() >= test->getConstitution() &&
			test->getConstitution() >= test->getStrength() &&
			test->getDexterity() >= test->getIntelligence() &&
			test->getIntelligence() >= test->getCharisma() &&
			test->getCharisma() >= test->getWisdom()
		);
		delete test;

	}

	// Set director to use bullyBuilder 
	director->setLivingEntityBuilder(bullyBuilder);
	// Verify that characters created with the bully concrete builder have 
	// ability scores assigned in the correct priority
	for (int i = 0; i < 100; i++) {
		director->constructLivingEntity();
		test = director->getLivingEntity();
		CPPUNIT_ASSERT(test->getStrength() >= test->getConstitution() &&
			test->getConstitution() >= test->getDexterity() &&
			test->getDexterity() >= test->getIntelligence() &&
			test->getIntelligence() >= test->getCharisma() &&
			test->getCharisma() >= test->getWisdom()
		);
		delete test;

	}



	delete tankBuilder;
	delete nimbleBuilder;
	delete bullyBuilder;
	delete director;

}


//! test method for character builder class.
//! Test Case: Check that HP and secondary stats are within appropriate bounds for characters created at various levels with each concrete builder.
//! Checks the following conditions:
//! HP must be greater than or equal to (level * (1d10 + CON modifier)).
//! Attack bonus must be equal to level + STR modifier.
//! Attacks per turn must be equal to (1 + level / 6).
//! Saving throws must be equal to: Fortitude: 2+level/2, Will: level/3, Reflex: level/3
//! AC must be equal to 10 + Dex modifier + 4 (from starting equipment)
//! 
void characterBuilderTest::testSecondaryStats()
{

	std::cout << "\nRunning testSecondaryStats..." << endl;

	Director* director = new Director();
	LivingEntityBuilder* tankBuilder = new TankBuilder;
	LivingEntityBuilder* nimbleBuilder = new NimbleBuilder;
	LivingEntityBuilder* bullyBuilder = new BullyBuilder;
	LivingEntity* test;


	director->setLivingEntityBuilder(nimbleBuilder);

	for (int i = 1; i < 20; i++) {
		director->setLevel(i);
		director->constructLivingEntity();
		test = director->getLivingEntity();
		CPPUNIT_ASSERT(test->getAttackBonus() == i + test->getModifier(0));
		CPPUNIT_ASSERT(test->getAttacksPerTurn() == (1 + i / 6));
		CPPUNIT_ASSERT(test->getSavingThrow(0) ==  2 + (i / 2));
		CPPUNIT_ASSERT(test->getSavingThrow(1) == i / 3);
		CPPUNIT_ASSERT(test->getSavingThrow(2) == i / 3);
		CPPUNIT_ASSERT(test->getMaxHealth() >= (i*(1 + test->getModifier(2))));
		CPPUNIT_ASSERT(test->getMaxHealth() <= (i*(10 + test->getModifier(2))));
		CPPUNIT_ASSERT(test->getArmorClass() == 10 + test->getModifier(1)+4);
		delete test;
	}

	director->setLivingEntityBuilder(bullyBuilder);

	for (int i = 1; i < 20; i++) {
		director->setLevel(i);
		director->constructLivingEntity();
		test = director->getLivingEntity();
		CPPUNIT_ASSERT(test->getAttackBonus() == i+test->getModifier(0));
		CPPUNIT_ASSERT(test->getAttacksPerTurn() == (1 + i / 6));
		CPPUNIT_ASSERT(test->getSavingThrow(0) == 2 + (i / 2));
		CPPUNIT_ASSERT(test->getSavingThrow(1) == i / 3);
		CPPUNIT_ASSERT(test->getSavingThrow(2) == i / 3);
		CPPUNIT_ASSERT(test->getArmorClass() == 10 + test->getModifier(1)+4);
		CPPUNIT_ASSERT(test->getMaxHealth() >= (i*(1 + test->getModifier(2))));
		CPPUNIT_ASSERT(test->getMaxHealth() <= (i*(10 + test->getModifier(2))));
		delete test;
	}


	director->setLivingEntityBuilder(tankBuilder);

	for (int i = 1; i < 20; i++) {
		director->setLevel(i);
		director->constructLivingEntity();
		test = director->getLivingEntity();
		CPPUNIT_ASSERT(test->getAttackBonus() == i+test->getModifier(0));
		CPPUNIT_ASSERT(test->getAttacksPerTurn() == (1 + i / 6));
		CPPUNIT_ASSERT(test->getSavingThrow(0) == 2 + (i / 2));
		CPPUNIT_ASSERT(test->getSavingThrow(1) == i / 3);
		CPPUNIT_ASSERT(test->getSavingThrow(2) == i / 3);
		CPPUNIT_ASSERT(test->getArmorClass() == 10 + test->getModifier(1)+4);
		CPPUNIT_ASSERT(test->getMaxHealth() >= (i*(1 + test->getModifier(2))));
		CPPUNIT_ASSERT(test->getMaxHealth() <= (i*(10 + test->getModifier(2))));
		delete test;
	}

	
	delete nimbleBuilder;
	delete bullyBuilder;
	delete tankBuilder;
	delete director;

}

//! test method for character builder class.
//! Test Case: Check that ability scores are within allowed bounds and created characters are valid.
//! Checks for each concrete builder that all ability scores are less than 19 and greater than 2
void characterBuilderTest::testBounds()
{

	std::cout << "\nRunning testBounds..." << endl;

	Director* director = new Director();
	LivingEntityBuilder* tankBuilder = new TankBuilder;
	LivingEntityBuilder* nimbleBuilder = new NimbleBuilder;
	LivingEntityBuilder* bullyBuilder = new BullyBuilder;
	LivingEntity* test;


	// Set director to use tankBuilder 
	director->setLivingEntityBuilder(tankBuilder);
	// Verify that characters created with the tank concrete builder are valid characters
	// with ability scores within allowed bounds
	for (int i = 0; i < 50; i++) {
		director->constructLivingEntity();
		test = director->getLivingEntity();
		CPPUNIT_ASSERT(
			test->getStrength() >= 3 && test->getStrength() <= 18 &&
			test->getDexterity() >= 3 && test->getDexterity()<=18 &&
			test->getConstitution() >= 3 && test->getConstitution() <= 18 &&
			test->getIntelligence() >=3 && test->getIntelligence()<=18 &&
			test->getCharisma() >= 3 && test->getCharisma() <= 18 &&
			test->getWisdom() >= 3 && test->getWisdom() <= 18
		);
		delete test;

	}

	// Set director to use nimbleBuilder 
	director->setLivingEntityBuilder(nimbleBuilder);
	// Verify that characters created with the nimble concrete builder are valid characters
	// with ability scores within allowed bounds
	for (int i = 0; i < 50; i++) {
		director->constructLivingEntity();
		test = director->getLivingEntity();
		CPPUNIT_ASSERT(
			test->getStrength() >= 3 && test->getStrength() <= 18 &&
			test->getDexterity() >= 3 && test->getDexterity() <= 18 &&
			test->getConstitution() >= 3 && test->getConstitution() <= 18 &&
			test->getIntelligence() >= 3 && test->getIntelligence() <= 18 &&
			test->getCharisma() >= 3 && test->getCharisma() <= 18 &&
			test->getWisdom() >= 3 && test->getWisdom() <= 18
		);
		delete test;

	}

	// Set director to use bullyBuilder 
	director->setLivingEntityBuilder(bullyBuilder);
	// Verify that characters created with the bully concrete builder are valid characters
	// with ability scores within allowed bounds
	for (int i = 0; i < 100; i++) {
		director->constructLivingEntity();
		test = director->getLivingEntity();
		CPPUNIT_ASSERT(
			test->getStrength() >= 3 && test->getStrength() <= 18 &&
			test->getDexterity() >= 3 && test->getDexterity() <= 18 &&
			test->getConstitution() >= 3 && test->getConstitution() <= 18 &&
			test->getIntelligence() >= 3 && test->getIntelligence() <= 18 &&
			test->getCharisma() >= 3 && test->getCharisma() <= 18 &&
			test->getWisdom() >= 3 && test->getWisdom() <= 18
		);
		delete test;

	}



	delete tankBuilder;
	delete nimbleBuilder;
	delete bullyBuilder;
	delete director;


}

