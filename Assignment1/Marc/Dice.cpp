//! @file 
//! @brief Implementation file for the Dice class  
//!
#pragma once
#include "stdafx.h"
#include "Dice.h"
#include <regex>

//! Implementation of the rolling dice
//! @param string : a string of the form "xdy+z"
//! @return an integer representing the addition of the value of the dice and modifier input, return -1 if the expression is invalid 
int Dice::roll(string input) {

	regex _regex("^(\\d+)[dD](\\d+)(?:\\+(\\d+))*$");

	// Initializing the result
	int result = 0;

	// Validating the roll input using regular expression
	if (!regex_match(input, _regex))
	{
		cout << "Invalid roll input" << endl;
		cout << endl;
		return -1;
	}

	// Splitting the input into the number of dice and the rest of the string
	int numDice = stoi(input.substr(0, input.find('d')));
	string extraInput = input.substr(input.find('d') + 1, sizeof(input));

	// Initiating the kind of dice and the modifier
	int kindDice = 0;
	int modifier = 0;

	// Checking to see if there is a modifier, 
	// if it's the case, split the rest of the input into the kind of dice and the modifier,
	// if not, store the rest of the input as the modifier
	if (extraInput.find('+') != string::npos)
	{
		kindDice = stoi(extraInput.substr(0, extraInput.find('+')));
		modifier = stoi(extraInput.substr(extraInput.find('+') + 1, sizeof(extraInput)));
	}
	else
	{
		kindDice = stoi(extraInput);
	}

	// Initiating the random number generation and its distribution
	random_device randomNum;
	mt19937 seed(randomNum());
	uniform_int_distribution<> generator(1, kindDice);

	// Outputting the nature of the roll
	cout << "Rolling " << numDice << " d" << kindDice << endl;

	// Rolling the number of dice of the kind specified by the input and outputting each roll 
	// as well as incrementing the overall result by the results of the individual rolls
	for (int n = 0; n < numDice; ++n)
	{
		int tempRoll = generator(seed);
		cout << "Rolled: " << tempRoll << endl;
		result += tempRoll;
	}

	// Outputting the modifier
	cout << "Modifier: +" << modifier << endl;

	// Incrementing the result by the modifier
	result += modifier;

	// Outputting the result
	cout << "Result: " << result << endl;
	cout << endl;

	return result;
}
