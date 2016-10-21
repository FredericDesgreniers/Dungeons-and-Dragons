//! @file
//! @brief Dice class header file
//! We implement a dice that can be rolled with only specific values
//! Only 4, 6, 8, 10, 12, 20 and 100 side dice can be rolled
//! Using the regular expression xdy or xdy+z we can roll x dice with y sides
//! and add a modifier if needed.
//!
//!
//! We use a regex to match the string entered when calling the roll function
//! If the regex and the string matches, the values from the capture groups are extracted
//! A default random engine is used (and seeded with <ctime>).
//! An uniform_int_distribution object is created to generate random numbers
//! The dice are then rolled and summed up. If a modifier is detected it will be added.
#pragma once

#include <stdio.h>
#include <stdlib.h>
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
	//!Default constructor for dice class.
	//!This class has no member variables
	Dice();

	//!Roll function.
	//!This function will generate random numbers based on a regular expression
	static int roll(string string);
};
