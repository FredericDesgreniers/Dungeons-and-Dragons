//! @file
//! @brief Dice implementation
//!
#include "Dice.h"

//!regex for dice expression xdy/xdy+z (for limited dice size)
static const regex rgx("^((?:[1-9]+)(?:\\d+)*)d(100|4|6|8|10|12|20)(?:\\+((?:[0-9]+)(?:\\d+)*))?$");

//!random number generator engine
static default_random_engine defaultEngine(time(NULL));

//!Empty default constructor for dice class.
Dice::Dice()
{
	//!deliberately empty
}

//!roll function for Dice class
//!/param a string of the form xdy / xdy+z
//!This string is checked against a regular expression
//!If validated the function will roll x die with y faces and a modifier z is added if required
int Dice::roll(string string)
{
	//declares the object that will hold the values extracted from the string
	smatch inputValue;

	//checks if regex matches with string
	//capture groups are extracted into an array
	if (regex_search(string, inputValue, rgx))
	{
		//!two capture groups get extracted here
		int numberOfRolls = stoi(inputValue[1]);
		int diceSize = stoi(inputValue[2]);

		//sum of all the rolls
		int rollSum = 0;

		//creates the random distribution starting at 1 to the chosen dice value
		uniform_int_distribution<int> randomNumberGenerator(1, diceSize);

		cout << "Rolling a " << diceSize << " side die " << numberOfRolls << " times." << endl;

		// rolls dice and updates sum
		// prints to console to keep track
		for (int i = 0; i < numberOfRolls; i++)
		{
			// generates a random number and adds it to the sum;
			int rollValue = randomNumberGenerator(defaultEngine);
			rollSum += rollValue;
			cout << "Dice #" << i + 1 << " rolled a " << rollValue << endl;
		}

		// adds modifier
		if (inputValue[3].matched)
		{
			cout << "Modifier " << inputValue[3] << " added to sum" << endl << endl;
			rollSum += stoi(inputValue[3]);
		}

		return rollSum;
	}
	else
	{
		cout << "Invalid dice roll. Please use the regular expression xdy or xdy+z" << endl;
		return -1;
	}
}
