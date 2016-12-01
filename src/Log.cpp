#include "Log.h"

Log::Log()
{
	l_game = l_dice = l_map = l_character = true;
}



Log::~Log()
{
	delete log_instance;
}


void Log::toggle_Dice(bool val)
{
	l_dice = !l_dice;
}

void Log::toggle_Map(bool val)
{
	l_map = !l_map;
}

void Log::toggle_Character(bool val)
{
	l_character = !l_character;
}


void Log::toggle_Game(bool val)
{
	l_game = !l_game;
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
