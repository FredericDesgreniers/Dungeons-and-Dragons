#include "dice.h"

using namespace std;
int main(int argc, const char* argv[])
{
	Dice diceTest;

	cout << endl << "Testing Valid Dice Rolls:" << endl << endl;
	diceTest.roll("4d8+20");
	diceTest.roll("3d6+4");
	diceTest.roll("2d6+1");
	diceTest.roll("2d6");
	diceTest.roll("21d20+0");
	diceTest.roll("2d8");
	diceTest.roll("4d12");
	diceTest.roll("6d5000+2");
	diceTest.roll("1d4+3");



	cout << endl << "Testing Invalid Dice Rolls:" << endl << endl;
	diceTest.roll("3d4   ");
	diceTest.roll("3d4+14 ");
	diceTest.roll("3d8-1");
	diceTest.roll("2d6+");
	diceTest.roll("hippo");
	diceTest.roll("xdy+z");

	return 0;
} 