#pragma once

#include "Screen.h"
#include "ScreenMain.h"
#include "../../Item.h"
#include "../Components/TextField.h"
#include "../Renderer.h"
#include "../../Observer.h"



/**
 * Class used to display the item creation gui
 */
class ScreenItemCreation : public Screen, public Observer
{
private:

	Item* it;
	TextField* itemName;
	std::string abilityScores[9];
	std::string type;
	int typeCounter;
public:

	/**
	*Constructor
	*/
	ScreenItemCreation(Game* game);

	/**
	*Destructor
	*/
	~ScreenItemCreation();

	/**
	*Renders strings to the screen
	*/
	void render() override;

	/**
	*Sets the type of the item to a passed string
	*/
	void setType(std::string value);

	/**
	*Sets the strength boost to a passed string
	*/
	void setStrength(std::string value);

	/**
	*Sets the constitution boost to a passed string
	*/
	void setConstitution(std::string value);

	/**
	*Sets the dexterity boost to a passed string
	*/
	void setDexterity(std::string value);

	/**
	*Sets the intelligence boost to a passed string
	*/
	void setIntelligence(std::string value);

	/**
	*Sets the wisdom boost to a passed string
	*/
	void setWisdom(std::string value);

	/**
	*Sets the charisma boost to a passed string
	*/
	void setCharisma(std::string value);

	/**
	*Sets the attack boost to a passed string
	*/
	void setAttack(std::string value);

	/**
	*Sets the damage boost to a passed string
	*/
	void setDamage(std::string value);

	/**
	*Sets the armor boost to a passed string
	*/
	void setArmor(std::string value);

	/**
	*Increments an item boost by 1
	*/
	void increment(int stat);

	/**
	*Decrements an item boost by 1
	*/
	void decrement(int stat);

	/**
	*Changes the type of item displayed on the screen
	*/
	void changeType(int stat);

	/**
	*Saves the item to a file
	*/
	void createItem();

	/**
	*Update function used in observer design pattern
	*/
	void Update();

};