#include "AbstractCharacter.h"
#include "Character.h"
#include "CharacterDecorator.h"
#include "Helmet.h"
#include "Armor.h"
#include "Shield.h"
#include "Weapon.h"
#include <iostream>


int main()
{
	AbstractCharacter *c = new Character(1, 1, 1, 1, 1, 1, 1, 1, 1);

	c = new Weapon(c, 1, 1);

	std::cout << c->toString()<< std::endl;
	c = new Weapon(c, 1, 1);
	c = new Weapon(c, 1, 1);

	std::cout << c->toString() << std::endl;


	c = new Shield(c, 1);


	std::cout << c->inventoryDisplay()<< std::endl;


	c = new Shield(c, 3);
	c = new Shield(c, 5);

	

}