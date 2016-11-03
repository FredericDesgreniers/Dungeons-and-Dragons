#include "Character.h"
#include "CharacterObserver.h"
#include <iostream>
using namespace std;

int main()
{
	// new Character object with 4 in all stats
	Character* c = new Character(4, 4, 4, 4, 4, 4);

	// new concrete observer
	CharacterObserver* o = new CharacterObserver(c);
	
	// print stats from base object
	cout << "New character created with following stats: " << c->toString() << endl;

	// The following lines will change the attributes of the character object
	// The observer pattern will register those changes and display the new stats
	// modifying Charisma and Constitution
	c->setCharisma(9);
	c->setConsitution(3);

	return 0;
}