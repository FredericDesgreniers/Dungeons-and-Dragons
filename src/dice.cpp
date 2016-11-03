//! @file 
//! @brief Dice class implementation 
//!

#include "Dice.h"

// This regex will find all patterns of the form xdy or xdy+z and capture x, y, z if applicable
regex Dice::pattern("^(\\d+)[dD](4|6|8|10|12|20|100)(?:\\+(\\d+))*$"); 
//Create random device to seed generator
random_device Dice::seeder;
//Create mersenne twister engine
mt19937 Dice::engine(Dice::seeder());


// Roll Function for the dice class
// Takes a string in the form xdy or xdy+z where x, y, z are integers and returns a dice roll
int Dice::roll(string diceInput) {

	// Declare regex result 
	smatch result;

	if (regex_search(diceInput, result, pattern)) {
		//Input is valid dice notation
		//Store parsed data for x, y in integers, initialize variables
		int diceNum = stoi(result[1]), diceVal = stoi(result[2]), diceMod = 0, rollSum = 0, currentRoll = 0;
		cout << "Rolling " << diceInput << endl;;
		

		//Define uniform distribution from 1 to diceVal
		uniform_int_distribution<int> dist(1, diceVal);

		// Roll [diceNum] pseudorandom numbers between 1 and [diceVal], store their sum in rollSum. Output result of each roll
		for (int i = 0; i < diceNum; i++) {
			currentRoll = dist(engine);
			cout << "Roll " << i + 1 << ": " << currentRoll << endl;
			rollSum += currentRoll;
		}

		// Check if z exists and if so, store it in diceMod and add it to sum
		if (result[3].matched) {
			diceMod = stoi(result[3]);
			cout << "Modifier: +" << diceMod << endl;
			rollSum += diceMod;
		}

		// Output the final roll sum
		cout << "Total: " << rollSum << endl << endl; 
		return rollSum;
	}

	else {
		cout << "Invalid input string '" << diceInput << "': input must be in the form xdy or xdy+z" << endl << endl;
		return -1;
	}

}

int Dice::rollStat() {
	int rolls[4] = { 0,0,0,0 };
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += rolls[i] = roll("1d6");
	}
	int smallest = rolls[0];
	for (int i = 1; i < 4; i++) {
		if (rolls[i] < smallest)
			smallest = rolls[i];
	}
	sum -= smallest;

	return sum;

}


