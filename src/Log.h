#pragma once
#include <string>
#include <iostream>
/**
 * Singleton used for logging events
 */
class Log
{
	//Singleton instance
	static Log *log_instance;
	/**
	 * Private constructor
	 */
	Log();

public:
	/**
	 * Different log categories
	 */
	enum component{ dice, map, character, game };
	~Log();

	/**
	 * Toggle dice logging
	 */
	void toggle_Dice();
	/**
	 * Toggle map logging
	 */
	void toggle_Map();
	/**
	 * Toggle game logging
	 */
	void toggle_Game();
	/**
	 * Toggle character logging
	 */
	void toggle_Character();
	/**
	 * Output log to console for a category
	 */
	void output(component comp, std::string output);

	/**
	 * Get singleton instance
	 */
	static Log *instance();

private:
	/**
	 * Should log map?
	 */
	bool l_map;
	/**
	 * Should log dive?
	 */
	bool l_dice;
	/**
	 * Should log game?
	 */
	bool l_game;
	/**
	 * Should log character
	 */
	bool l_character;

};

