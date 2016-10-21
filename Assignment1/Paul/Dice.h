//! @file
//! @brief Dice class header file
//! We implement a dice that can be rolled with only specific values
//! Only 4, 6, 8, 10, 12, 20 and 100 side dice can be rolled
//! Using the regular expression xdy or xdy+z we can roll x dice with y sides
//! and add a modifier if needed.

//!
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
