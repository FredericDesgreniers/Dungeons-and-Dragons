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
//!  3. Select the cppunit project in the Solution Explorer and go to 'Project > Properties > Configuration Properties > Librarian > General. Put "Debug\cppunit.lib" in the �Output File� textbox. 
//!  4. Right-click on the cppunit project in the Solution Explorer pane and choose Build.
//!  5. After successful compilation, D:/cppunit-1.12.1/lib/cppunit.lib is produced which you then need to setup the Visual Studio Linker with (see below).

//!
//! To setup a project from scratch for Compilation / Linking:
//!
//!	  1. Activate 'Project > Properties > C/C++ >  Code Generation > Runtime Library > Multi - threaded Debug DLL'
//!	  2. Go to 'Project > Properties > C/C++ > General'. Put "D:\cppunit-1.12.1\include" in the 'Additional Include Directories' text box.
//!	  3. Go to 'Project > Properties > Linker > Input'. Put "D:\cppunit-1.12.1\lib\cppunit.lib" in the 'Additional Dependences' text box.
//!	  4. Go to 'Project > Properties > Build Events > Post-Build Event'. Put '"$(TargetPath)"' in the 'Command Line' textbox.Put 'Unit Tests...' in the 'Description' textbox.

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include "Character.h"
#include "AbstractCharacter.h"
#include "CharacterDecorator.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"
#include "Ring.h"
#include "Boots.h"
#include "Weapon.h"
#include "Belt.h"
#include <iostream>


#define DRIVER

//! main() function. Entry point of the program
//! It does the following: 
//! 1. Create a test suite object from the registry as populated by the code in the Test Classes
//! 2. Create a test runner that will execute all the tests in the registry
//! 3. (optionally) sets an outputter that will output the results
//! 4. Run the test cases. 
int main(int argc, char* argv[])
{
	// Get the top level suite from the registry
	CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

	// Adds the test to the list of test to run
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(suite);

	// Change the default outputter to a compiler error format outputter
	runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(),
		std::cerr));
	// Run the tests.
	bool wasSucessful = runner.run();

	getchar();

#ifdef DRIVER

	std::cout << "We will try to add each type of items twice then displays scores" << std::endl;
	AbstractCharacter *c = new Character(1, 1, 1, 1, 1, 1, 1, 1, 1);

	c = new Weapon(c, 1, 1);
	c = new Weapon(c, 1, 1);

	c = new Shield(c, 1);
	c = new Shield(c, 1);

	c = new Armor(c, 1);
	c = new Armor(c, 1);

	c = new Ring(c, 1, 1, 1, 1, 1);
	c = new Ring(c, 1, 1, 1, 1, 1);

	c = new Helmet(c, 1, 1, 1);
	c = new Helmet(c, 1, 1, 1);

	c = new Boots(c, 1, 1);
	c = new Boots(c, 1, 1);

	c = new Belt(c, 1, 1);
	c = new Belt(c, 1, 1);

	// will print stats
	std::cout << c->toString() << std::endl;

	// will print inventory: note that onle one item of each type is allowed
	std::cout << c->inventoryDisplay() << std::endl;

#endif DRIVER

	// Return error code 1 if the one of test failed.
	return wasSucessful ? 0 : 1;
}