#include "dice.h"

int main(int argc, const char* argv[])
{
	Dice diceTest;
	diceTest.roll("4d8+20");
	diceTest.roll("3d6+4");
	diceTest.roll("2d6+1");
	diceTest.roll("2d6");
	diceTest.roll("2d6");
	diceTest.roll("3d4   ");
	diceTest.roll("3d4+14 ");
	diceTest.roll("3d8-1");
	diceTest.roll("2d6+");
	diceTest.roll("1d4+3");
	return 0;
} 