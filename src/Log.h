#pragma once
#include <string>
#include <iostream>

class Log
{
	static Log *log_instance;
	Log();

public:
	enum component{ dice, map, character, game };
	~Log();

	void toggle_Dice();
	void toggle_Map();
	void toggle_Game();
	void toggle_Character();

	void output(component comp, std::string output);


	static Log *instance();

private:
	bool l_map;
	bool l_dice;
	bool l_game;
	bool l_character;

};

