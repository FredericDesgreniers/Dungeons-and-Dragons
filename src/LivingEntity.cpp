#include "LivingEntity.h"

LivingEntity::LivingEntity(char c):
	LivingEntity(c, Dice::rollStat(), Dice::rollStat(), Dice::rollStat(), Dice::rollStat(), Dice::rollStat(), Dice::rollStat(), 1)
{
}

LivingEntity::LivingEntity(char c, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int level) :
	LivingEntity(c, strength, dexterity, constitution, intelligence, wisdom, charisma, level, "Defaultname")

{
}

LivingEntity::LivingEntity(char c, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int level, std::string cname) :
	Entity(c), level(level), name(cname)
{
	effectiveAbilityScores[0] = abilityscores[0] = strength;
	effectiveAbilityScores[1] = abilityscores[1] = dexterity;
	effectiveAbilityScores[2] = abilityscores[2] = constitution;
	effectiveAbilityScores[3] = abilityscores[3] = intelligence;
	effectiveAbilityScores[4] = abilityscores[4] = wisdom;
	effectiveAbilityScores[5] = abilityscores[5] = charisma;
	// TODO: Proper HP calculations
	health = maxHealth = 100;
	attackBonus = damageBonus = 0;
	armorClass = 10;
	for (int i = 0; i < 7; i++) {
		equipped[i] = nullptr;
	}
	backpack = new ItemContainer("Backpack", 10);
}



	bool LivingEntity::hit(int damage)
	{
		health -= damage;
		if (health > maxHealth)
			health = maxHealth;
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
		Notify();
		return removed;
	}

	bool LivingEntity::updateStats()
	{
		//TODO: Complete and test update stats method


		for (int i = 0; i < 7; i++) {
			effectiveAbilityScores[i] = abilityscores[i];
		}
		armorClass = 10;

		for (int i = 0; i < 7; i++) {
			if (equipped[i] != nullptr) {
				switch (i) {
				case 0: // Item is helmet
					// Add int bonus
					effectiveAbilityScores[3] += equipped[i]->getIntBoost();
					// Add wis bonus
					effectiveAbilityScores[4] += equipped[i]->getWisBoost();
					// Add AC bonus 
					armorClass += equipped[i]->getArmBoost();
					break;
				case 1: //Item is Armor
					//Add AC bonus
					armorClass += equipped[i]->getArmBoost();
					break;
				case 2: // Item is Shield 
					//Add AC bonus
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
					//Add AC bonus
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
					// Add AC bonus
					armorClass += equipped[i]->getArmBoost();
					break;
				case 6: //Item is Weapon
					// Add damage
					//TODO: Figure out damage + boost (4d6 etc)
					// Add damage bonus
					damageBonus = equipped[i]->getDmgBoost();
					// Add attack bonus
					attackBonus = equipped[i]->getAtkBoost();
				default:
					break;
					
				}
				
			}

		}


		return false;
	}

	bool LivingEntity::copyStats(LivingEntity * from, LivingEntity * to)
	{
		if (from == nullptr || to == nullptr) {
			return false;
		}
		to->setStrength(from->getStrength());
		to->setDexterity(from->getDexterity());
		to->setConstitution(from->getConstitution());
		to->setIntelligence(from->getIntelligence());
		to->setWisdom(from->getWisdom());
		to->setCharisma(from->getCharisma());
		to->setLevel(from->getLevel());
		to->setName(from->getName());
		Item** toCopy = from->getEquippedItems();
		for (int i = 0; i < 7; i++) {
			if (toCopy[i]!=nullptr)
			to->equip(new Item(toCopy[i]));
		}
		// Test item
		//to->equip(new Item("Helmetfury, Blessed Hat of the Windseeker", Item::ItemType::HELMET, 0, 0, 0, 5, 5, 0, 0, 0, 5)); 
		return true;
	}

	void LivingEntity::equipBasic() {
		std::cout << "Adding basic equipment:" << endl;
		equip(new Item("Crude Helmet", Item::ItemType::HELMET, 0, 0, 0, 0, 0, 0, 0, 0, 1));
		equip(new Item("Leather Armor", Item::ItemType::ARMOR, 0, 0, 0, 0, 0, 0, 0, 0, 1));
		equip(new Item("Wooden Buckler", Item::ItemType::SHIELD, 0, 0, 0, 0, 0, 0, 0, 0, 1));
		equip(new Item("Leather Boots", Item::ItemType::BOOTS, 0, 0, 0, 0, 0, 0, 0, 0, 1));
		equip(new Item("Dagger", Item::ItemType::WEAPON, 0, 0, 0, 0, 0, 0, 1, 0, 0));
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

	void LivingEntity::setLevel(int value)
	{
		level = value;
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

	void LivingEntity::setCharisma(int value)
	{
		abilityscores[5] = value;
		Notify();
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
		delete backpack;
		backpack = nullptr;
	}
