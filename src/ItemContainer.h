#pragma once
#include <vector>
#include "Item.h"


class ItemContainer
{
public:
	ItemContainer();
	ItemContainer(std::string name, bool restricted);
	~ItemContainer();

	Item getItemAtIndex(int i);
	void removeItemAtIndex(int i);
	void addItemAtIndex(int i);

	std::string getName();
	void setName(std::string s);


	
private:
	std::vector<Item> container;
	std::string name;
	bool restricted;
};