#pragma once
#include <string>
#include <regex>
#include <iostream>
#include <random>

using namespace std;

class Dice {
private:
	static const regex pattern;
public:
	int Dice::roll(string string);

};