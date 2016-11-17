#include "character.h"

Character::Character(int level) :LivingEntity('C')
{
	setLevel(level);
	equipBasic();
}

Character::Character(int str, int dex, int cons, int intel, int wisd, int chari, int lvl) : LivingEntity('C', str, dex, cons, intel, wisd, chari, lvl)
{
}

Character::Character(int str, int dex, int cons, int intel, int wisd, int chari, int lvl, std::string cname) : LivingEntity('C', str, dex, cons, intel, wisd, chari, lvl, cname)
{

}


Character* Character::loadCharacter(std::string name) {
	Character* loadedCharacter;
	std::fstream charFile("characters/" + name + ".chr");
	if (charFile.is_open()) {
		int abilities[6] = { 0,0,0,0,0,0 };
		int loadLevel = 1;
		std::string equipped[7] = { "","","","","","","" };
		std::string backpack[10] = { "","","","","","","","","","" };
		std::string line = "";
		std::getline(charFile, line);
		loadLevel = stoi(line);
		for (int i = 0; i < 6; i++)
		{
			std::getline(charFile, line);
			abilities[i] = stoi(line);
		}
		for (int i = 0; i < 7; i++) {
			std::getline(charFile, line);
			equipped[i] = line;
		}
		for (int i = 0; i < 10; i++) {
			std::getline(charFile, line);
			backpack[i] = line;
		}

		loadedCharacter = new Character(abilities[0], abilities[1], abilities[2], abilities[3], abilities[4], abilities[5], loadLevel, name);
		Item* loadedItem;
		for (int i = 0; i < 7; i++) {
			if (equipped[i] != "None") {
				loadedItem = Item::loadItem(equipped[i]);
				if (loadedItem != nullptr) {
					loadedCharacter->equip(loadedItem);
				}
			}
		}

		for (int i = 0; i < 10; i++) {
			if (backpack[i] != "None") {
				loadedItem = Item::loadItem(backpack[i]);
				if (loadedItem != nullptr) {
					loadedCharacter->getBackpack()->addItem(loadedItem);
				}
			}
		}
		//character->getBackpack()->addItem(new Item("Stale Bread", Item::ItemType::BELT, 0, 0, 0, 0, 0, 0, 0, 0, 0));

		std::cout << "Successfully loaded character from " << name << ".chr" << endl;
		std::cout << loadedCharacter->toString() << endl;

	}
	else {
		std::cout << "Unable to read character file, returning random level 1 character" << endl;
		loadedCharacter = new Character(1);
	}
	return loadedCharacter;
}

bool Character::saveCharacter(std::string name, Character* character) {
	std::fstream charFile;
	charFile.open("characters/" + name + ".chr", std::ios::out);
	if (charFile.is_open()) {
		charFile << character->getLevel() << endl;;
		int *abilities = (character->getAbilityScoreArray());
		for (int i = 0; i < 6; i++) {
			charFile << abilities[i] << endl;
		}
		charFile.flush();
		Item **equipped = (character->getEquippedItems());
		for (int i = 0; i < 7; i++) {
			if (equipped[i] != nullptr) {
				Item::saveItem(equipped[i]->getName(), equipped[i]);
				charFile << equipped[i]->getName() << endl;
			}
			else {
				charFile << "None" << endl;
			}
		}
		charFile.flush();

		ItemContainer* backpack = (character->getBackpack());
		Item* item;
		for (int i = 0; i < 10; i++) {
			item = backpack->getItemAtIndex(i);
			if (item != nullptr) {
				Item::saveItem(item->getName(),item);
				charFile << item->getName() << endl;
			}
			else {
				charFile << "None" << endl;
			}
		}

		charFile.flush();
		charFile.close();
	}
	else {
		std::cout << "Unable to open file for writing" << endl;
		return false;
	}
	std::cout << "Character saved to " + name + ".chr" << endl;
	return true;
}


bool Character::validateNewCharacter()
{
	
	int* abilities = getAbilityScoreArray();
	for (int i = 0; i < 7; i++){
		if (abilities[i] < 3 || abilities[i] > 18)
			return false;

	}
	return true;
}




