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
}

//! Destructor
ItemContainer::~ItemContainer()
{

}

// returns an Item at index i
Item* ItemContainer::getItemAtIndex(int i)
{
	if (i <= (maxSize - 1))
	{
		return container[i];
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
	if(container.size() < maxSize )
	{
		container.push_back(it);
	}
	else
	{
		std::cout << "Cannot add an item here, no more space" << std::endl;
	}
}

// removes an Item at index i from the container
void ItemContainer::removeItemAtIndex(int i) 
{
	delete container[i];
	container[i] = nullptr;

}

// adds an item at index i to the container
void ItemContainer::addItemAtIndex(Item* it, int i)
{
	if (i <= (maxSize - 1))
	{
		container.insert(container.begin() + i, it);
	}
	else
	{
		std::cout << "Cannot add an item here." << std::endl;
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
		std::cout << container[i]->toString() << std::endl;
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
	//i->addItem(it);
	//i->addItem(it2);
	//i->addItem(it3);
	//i->addItem(it4);
	//i->addItemAtIndex(insert, 4);
	////i->removeItemAtIndex(1);
	//// removeItem doesnt work

	//i->printContainer();


