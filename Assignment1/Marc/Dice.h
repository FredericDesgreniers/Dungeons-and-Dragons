//! @file 
//! @brief Header file for the Dice class.
//!

#pragma once
#include <string>
#include <regex>
#include <iostream>
#include <random>
using namespace std;

//! class that implements the rolling of Dice 
//! 1) The Dice class simulates the roll of a die in the real world, 
//! where it returns a random result from 1 to the highest number on the die.
//! In d20 game rules, a dice roll may include multiple dice and a modifier 
//! that will be added to the result of the roll. 
//! 2) The Dice class emulates those rules by validating an input using a 
//! regular expression and, if valid, returning the addition of the results 
//! of the specified number of random rolls from 1 to the value of the input die 
//! together, incremented by the value of the modifier, if one was included in the input.
//! 3) The <string> library was included for the input and output of strings in the solution.
//! The <iostream> library was included in the solution for the output of the results to the console.
//! The <random> library was included to provide a solution to extract a random number from a range, 
//! in order to simulate the roll of a die.
//! The <regex> library was included to make it possible to validate the input of the dice roll.
//! Using a regular expression, I was able to determine if an input was in the correct format to be 
//! interpreted by the solution. If it wasn't, the solution would now be able to generate an appropriate response
class Dice {

private:
public:
	static int Dice::roll(string string);

};