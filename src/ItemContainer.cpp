#include "ItemContainer.h"

//! Constuctor
ItemContainer::ItemContainer()
{
	this->name = "Default Container";
}

ItemContainer::ItemContainer(std::string name)
{
	this->name = name;
}

//! Destructor
ItemContainer::~ItemContainer()
{

}

// returns an Item at index i
Item ItemContainer::getItemAtIndex(int i)
{
	return container[i];
}

// adds an Item to the end of the container
void ItemContainer::addItem(Item& it)
{
	container.push_back(it);
}

// removes an Item at index i from the container
void ItemContainer::removeItemAtIndex(int i) 
{
	container.erase(container.begin() + i);
}

// adds an item at index i to the container
void ItemContainer::addItemAtIndex(Item& it, int i)
{
	container.insert(container.begin() + i, it);
}

// returns the name of the container
std::string ItemContainer::getName()
{
	return this->name;
}


void ItemContainer::setName(std::string s)
{
	name = s;
}

// returns size of container
int ItemContainer::getSize()
{
	return container.size();
}

// returns capacity of container
int ItemContainer::getCapacity()
{
	return container.capacity();
}

// prints every items in the container
void ItemContainer::printContainer()
{
	int size = container.size();

	for (int i = 0; i < size; ++i)
	{
		std::cout << container[i].toString() << std::endl;
	}
}

// Example code for Container creation

	//ItemContainer* i = new ItemContainer("Test");

	//Item* it = new Item("Hi", Item::HELMET, 1, 2, 2, 3, 3, 2, 1, 2 ,3);
	//Item* it2 = new Item("someSword", Item::WEAPON, 1, 2, 3, 4, 5, 4, 5, 3, 2);
	//Item* it3 = new Item();
	//Item* it4 = new Item();

	//Item* insert = new Item("WWWWWWWWW", Item::ARMOR, 1, 1, 1, 1, 1, 1, 1, 1, 1 );
	//// adds an item to the container
	//i->addItem(*it);
	//i->addItem(*it2);
	//i->addItem(*it3);
	//i->addItem(*it4);
	//i->addItemAtIndex(*insert, 0);
	//i->removeItemAtIndex(0);

	//i->printContainer();
