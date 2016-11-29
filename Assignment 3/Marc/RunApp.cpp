//! @file 
//! @brief Driver file to create and execute the test suite 
//!
//! Brief instruction on how to set CppUnit:
//! from: http ://www.comp.nus.edu.sg/~cs3215/tools/cppunitAll.html
//!
//!	First, to install cppUnit :
//!
//!	 1. Unpack the CppUnit archive (https://sourceforge.net/projects/cppunit/files/cppunit/1.12.1/) to a directory of your choice, in this example I assume it is D:\. 
//!  2. Go to D:/cppunit-1.12.1/src and open the CppUnitLibraries.dsw in Visual Studio.
//!  3. Select the cppunit project in the Solution Explorer and go to 'Project > Properties > Configuration Properties > Librarian > General. Put "Debug\cppunit.lib" in the ‘Output File’ textbox. 
//!  4. Right-click on the cppunit project in the Solution Explorer pane and choose Build.
//!  5. After successful compilation, D:/cppunit-1.12.1/lib/cppunit.lib is produced which you then need to setup the Visual Studio Linker with (see below).

//!
//! To setup a project from scratch for Compilation / Linking:
//!
//!	  1. Activate 'Project > Properties > C/C++ >  Code Generation > Runtime Library > Multi - threaded Debug DLL'
//!	  2. Go to 'Project > Properties > C/C++ > General'. Put "D:\cppunit-1.12.1\include" in the 'Additional Include Directories' text box.
//!	  3. Go to 'Project > Properties > Linker > Input'. Put "D:\cppunit-1.12.1\lib\cppunit.lib" in the 'Additional Dependences' text box.
//!	  4. Go to 'Project > Properties > Build Events > Post-Build Event'. Put '"$(TargetPath)"' in the 'Command Line' textbox.Put 'Unit Tests...' in the 'Description' textbox.

#include "stdafx.h"
#include "Item.h"
#include "Character.h"
#include "EquipmentWidgets.h"
#include "CharacterDecorator.h"
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
using namespace std;
using namespace EquipmentWidgets;

#define USER_TEST

//! main() function. Entry point of the program
//! It does the following: 
//! 1. Create a test suite object from the registry as populated by the code in the Test Classes
//! 2. Create a test runner that will execute all the tests in the registry
//! 3. (optionally) sets an outputter that will output the results
//! 4. Run the test cases. 
int main(int argc, char* argv[])
{

#ifndef USER_TEST

	cout << endl;

	// Get the top level suite from the registry
	CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

	// Adds the test to the list of test to run
	CppUnit::TextUi::TestRunner runner;
	runner.addTest( suite );

	// Change the default outputter to a compiler error format outputter
	runner.setOutputter( new CppUnit::CompilerOutputter( &runner.result(),
														std::cerr ) );
	// Run the tests.
	bool wasSucessful = runner.run();

	getchar();

	// Return error code 1 if the one of test failed.
	return wasSucessful ? 0 : 1;

#endif

#ifdef USER_TEST

	Character *testChar = new Character("Illidan Stormrage", 6, 4, 2, 4, 2, 3);

	Item* items[] =
	{
		new Item("Helm of Zeratul", Character::EquipmentSlot::Head, 0, 0, 0, 8, 0, 2),
		new Item("Runic Chest Plate", Character::EquipmentSlot::Chest, 0, 6, 0, 0, 0, 4),
		new Item("Studded Leather Trousers", Character::EquipmentSlot::Legs, 0, 2, 0, 0, 2, 0),
		new Item("Hand Wraps of the Monks", Character::EquipmentSlot::Hands, 3, 0, 4, 0, 0, 0),
		new Item("Pegasus Boots", Character::EquipmentSlot::Feet, 0, 0, 8, 0, 2, 0),
		new Item("Sword of a Thousand Truths", Character::EquipmentSlot::Weapon, 7, 0, 2, 0, 0, 0)
	};

	std::cout << "I have prepared a bunch of items for you:\n" << endl;

	for(int i = 0; i < 6; i++)
	{
		std::cout << items[i]->getName() << endl;
	}

	std::cout << "\nAlso, here is a basic character:\n" << endl;
	std::cout << testChar->getCharName() << endl;
	std::cout << testChar->getStats() << endl;
	std::cout << testChar->getEquipment() << endl;

	std::string gameInput = "";
	std::string equipInput = "";
	std::string removeInput = "";
	bool gameContinue = false;
	bool equipContinue = false;
	bool removeContinue = false;

	do
	{
		gameContinue = false;

		std::cout << "\nWould you like to equip (e) an item, remove (r) an item, or quit (q) ?" << endl;
		
		std::getline(std::cin, gameInput);

		if (gameInput == "e")
		{
			gameContinue = true;

			do
			{
				std::cout << "\nWhich item would you like to equip (1-6) ?" << endl;
				for (int i = 0; i < 6; i++)
				{
					std::cout << "(" << i + 1 << ")" << items[i]->getName() << endl;
				}

				equipInput = "";
				equipContinue = false;

				std::getline(std::cin, equipInput);

				testChar = equipItem(testChar, items[std::stoi(equipInput)-1]);
				std::cout << "\n" << testChar->getCharName() << endl;
				std::cout << testChar->getStats() << endl;
				std::cout << testChar->getEquipment() << endl;

				std::cout << "\nWould you like to equip another item (y/n) ?" << endl;

				std::getline(std::cin, equipInput);

				equipContinue = (equipInput != "n");

			} while (equipContinue);
		}
		else if (gameInput == "r")
		{
			gameContinue = true;

			do
			{
				std::cout << "\nFrom which slot would you like to remove an item (1-6) ?" << endl;
				std::cout << "(1)Head" << endl;
				std::cout << "(2)Chest" << endl;
				std::cout << "(3)Legs" << endl;
				std::cout << "(4)Hands" << endl;
				std::cout << "(5)Feet" << endl;
				std::cout << "(6)Weapon" << endl;

				removeInput = "";
				removeContinue = false;

				std::getline(std::cin, removeInput);

				testChar = removeItemFromSlot(testChar, testChar, Character::EquipmentSlot(std::stoi(removeInput)));
				std::cout << "\n" << testChar->getCharName() << endl;
				std::cout << testChar->getStats() << endl;
				std::cout << testChar->getEquipment() << endl;

				std::cout << "\nWould you like to remove another item (y/n) ?" << endl;

				std::getline(std::cin, removeInput);

				removeContinue = (removeInput != "n");

			} while (removeContinue);
		}
		else
		{
			gameContinue = false;
		}

	} while (gameContinue);

	std::cout << "\nThank you for playing!" << endl;

	return 0;

#endif

}