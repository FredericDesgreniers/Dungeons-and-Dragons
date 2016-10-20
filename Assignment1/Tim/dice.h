#pragma once
#include <string>
#include <regex>
#include <iostream>
#include <random>

using namespace std;

class Dice {
private:
	static random_device seeder;
	static mt19937 engine;
	static const regex pattern;
public:
	static int Dice::roll(string string);

};