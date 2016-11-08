#include "ItemContainer.h"

//! Constuctor
ItemContainer::ItemContainer()
{
	this->name = "Default Container";
}

ItemContainer::ItemContainer(std::string name, int max)
{
	this->name = name;
	this->maxSize = max;
	arrayPtr = new Item *[maxSize];
}

//! Destructor
ItemContainer::~ItemContainer()
{

}

// returns an Item at index i
Item* ItemContainer::getItemAtIndex(int i)
{
	if (i < maxSize)
	{
		return arrayPtr[i];
	}
	else 
	{
		std::cout << "No items here, limited size." << std::endl;
		return nullptr;
	}
}

// adds an Item to the end of the container
void ItemContainer::addItem(Item* it)
{
	for (int i = 0; i < maxSize; i++)
	{
		if (arrayPtr[i] == nullptr)
		{
			arrayPtr[i] = it;
			break;
		}
	}
}

// removes an Item at index i from the container
void ItemContainer::removeItemAtIndex(int i)
{
	if (arrayPtr[i] != nullptr)
	{
		arrayPtr[i] == nullptr;
	}


}

// adds an item at index i to the container
void ItemContainer::addItemAtIndex(Item* it, int i)
{
	if (arrayPtr[i] == nullptr)
	{
		arrayPtr[i] = it;
	}
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
	return maxSize;
}


// prints every items in the container
void ItemContainer::printContainer()
{
	for (int i = 0; i < maxSize; ++i)
	{
		std::cout << arrayPtr[i]->toString() << std::endl;
	}
}

// Example code for Container creation

	//ItemContainer* i = new ItemContainer("Test", 10);

	//Item* it = new Item("Hi", Item::HELMET, 1, 2, 2, 3, 3, 2, 1, 2, 3);
	//Item* it2 = new Item("someSword", Item::WEAPON, 1, 2, 3, 4, 5, 4, 5, 3, 2);
	//Item* it3 = new Item();
	//Item* it4 = new Item();

	//Item* insert = new Item("WWWWWWWWW", Item::ARMOR, 1, 1, 1, 1, 1, 1, 1, 1, 1);
	//// adds an item to the container
	////i->addItem(it);
	////i->addItem(it2);
	////i->addItem(it3);
	////i->addItem(it4);
	////i->addItemAtIndex(insert, 4);
	////i->removeItemAtIndex(1);

	//i->printContainer();


