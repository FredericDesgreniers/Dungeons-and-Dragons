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
#include "Map.h"
#include "MapView.h"
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
using namespace std;

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
  
  char gameInput = NULL;
  bool gameContinue = false;

  Map *testMap = NULL;
  MapView *mapView = NULL;

  do
  {
	  cout << "A map is being generated for you..." << endl;
	  cout << endl;

	  testMap = new Map();
	  mapView = new MapView(testMap);

	  testMap->generateMap();

	  cout << "Do you want to play this map (y), generate another one (n), or quit (q) ?" << endl;
	  cout << endl;

	  gameInput = NULL;
	  cin >> gameInput;

	  cout << endl;

	  if (gameInput == 'n' || gameInput == 'q')
	  {
		  gameContinue = (gameInput == 'n');
		  continue;
	  }

	  bool mapContinue = false;

	  cin.clear();
	  cin.ignore();

	  do
	  {
		  cout << "Do you want to go up (w), right (d), down (s), left (a), restart with a new map (r) or quit (q) ?" << endl;
		  cout << endl;

		  cin >> gameInput;
		  cout << endl;

		  mapContinue = testMap->controlPlayer(gameInput);

		  if (testMap->isCompleted())
		  {
			  cout << endl;
			  cout << "Do you want to restart with a new map (r) or quit (q) ?" << endl;
			  cout << endl;

			  cin >> gameInput;

			  mapContinue = gameInput != 'q';
		  }

		  cout << endl;

		  cin.clear();
		  cin.ignore();

	  } while (gameInput != 'r' && gameInput != 'q' && gameInput != NULL && mapContinue);
	  
	  gameContinue = (gameInput == 'r');

	  delete mapView;
	  delete testMap;

  } while (gameContinue);

  cout << "Thank you for playing!" << endl;

  return 0;
#endif
}