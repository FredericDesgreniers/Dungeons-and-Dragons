#include "character.h"
#include "Map.h"
#include "MapBuilder.h"
#include <iostream>

class Map;
/**
 * Print the map
 */
void printMap(Map* map)
{
	
	for (int y = 0; y < map->getHeight(); y++)
	{
		for (int x = 0; x < map->getWidth(); x++)
		{
			if(Entity* en = map->getEntity(x,y))
			{
				std::cout << en->getRenderChar();
			}else
			{
				std::cout << map->getTile(x, y)->getId();
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	Character* c = new Character(1);
	Map* map = MapBuilder::createEmptyMap(10, 10)->spawnCharacter(c)->spawnRandomMonsters()->spawnScaledContent()->get();
	
	while(true)
	{
		//clear the screen
		std::cout << "\n\n";
		printMap(map);

		//Go through entities
		for (int i = 0; i < map->getEntities()->size(); i++)
		{
			Entity* en = map->getEntities()->at(i);
			//if living entity
			if(LivingEntity* le = dynamic_cast<LivingEntity*>(en))
			{
				//start turn
				le->setTurnFinished(false);
				//Do actions until turn is ended
				while(!le->getTurnFinished())
					le->doStrategy(map);
			}
		}
	}




	return 0;
}

