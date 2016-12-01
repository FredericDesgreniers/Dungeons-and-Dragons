#include "Log.h"

Log::Log()
{
	l_game = l_dice = l_map = l_character = true;
}



Log::~Log()
{
	delete log_instance;
}


void Log::toggle_Dice()
{
	l_dice = !l_dice;
	std::cout << (l_dice ? "Dice logging enabled" : "Dice logging disabled.") << std::endl;
}

void Log::toggle_Map()
{
	l_map = !l_map;
	std::cout << (l_map ? "Map logging enabled" : "Map logging disabled.") << std::endl;
}

void Log::toggle_Character()
{
	l_character = !l_character;
	std::cout << (l_character ? "Character logging enabled" : "Character logging disabled.") << std::endl;
}


void Log::toggle_Game()
{
	l_game = !l_game;
	std::cout << (l_game ? "Game logging enabled" : "Game logging disabled.") << std::endl;
}


void Log::output(component comp, std::string text)
{
	switch (comp) {
	case Log::component::character:
		if (l_character)
			std::cout << text << std::endl;
		break;
	case Log::component::dice:
		if (l_dice)
			std::cout << text << std::endl;
		break;
	case Log::component::game:
		if (l_game)
			std::cout << text << std::endl;
		break;

	case Log::component::map:
		if (l_map)
			std::cout << text << std::endl;
		break;
	default:
		break;
	}
}

Log * Log::instance()
{
	if (!log_instance)
		log_instance = new Log;
	return log_instance;
}

Log *Log::log_instance;
