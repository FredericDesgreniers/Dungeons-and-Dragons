
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include "Observer.h"
#include "character.h"

class ObserverTest1 :public Observer
{
public:
	ObserverTest1();
	void notify() override;
private:
	Character character;
};

ObserverTest1::ObserverTest1():character(1)
{
	std::cout << "registering character (should be true): " << character.registerObserver(this) << std::endl;
	std::cout << "Setting str to 18" << std::endl;
	character.setStrength(18);
	std::cout << "Setting level to 10" << std::endl;
	character.setLevel(10);
	std::cout << "Setting dext to 20" << std::endl;
	character.setDexterity(20);
	std::cout <<"registering character again (should be false): "<< character.registerObserver(this) << std::endl;
	std::cout << "unregistering character (should be true): " << character.unregisterObserver(this) << std::endl;
	std::cout << "unregistering character again (should be false): " << character.unregisterObserver(this) << std::endl;
}

void ObserverTest1::notify()
{
	std::cout << "Observer notified, redisplaying character info!" << std::endl;

	std::cout << character.toString() << std::endl;
};

// #define cppunit
int main(int argc, char* argv[])
{
#ifdef cppunit 
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
	ObserverTest1 ot;

	getchar();

	return 0;
#endif
}