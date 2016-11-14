#pragma once
#include "Screen.h"
#include "screenMain.h"
#include "../../character.h"
#include <sstream>
#include "../Components/TextField.h"
#include "../Components/EquipedItemComponent.h"
#include "../Renderer.h"
#include "../../dice.h"
#include "../../Observer.h"
#include <string>

/**
* Character editor screen. Used to roll new characters or edit existing ones.
* Currently supports only the fighter class. 
*/
class ScreenCharacterCreation : public Screen, public Observer
{

private:
	/**
	* Stores string versions of ability scores of rolled/loaded characters for display
	*/
	std::string abilityScores[7];
	/**
	* Character object used for character creation. Pointer to a character object used for loading/saving characters
	* and displaying their information in the editor.
	*
	*/
	Character* character;

	/**
	* A text field for inputting character names
	*/
	TextField* nameInput;

	/**
	* An array which holds character ability score modifiers for display. Updated upon changes to character via observer
	*/
	int mods[6];

	/**
	* An array which holds character saving throws for display. Updated upon changes to character via observer
	*/
	int savingThrows[3];
	/**
	* The characters attacks per round for display
	*/
	int attacksPerTurn;

	/**
	* The character's attack bonus for display
	*/
	int attackBonus;

	

public:
	ScreenCharacterCreation(Game* game);
	void render() override;
	~ScreenCharacterCreation();

	/**
	* Change the string version of remaining ability points
	* Used for incrementing/decrementing ability scores
	*/
	void setRemaining(std::string value);

	/**
	* Increment the specified ability score.
	* STR=0, DEX=1, CON=2, INT=3, WIS=4, CHA=5, remaining=6
	*/
	void increment(int stat);
	/**
	* Decrement the specified ability score.
	* STR=0, DEX=1, CON=2, INT=3, WIS=4, CHA=5, remaining=6
	*/
	void decrement(int stat);
	/**
	* Save the rolled or loaded character to a file with the name specified in nameInput
	*/
	void saveCharacter();
	/**
	* Called when Character notifies the editor of changes. Updates display of ability scores and inventory
	*/
	void Update();
	/**
	* Load a character from file into editor. Currently loads a character named Test.chr for testing purposes,
	* but will be able to load other characters once a menu for selection is added
	*/
	void loadCharacter();

	/**
	* Roll a new level 1 character with random stats. These can be adjusted before saving
	* Clears equipped items and inventory, sets level to 1. 
	*/
	void rollCharacter();


};
