#pragma once
#include <vector>
#include "Item.h"


class ItemContainer
{
public:
	Item getItemAtIndex(int i);
private:
	std::vector<Item> container;

};