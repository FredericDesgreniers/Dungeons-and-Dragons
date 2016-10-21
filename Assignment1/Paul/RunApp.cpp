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

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "dice.h"


//! The define Driver should be commented out if only the test cases need to be executed.
#define DRIVER
//!Main function
int main(int argc, char* argv[])
{
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
#ifdef DRIVER
  //! Driver implementation
  //! Tests different possibilities.
  // new dice object
  Dice* d = new Dice();

  int result = 0;

  cout << "------- DRIVER FOR DICE CLASS -------" << endl;
  cout << "If you wish to run the test cases, the #define TEST should NOT be commented out at the start of main" << endl << endl;

  cout << "----- Different dice can be rolled but restricted to only those -----" << endl << endl;
  result = d->roll("1d4");
  result = d->roll("1d6");
  result = d->roll("1d8");
  result = d->roll("1d10");
  result = d->roll("1d12");
  result = d->roll("1d20");
  result = d->roll("1d100");

  cout << "\n----- Multiple dice can be rolled -----" << endl << endl;
  result = d->roll("5d6");
  result = d->roll("3d10");
  result = d->roll("10d12");
  result = d->roll("9d100");

  cout << "\n----- And modifiers can be added to the sum of dice rolls -----" << endl << endl;
  result = d->roll("1d4+15");
  result = d->roll("1d8+13");
  result = d->roll("2d12+8");
  result = d->roll("13d4+140");

  delete d;
  d = NULL;
#endif DRIVER

  // Return error code 1 if the one of test failed.
  return wasSucessful ? 0 : 1;
}
