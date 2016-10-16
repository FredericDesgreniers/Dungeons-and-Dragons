#include "Dice.h"

// regex for dice expression xdy/xdy+z (for limited dice size)
static const regex e("^((?:[1-9]+)(?:\\d+)*)d(100|4|6|8|10|12|20)(?:\\+((?:[1-9]+)(?:\\d+)*))?$");

// random number generator
static default_random_engine engine(time(NULL));

int Dice::roll(string string)
{
	smatch inputValue;

	if (regex_search(string, inputValue, e))
	{
		// there are three capture groups
		// 1: number of rolls
		// 2: number of faces
		// 3: optionnal modifier
		// we assign the first two here, since they are always present
		int numberOfRolls = stoi(inputValue[1]);
		int diceSize = stoi(inputValue[2]);

		// sum of all the rolls
		int rollSum = 0;

		uniform_int_distribution<int> randomNumber(1, diceSize); // creates the random distribution starting at 1
		cout << "Rolling a " << diceSize << " side die " << numberOfRolls << " times." << endl;

		// rolls dice and updates sum
		// prints to console to keep track
		for (int i = 0; i < numberOfRolls; i++)
		{
			int rollValue = randomNumber(engine);
			rollSum += rollValue;
			cout << "Dice #" << i + 1 << " rolled a " << rollValue << endl;
		}

		// adds modifier
		if (inputValue[3].matched)
		{
			cout << "Modifier " << inputValue[3] << " added to sum" << endl;
			rollSum += stoi(inputValue[3]);
		}
		
		cout << endl;
		return rollSum;

	}
	else
	{
		return -1;
	}

}

int main()
{
	int result = 0;
	for (int j = 1; j <= 10; j++) {
		result = Dice::roll("10d100");
		cout << "Result is " << result << endl;
	}

	cout << Dice::roll("4d100+") << endl;
	cout << Dice::roll("d20") << endl;
	cout << Dice::roll("420") << endl;
	cout << Dice::roll("4d20+") << endl;

	return 0;

}