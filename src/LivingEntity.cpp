#include "LivingEntity.h"

LivingEntity::LivingEntity(char c):Entity(c)
{
	abilityscores[0] = Dice::rollStat();
	abilityscores[1] = Dice::rollStat();
	abilityscores[2] = Dice::rollStat();
	abilityscores[3] = Dice::rollStat();
	abilityscores[4] = Dice::rollStat();
	abilityscores[5] = Dice::rollStat();
	level = 1;
	// TODO: Proper HP Calculations
	effectiveMaxHealth = health = maxHealth = 100;
	attackBonus = damageBonus = armorClass = 0;
	for (int i = 0; i < 7; i++) {
		equipped[i] = nullptr;
	}
}


LivingEntity::LivingEntity(char c, int strength, int dexterity, int constitution, int intelligence, int wisdom, int charisma, int level):Entity(c), level(level)

{
	effectiveAbilityScores[0]=abilityscores[0] = strength;
	effectiveAbilityScores[1]=abilityscores[1] = dexterity;
	effectiveAbilityScores[2]=abilityscores[2] = constitution;
	effectiveAbilityScores[3]=abilityscores[3] = intelligence;
	effectiveAbilityScores[4]=abilityscores[4] = wisdom;
	effectiveAbilityScores[5]=abilityscores[5] = charisma;
	// TODO: Proper HP calculations
	effectiveMaxHealth = health = maxHealth = 100;
	attackBonus = damageBonus = armorClass = 0;
	for (int i = 0; i < 7; i++) {
		equipped[i] = nullptr;
	}

}


bool LivingEntity::hit(int damage)
{
	health -= damage;
	if (health > maxHealth)
		health = maxHealth;
	return health <= 0;
}

int LivingEntity::getHealth()
{
	return health;
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
	if (toEquip == nullptr){
		std::cout << "Cannot equip: Nothing to equip";
		return false;
	}
	Item* wasEquipped = nullptr;
	switch (toEquip->getItemType()) {
	case Item::ItemType::HELMET:
		wasEquipped = unequip(0);
		equipped[0] = toEquip;
		//TODO: dequip previously equipped item. return pointer to it if needed?
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
	return wasEquipped;
}

Item* LivingEntity::unequip(int itemSlot)
{
	if (equipped[itemSlot] == nullptr) {
		return nullptr;
	}
	Item* removed = equipped[itemSlot];
	equipped[itemSlot] = nullptr;
	return removed;
}

bool LivingEntity::updateStats()
{
	//TODO: Complete and test update stats method


	for (int i = 0; i < 7; i++) {
		effectiveAbilityScores[i] = abilityscores[i];
	}
	effectiveMaxHealth = maxHealth;
	armorClass = 0;
	
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
			}
		}
	}

	
	return false;
}

int LivingEntity::getStrength()
{
	return abilityscores[0];
}


int LivingEntity::getDexterity()
{
	return abilityscores[1];
}

int LivingEntity::getConsitution()
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
}


void LivingEntity::setStrength(int value)
{
	abilityscores[0] = value;
}


void LivingEntity::setDexterity(int value)
{
	abilityscores[1]=value;
}

void LivingEntity::setConsitution(int value)
{
	abilityscores[2] = value;
}

void LivingEntity::setIntelligence(int value)
{
	abilityscores[3] = value;
}

void LivingEntity::setWisdom(int value)
{
	abilityscores[4] = value;
}

void LivingEntity::setCharisma(int value)
{
	abilityscores[5] = value;
}

int * LivingEntity::getEffectiveAbilityScoreArray()
{
	return effectiveAbilityScores;
}

