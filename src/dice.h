//! @file 
//! @brief Header file for the Dice class 
//!
#pragma once
#include <regex>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include "Log.h"


using namespace std;

//!  Dice class 
/*!
  Used in simulating dice rolls for D&D style gameplay. 
  This class contains a single static function called roll which takes a string in valid dice notation and returns the resulting simulated dice rolls. 

  <regex> library is used to verify strings are in correct dice notation and parse them for relevant data. 

  <random> library is used for random_device, mt19937, and uniform_distribution types. We use a random_device to produce a non-deterministic seed for an mt19937
  mersenne twister engine, then define a uniform distribution between 1 and the value of the dice being rolled.  The reason for using a mersenne twister over a
  simpler rand() implementation is that mt19937 generates a much better approximation of randomness. Rand() used in combination with mod generates numbers biased towards 
  the lower end. By using mt19937 in conjunction with uniform distribution, we generate unbiased, uniformly distributed numbers between 1 and the dice value with
  very small overhead. 

  <iostream> is used to output to console for testing and debugging purposes

*/
class Dice {
private:
	/** random_device
	*
	*  Generates seed for mersenne twister
	*/
	static random_device seeder;
	/** mt19937
	*
	*  Mersenne twister engine used to generate pseudorandom numbers for dice rolls
	*/
	static mt19937 engine;
	/** regex pattern
	*
	*  Regex used to verify a string is valid dice notation and parse the string
	*/
	static regex pattern;
public:
	/**
	* @brief Takes a string in dice notation and simulates dice rolls
	*
	* Takes a string in the form xdy or xdy+z and where x, z are integers and y is one of 4, 6, 8, 10, 12, 20, 100. Simulates rolling x y-sided dice and returns the result (+z if applicable)
	*/
	static int Dice::roll(string string); 

	static int rollStat();

};