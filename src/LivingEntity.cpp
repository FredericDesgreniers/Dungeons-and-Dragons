#include "LivingEntity.h"
#include "GUI/Components/CharacterComponent.h"
#include "GUI/Screens/ScreenCharacterSelect.h"
#include "GUI/Screens/ScreenLoot.h"


LivingEntity::LivingEntity(char c):
	LivingEntity(c, Dice::rollStat(), Dice::rollStat(), Dice::rollStat(), Dice::rollStat(), Dice::rollStat(), Dice::rollStat(), 1)
{
}

LivingEntity::LivingEntity(char c, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int level) :
	LivingEntity(c, strength, dexterity, constitution, intelligence, wisdom, charisma, level, "Defaultname")

{
}

LivingEntity::LivingEntity(char c, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int level, std::string cname) :
	Entity(c), level(level), name(cname), attackBonus(level), damageBonus(0)
{
	effectiveAbilityScores[0] = abilityscores[0] = strength;
	effectiveAbilityScores[1] = abilityscores[1] = dexterity;
	effectiveAbilityScores[2] = abilityscores[2] = constitution;
	effectiveAbilityScores[3] = abilityscores[3] = intelligence;
	effectiveAbilityScores[4] = abilityscores[4] = wisdom;
	effectiveAbilityScores[5] = abilityscores[5] = charisma;

	// TODO: Update HP calculation
	health = maxHealth = level*Dice::roll("1d10") + getModifier(2);
	for (int i = 0; i < 7; i++) {
		equipped[i] = nullptr;
	}
	
	attacksRemaining = attacksPerTurn = 1 + (level / 6);
	movementRemaining = movement = 5;

	// Set save vs fortitude
	savingThrows[0] = 2 + (level / 2);
	// Set save vs reflex
	savingThrows[1] = level / 3;
	// Set save vs will
	savingThrows[2] = level / 3;

	// Instantiate backpack container;
	backpack = new ItemContainer("Backpack", 10);
	player = false;
	updateStats(); // Set secondary stats
}



	bool LivingEntity::hit(int damage)
	{
		health -= damage;
		if (health > maxHealth)
			health = maxHealth;
		if(health<0)
		{
			health = 0;
		}
		Notify();
		return health <= 0;
	}

	void LivingEntity::setName(std::string cname)
	{
		name = cname;
		Notify();
	}

	int LivingEntity::getHealth()
	{
		return health;
	}

	std::string LivingEntity::getName()
	{
		return name;
	}

	int LivingEntity::getMaxHealth()
	{
		return maxHealth;
	}

	int LivingEntity::getLevel()
	{
		return level;
	}

	int* LivingEntity::getAbilityScoreArray()
	{
		return abilityscores;
	}

	ItemContainer* LivingEntity::getBackpack() {
		return backpack;
	}

	int LivingEntity::getSavingThrow(int save)
	{
		if (save > -1 && save < 3)
		{
			return savingThrows[save];
		}
		else return 0;
		
	}


	void LivingEntity::outputEquipped()
	{
		for (int i = 0; i < 7; i++) {
			switch (i) {
			case 0:
				std::cout << "Helmet: ";
				break;
			case 1:
				std::cout << "Armor: ";
				break;
			case 2:
				std::cout << "Shield: ";
				break;
			case 3:
				std::cout << "Ring: ";
				break;
			case 4:
				std::cout << "Belt: ";
				break;
			case 5:
				std::cout << "Boots: ";
				break;
			case 6:
				std::cout << "Weapon: ";
				break;
			default:
				break;
			}

			if (equipped[i] == nullptr) {
				std::cout << "None" << endl;
			}
			else {
				std::cout << equipped[i]->getName() << endl;
			}
		}
	}

	Item* LivingEntity::equip(Item * toEquip)
	{
		if (toEquip == nullptr) {
			std::cout << "Cannot equip: Nothing to equip";
			return false;
		}
		Item* wasEquipped = nullptr;
		switch (toEquip->getItemType()) {
		case Item::ItemType::HELMET:
			wasEquipped = unequip(0);
			equipped[0] = toEquip;
			break;
		case Item::ItemType::ARMOR:
			wasEquipped = unequip(1);
			equipped[1] = toEquip;
			break;
		case Item::ItemType::SHIELD:
			wasEquipped = unequip(2);
			equipped[2] = toEquip;
			break;
		case Item::ItemType::RING:
			wasEquipped = unequip(3);
			equipped[3] = toEquip;
			break;
		case Item::ItemType::BELT:
			wasEquipped = unequip(4);
			equipped[4] = toEquip;
			break;
		case Item::ItemType::BOOTS:
			wasEquipped = unequip(5);
			equipped[5] = toEquip;
			break;
		case Item::ItemType::WEAPON:
			wasEquipped = unequip(6);
			equipped[6] = toEquip;
			break;
		default:
			break;
		}
		std::cout << "Equipped " << toEquip->getName() << endl;
		updateStats();
		Notify();
		return wasEquipped;
	}

	Item* LivingEntity::unequip(int itemSlot)
	{
		if (equipped[itemSlot] == nullptr) {
			return nullptr;
		}
		Item* removed = equipped[itemSlot];
		equipped[itemSlot] = nullptr;
		updateStats();
		Notify();
		return removed;
	}

	void LivingEntity::updateStats()
	{
		// Set effective ability scores to base ability scores
		for (int i = 0; i < 7; i++) {
			effectiveAbilityScores[i] = abilityscores[i];
		}
		// Set base armor class and add dexterity modifier
		armorClass = 10 + getModifier(1);

		// Set attack bonus based on level
		attackBonus = level;

		// Add item bonuses to effective ability scores
		for (int i = 0; i < 7; i++) {
			if (equipped[i] != nullptr) {
				switch (i) {
				case 0: // Item is helmet
					// Add int bonus
					effectiveAbilityScores[3] += equipped[i]->getIntBoost();
					// Add wis bonus
					effectiveAbilityScores[4] += equipped[i]->getWisBoost();
					// Add Armor bonus
					armorClass += equipped[i]->getArmBoost();
					break;
				case 1: //Item is Armor
					//Add Armor Bonus
					armorClass += equipped[i]->getArmBoost();
					break;
				case 2: // Item is Shield 
					//Add Shield bonus
					armorClass += equipped[i]->getArmBoost();
				case 3: // Item is Ring
					//Add STR bonus
					effectiveAbilityScores[0] += equipped[i]->getStrBoost();
					//Add CON bonus
					effectiveAbilityScores[2] += equipped[i]->getConBoost();
					// Add WIS bonus
					effectiveAbilityScores[4] += equipped[i]->getWisBoost();
					//Add CHA bonus
					effectiveAbilityScores[5] += equipped[i]->getChaBoost();
					//Add Armor Bonus
					armorClass += equipped[i]->getArmBoost();
					break;
				case 4: // Item is belt
					// Add CON bonus
					effectiveAbilityScores[2] += equipped[i]->getConBoost();
					// Add STR bonus
					effectiveAbilityScores[0] += equipped[i]->getStrBoost();
					break;
				case 5: // Item is boots
					// Add DEX bonus
					effectiveAbilityScores[1] += equipped[i]->getDexBoost();
					// Add Armor Bonus
					armorClass += equipped[i]->getArmBoost();
					break;
				case 6: //Item is Weapon
					// Add damage
					//TODO: Figure out damage + boost (4d6 etc)
					// Add damage bonus
					damageBonus += equipped[i]->getDmgBoost();
					// Add attack bonus
					attackBonus += equipped[i]->getAtkBoost();
				default:
					break;
					
				}
				
			}

		}


		return;
	}
	int LivingEntity::getInitiative()
	{
		return initiative;
	}


	bool LivingEntity::copyStats(LivingEntity * from)
	{
		
		
		int* toCopy = from->getAbilityScoreArray();
		
		// Copy ability scores
		for (int i = 0; i < 6; i++) {
			abilityscores[i] = toCopy[i];
		}
				
		level = from->getLevel();
		name = from->getName();
		health=maxHealth=from->getMaxHealth();
		Item** toEquip = from->getEquippedItems();
		for (int i = 0; i < 7; i++) {
			if (toEquip[i]!=nullptr)
			equip(new Item(toEquip[i]));
		}
		Item* toBackpack = nullptr;
		for (int i = 0; i < 10; i++) {
			backpack->removeItemAtIndex(i);
			toBackpack = from->getBackpack()->getItemAtIndex(i);
			if (toBackpack != nullptr) {
				backpack->addItem(new Item(toBackpack));
			}

		}
		updateStats();
		// Test item
		//to->equip(new Item("Helmetfury, Blessed Hat of the Windseeker", Item::ItemType::HELMET, 0, 0, 0, 5, 5, 0, 0, 0, 5)); 
		return true;
	}

	void LivingEntity::equipBasic() {
		std::cout << "Adding basic equipment:" << endl;
		equipped[0]=new Item("CrudeHelmet", Item::ItemType::HELMET, 0, 0, 0, 0, 0, 0, 0, 0, 1);
		equipped[1]=new Item("LeatherArmor", Item::ItemType::ARMOR, 0, 0, 0, 0, 0, 0, 0, 0, 1);
		equipped[2]=new Item("WoodenBuckler", Item::ItemType::SHIELD, 0, 0, 0, 0, 0, 0, 0, 0, 1);
		equipped[5]=new Item("LeatherBoots", Item::ItemType::BOOTS, 0, 0, 0, 0, 0, 0, 0, 0, 1);
		equipped[6]=new Item("Dagger", Item::ItemType::WEAPON, 0, 0, 0, 0, 0, 0, 1, 0, 0);
		updateStats();
	}

	int LivingEntity::getStrength()
	{
		return abilityscores[0];
	}


	int LivingEntity::getDexterity()
	{
		return abilityscores[1];
	}

	int LivingEntity::getConstitution()
	{
		return abilityscores[2];
	}

	int LivingEntity::getIntelligence()
	{
		return abilityscores[3];
	}

	int LivingEntity::getWisdom()
	{
		return abilityscores[4];
	}

	int LivingEntity::getCharisma()
	{
		return abilityscores[5];
	}

	int LivingEntity::getAttackBonus() {
		return attackBonus;
	}



	int LivingEntity::getArmorClass() {
		return armorClass;
	}

	int LivingEntity::getAttacksPerTurn() {
		return attacksPerTurn;
	}

	void LivingEntity::setLevel(int value)
	{
		level = value;
		updateStats();
		Notify();
	}


	void LivingEntity::setStrength(int value)
	{
		abilityscores[0] = value;
		Notify();
	}


	void LivingEntity::setDexterity(int value)
	{
		abilityscores[1] = value;
		Notify();
	}

	void LivingEntity::setConstitution(int value)
	{
		abilityscores[2] = value;
		Notify();
	}

	void LivingEntity::setIntelligence(int value)
	{
		abilityscores[3] = value;
		Notify();
	}

	void LivingEntity::setWisdom(int value)
	{
		abilityscores[4] = value;
		Notify();
	}

	void LivingEntity::setMaxHealth(int value)
	{
		health = maxHealth = value;
		Notify();
	}

	void LivingEntity::setHealth(int value)
	{
		health = value;
		Notify();
	}

	void LivingEntity::setCharisma(int value)
	{
		abilityscores[5] = value;
		Notify();
	}

	void LivingEntity::setPlayer(bool value)
	{
		player = value;
	}

	int * LivingEntity::getEffectiveAbilityScoreArray()
	{
		return effectiveAbilityScores;
	}

	Item** LivingEntity::getEquippedItems()
	{
		return equipped;
	}

	LivingEntity::~LivingEntity()
	{
		for (int i = 0; i < 7; i++) {
			delete equipped[i];
		}
		delete backpack;
		backpack = nullptr;
	}


	int LivingEntity::getModifier(int score)
	{
		switch (score) {
		case 0:
			return (getStrength() - 10) / 2;
		case 1:
			return (getDexterity() - 10) / 2;
		case 2:
			return (getConstitution() - 10) / 2;
		case 3:
			return (getIntelligence() - 10) / 2;
		case 4:
			return (getWisdom() - 10) / 2;
		case 5:
			return (getCharisma() - 10) / 2;
		}
		return 0;
	}

	void LivingEntity::levelUp() {
		// Roll for health increase
		maxHealth += Dice::roll("1d10") + getModifier(2);
		// Setlevel calls updateStats which will update attacks per turn, saving throws, etc
		setLevel(level + 1);

		attacksRemaining = attacksPerTurn = 1 + (level / 6);

		// Set save vs fortitude
		savingThrows[0] = 2 + (level / 2);
		// Set save vs reflex
		savingThrows[1] = level / 3;
		// Set save vs will
		savingThrows[2] = level / 3;
	}

	int LivingEntity::rollInitiative() {
		initiative = Dice::roll("1d20") + getModifier(1);
		return initiative;
	}

	int LivingEntity::rollDamage() {
		// TODO: Damage bonus should depend on weapon type
		return Dice::roll("1d8") + getModifier(0);
	}

	int LivingEntity::rollAttack() {
		int result = Dice::roll("1d20") + (attackBonus - 5 * (attacksPerTurn-attacksRemaining));
		attacksRemaining--;
		return result;
	}

	void LivingEntity::resetTurn() {
		attacksRemaining = attacksPerTurn;
		movementRemaining = movement;
	}

	int LivingEntity::getAttacksRemaining() {
		return attacksRemaining;
	}

	int LivingEntity::getMovementRemaining() {
		return movementRemaining;
	}

	int LivingEntity::getMovement() {
		return movement;
	}

	void LivingEntity::setMovementRemaining(int value) {
	 movementRemaining = value;
	}

	void LivingEntity::setMovement(int value) {
		movement = value;
	}

	bool LivingEntity::getTurnFinished()
	{
		return turnFinished;
	}

	void LivingEntity::setTurnFinished(bool tf)
	{
		turnFinished = tf;
	}

	void LivingEntity::doStrategy(Map* map)
	{
		if (strategy == nullptr)
			strategy = new Strategy();

		strategy->doStrategy(map, this);
	}

void LivingEntity::setStrategy(Strategy* strategy)
{
	this->strategy = strategy;
}

bool LivingEntity::getHostile()
{
	return hostile;
}
void LivingEntity::setHostile(bool hostile)
{
	this->hostile = hostile;
}
bool LivingEntity::isPlayer()
{
	return player;
}
bool LivingEntity::interact(Map* map, Entity* entity)
{
	if(this->attacksRemaining>0)
	if (LivingEntity* le = dynamic_cast<LivingEntity*>(entity))
	{
		if (le->hit(getStrength() * 2))
		{
			if(player)
			{
				Game* game = Game::getInstance();
				
				for (int i = Item::ItemType::HELMET; i <= Item::ItemType::WEAPON; i++)
				{
					Item* item = le->getEquippedItems()[i];
					if(item!=nullptr)
					{
						le->getBackpack()->addItem(item);
					}
				}

				ScreenLoot* lootScreen = new ScreenLoot(game, this->getBackpack(), le->getBackpack());
				lootScreen->setBackButton(game->getGuiManager()->setScreen(lootScreen));
			}
		}
		attacksRemaining--;
		return true;
	}
	return false;
}

void LivingEntity::reset() {
	attacksRemaining = attacksPerTurn;
	movementRemaining = movement;
	health = maxHealth;
}

LivingEntity* LivingEntity::loadLivingEntity(std::string name) {
	LivingEntity* loadedCharacter;
	std::fstream charFile("characters/" + name + ".chr");
	if (charFile.is_open()) {
		int abilities[6] = { 0,0,0,0,0,0 };
		int loadLevel = 1;
		int loadHitPoints = 1;
		std::string equipped[7] = { "","","","","","","" };
		std::string backpack[10] = { "","","","","","","","","","" };
		std::string line = "";
		std::getline(charFile, line);
		loadLevel = stoi(line);
		std::getline(charFile, line);
		loadHitPoints = stoi(line);
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
		// Instantiate character with loaded ability scores, level, and name
		loadedCharacter = new LivingEntity('c', abilities[0], abilities[1], abilities[2], abilities[3], abilities[4], abilities[5], loadLevel, name);
		loadedCharacter->setMaxHealth(loadHitPoints); // Set max HP to loaded value

													  //
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
		loadedCharacter = new LivingEntity(1);
	}
	return loadedCharacter;
}

bool LivingEntity::saveLivingEntity() {
	std::fstream charFile;
	charFile.open("characters/" + name + ".chr", std::ios::out);
	if (charFile.is_open()) {
		charFile << getLevel() << endl;;
		charFile << getMaxHealth() << endl;;
		int *abilities = (getAbilityScoreArray());
		for (int i = 0; i < 6; i++) {
			charFile << abilities[i] << endl;
		}
		charFile.flush();
		Item **equipped = (getEquippedItems());
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

		ItemContainer* backpack = (getBackpack());
		Item* item;
		for (int i = 0; i < 10; i++) {
			item = backpack->getItemAtIndex(i);
			if (item != nullptr) {
				Item::saveItem(item->getName(), item);
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

void LivingEntity::resetAttacks()
{
	attacksRemaining = attacksPerTurn;
}
