//!@file
//!@brief Dice class header file
//!
//! We implement a dice that can be rolled with only specific values
//! Only 4, 6, 8, 10, 12, 20 and 100 side dice can be rolled
//! Using the regular expression xdy or xdy+z we can roll x dice with y sides
//! and add a modifier if needed.
//! We use a regex to match the string entered when calling the roll function
//! If the regex and the string matches, the values from the capture groups are extracted
//! A default random engine is used (and seeded with <ctime>).
//! An uniform_int_distribution object is created to generate random numbers
//! The dice are then rolled and summed up. If a modifier is detected it will be added.
//!
//! We use <stdio> for NULL, <iostream> for cout to console, <string> for stoi(),
//! <regex> for the regular expression xdy/xdy+z, <ctime> to seed the random engine
//! and <random> to use the engine and declare the uniform_int_distribution.
#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include <random>
using namespace std;

//!Dice class.
//!It contains a default constructor and the roll() function as public members
class Dice
{
public:
	//!This class has no member variables
	Dice();

	//!Roll function.
	//!@param string string of the form xdy / xdy+z
	//!
	//!This string is checked against a regular expression
	//!Data from the string is extracted using regular expression's capture groups
	//!If validated the function will roll x die with y faces and a modifier z is added if required
	static int roll(string string);
};
