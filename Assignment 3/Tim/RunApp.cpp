//! @file 
//! @brief Driver file to create and execute the test suite 
//!
//! Brief instruction on how to set CppUnit:
//! from: http ://www.comp.nus.edu.sg/~cs3215/tools/cppunitAll.html
//!
//!	First, to install cppUnit :
//!
//!	  1. Unpack the CppUnit archive file to a directory of your choice, in this example I assume it is D:\.
//!   2. Go to D:/cppunit-1.12.1/src and open the CppUnitLibraries.sln in Visual Studio.
//!	  3. Right - click on the cppunit project in the Solution Explorer pane and choose Build.
//!	  4. After successful compilation, cppunit.lib is produced which you then need to setup the Visual Studio Linker with (see below).
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
#include <string>
#include <iostream>
#include "LivingEntity.h"
#include "LivingEntityBuilder.h"
#include "Director.h"
#include "BullyBuilder.h"
#include "NimbleBuilder.h"
#include "TankBuilder.h"

 #define TEST


//! main() function. Entry point of the program
//! It does the following: 
//! 1. Create a test suite object from the registry as populated by the code in the Test Classes
//! 2. Create a test runner that will execute all the tests in the registry
//! 3. (optionally) sets an outputter that will output the results
//! 4. Run the test cases. 

int main(int argc, char* argv[])
{

#ifdef TEST
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

#else
	std::cout << "Begin Demonstration of Character Builder" << endl << endl;;
	Director* director = new Director();
	LivingEntityBuilder* bullyBuilder = new BullyBuilder;
	LivingEntityBuilder* nimbleBuilder = new NimbleBuilder;
	LivingEntityBuilder* tankBuilder = new TankBuilder;

	// Create characters of each archetype (Bully, Nimble, Tank) using the appropriate concrete 
	// builder and display information about the created character. 
	// Cycles through each archetype for levels 1, 4, 7, 10, 13, 16
	for (int i = 0; i <= 15; i+=3) {
		std::cout << "Create Level "<< to_string(i+1) <<  " Bully fighter (Priority: STR>CON>DEX>INT>CHA>WIS):" << endl;
		director->setLivingEntityBuilder(bullyBuilder);
		director->setLevel(i+1);
		director->constructLivingEntity();
		LivingEntity* bully = director->getLivingEntity();
		std::cout << bully->toString() << endl;
		delete bully;

		std::cout << "Create Level " << to_string(i+1) << " Nimble fighter (Priority: DEX>CON>STR>INT>CHA>WIS):" << endl;
		director->setLivingEntityBuilder(nimbleBuilder);
		if (i>0) director->setLevel(i+1);
		director->constructLivingEntity();
		LivingEntity* nimble = director->getLivingEntity();
		std::cout << nimble->toString() << endl;
		delete nimble;

		std::cout << "Create Level " << to_string(i+1) << " Tank fighter (Priority: CON>DEX>STR>INT>CHA>WIS):" << endl;
		director->setLivingEntityBuilder(tankBuilder);
		if (i>0) director->setLevel(i+1);
		director->constructLivingEntity();
		LivingEntity* tank = director->getLivingEntity();
		std::cout << tank->toString() << endl;
		delete tank;

		std::cout << endl << endl;
	}


	delete bullyBuilder;
	delete nimbleBuilder;
	delete tankBuilder;
	delete director;

#endif
  return 0;


}