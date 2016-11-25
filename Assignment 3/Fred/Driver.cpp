#include "character.h"
#include "Map.h"

class Map;

int main()
{
	Character* c = new Character(1);
	Map* map = new Map("test", 10, 10);
	while(true)
	{
		c->doStrategy(map);
		for (int i = 0; i < map->getEntities()->size(); i++)
		{
			Entity* en = map->getEntities()->at(i);
			if(LivingEntity* le = dynamic_cast<LivingEntity*>(en))
			{
				le->doStrategy(map);
			}
		}
	}




	return 0;
}
