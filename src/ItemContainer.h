#pragma once
#include <vector>
#include "Item.h"


class ItemContainer
{
public:
	ItemContainer();
	ItemContainer(std::string name, int max);
	~ItemContainer();

	Item* getItemAtIndex(int i);
	void removeItemAtIndex(int i);
	void addItemAtIndex(Item* it, int i);
	void addItem(Item* it);

	void printContainer();

	std::string getName();
	void setName(std::string s);

	int getSize();



	
private:

	Item **arrayPtr;
	std::string name;
	int maxSize;
};