#include "ItemContainer.h"

//! Constuctor
ItemContainer::ItemContainer()
{
	this->name = "Default Container";
	this->restricted = false;
}

ItemContainer::ItemContainer(std::string name, bool restriction)
{
	this->name = name;
	this->restricted = restriction;
}

//! Destructor
ItemContainer::~ItemContainer()
{

}

Item ItemContainer::getItemAtIndex(int i)
{
	return container[i];
}

std::string ItemContainer::getName()
{
	return this->name;
}

void ItemContainer::setName(std::string s)
{
	this->name = s;
}