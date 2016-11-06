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
#include "character.h"
#include "characterObserver.h"


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
	using namespace std;
	std::cout << "Creating Random Character 'testCharacter'..." << endl;
	Character* testCharacter = new Character();
	std::cout << "\nAttaching Observer 'testObserver' and calling its Display() method:" << endl;
	CharacterObserver* testObserver = new CharacterObserver(testCharacter);
	testObserver->Display();
	std::cout << "\nHitting testCharacter for 5 damage:" << endl;
	testCharacter->hit(5);

	std::cout << "\nHealing testCharacter for 2 damage:" << endl;
	testCharacter->hit(-2);

	std::cout << "\nSetting level to 4:" << endl;
	testCharacter->setLevel(4);

	std::cout << "\nIncreasing STR by 1:" << endl;
	testCharacter->setStrength(testCharacter->getStrength() + 1);

	std::cout << "\nSetting WIS to 6:" << endl;
	testCharacter->setWisdom(6);

	std::cout << "\n\nAttaching second Observer 'testObserver2' ..." << endl;
	std::cout << "NOTE: Outputs will be duplicated to show that 2 observers are being notified of changes!" << endl;
	CharacterObserver* testObserver2 = new CharacterObserver(testCharacter);

	std::cout << "\nDecreasing CON by 1:" << endl;
	testCharacter->setConstitution(testCharacter->getConstitution() - 1);

	std::cout << "\nIncreasing INT by 3:" << endl;
	testCharacter->setIntelligence(testCharacter->getIntelligence() + 3);

	std::cout << "\nIncreasing DEX by 2:" << endl;
	testCharacter->setDexterity(testCharacter->getDexterity() + 2);

	std::cout << "\nSetting CHA to 18:" << endl;
	testCharacter->setCharisma(18);

	std::cout << "\n\nDetaching both observers from testCharacter ..." << endl;
	std::cout << "The following changes will not cause the updated stats to be displayed since observers are no longer attached." << endl;
	testCharacter->Detach(testObserver);
	testCharacter->Detach(testObserver2);

	std::cout << "\nDecreasing level by 2..." << endl;
	testCharacter->setLevel(testCharacter->getLevel() - 1);

	std::cout << "Increasing WIS by 4..." << endl;
	testCharacter->setWisdom(testCharacter->getWisdom() + 4);

	std::cout << "Decreasing DEX by 2..." << endl;
	testCharacter->setDexterity(testCharacter->getDexterity() - 2);

	std::cout << "Setting CHA to 3..." << endl;
	testCharacter->setCharisma(3);


	delete(testObserver);
	delete(testObserver2);
	delete(testCharacter);
	testObserver = nullptr;
	testObserver2 = nullptr;
	testCharacter = nullptr;

#endif
  return 0;


}