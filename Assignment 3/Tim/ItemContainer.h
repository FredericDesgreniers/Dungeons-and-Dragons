//! @file 
//! @brief Header file for ItemContainer class
#pragma once
#include <vector>
#include "Item.h"

/**
 * Container that contains a series of items
 */
class ItemContainer //:public Subject
{
public:
	/**
	 * Default constructor
	 */
	ItemContainer();
	/**
	 * Constructor given a name and a max item limit
	 */
	ItemContainer(std::string name, int max);
	~ItemContainer();
	/**
	 * Get the item at index i, returns nullptr if none
	 */
	Item* getItemAtIndex(int i);
	/**
	 * Remove item at index is
	 */
	void removeItemAtIndex(int i);
	/**
	 * Add item at index i
	 */
	void addItemAtIndex(Item* it, int i);
	/**
	 * Add item at the first availlable spot
	 */
	void addItem(Item* it);
	/**
	 * Print container
	 */
	void printContainer();
	/**
	 * Returns the name of the container
	 */
	std::string getName();
	/**
	 * Set the name of the container
	 */
	void setName(std::string s);
	/**
	 * return the max size of the container
	 */
	int getSize();



	
private:

	Item **arrayPtr;
	std::string name;
	int maxSize;
};