#include "Dice.h"

// This regex will find all patterns of the form xdy or xdy+z and capture x, y, z if applicable
const ::regex Dice::pattern("^(\\d+)[dD](\\d+)(?:\\+(\\d+))*$"); 

//Create random device to seed generator
random_device seeder;
//Create mersenne twister engine
mt19937 engine(seeder());


int Dice::roll(::string diceInput) {

	// Declare regex result
	smatch result;

	if (::regex_search(diceInput, result, pattern)) {
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
