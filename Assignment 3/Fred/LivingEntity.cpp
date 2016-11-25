#include "LivingEntity.h"
#include <iostream>

LivingEntity::LivingEntity(char c):
	LivingEntity(c, 10,10,10,10,10,10, 1)
{
}
LivingEntity::LivingEntity(char c, Strategy* strategy):LivingEntity(c) 
{
	this->strategy = strategy;
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
	health = maxHealth = level*10 + getModifier(2);

	updateStats(); // Set secondary stats
}

void LivingEntity::doStrategy(Map* map)
{
	if(strategy != nullptr)
		strategy->doStrategy(map, this);
}

void LivingEntity::setStrategy(Strategy* strategy)
{
	this->strategy = strategy;
}

LivingEntity::~LivingEntity()
{
	
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

		return health <= 0;
	}

	void LivingEntity::setName(std::string cname)
	{
		name = cname;

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



	int LivingEntity::getSavingThrow(int save)
	{
		if (save > -1 && save < 3)
		{
			return savingThrows[save];
		}
		else return 0;
		
	}
	


	void LivingEntity::updateStats()
	{
		// Set effective ability scores to base ability scores
		for (int i = 0; i < 7; i++) {
			effectiveAbilityScores[i] = abilityscores[i];
		}
		// Set base armor class and add dexterity modifier
		armorClass = 10 + getModifier(1);

		// Set attacks per turn and attack bonus based on level
		attacksRemaining = attacksPerTurn = 1 + (level / 6);
		attackBonus = level;
		
		// Set save vs fortitude
		savingThrows[0] = 2 + (level / 2);
		// Set save vs reflex
		savingThrows[1] = level / 3;
		// Set save vs will
		savingThrows[2] = level / 3;

		// Add item bonuses to effective ability scores
		


		return;
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
		
		updateStats();
		// Test item
		//to->equip(new Item("Helmetfury, Blessed Hat of the Windseeker", Item::ItemType::HELMET, 0, 0, 0, 5, 5, 0, 0, 0, 5)); 
		return true;
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

	int LivingEntity::getAttacksPerTurn() {
		return attacksPerTurn;
	}

	void LivingEntity::setLevel(int value)
	{
		level = value;
		updateStats();
	}


	void LivingEntity::setStrength(int value)
	{
		abilityscores[0] = value;
	}


	void LivingEntity::setDexterity(int value)
	{
		abilityscores[1] = value;
	}

	void LivingEntity::setConstitution(int value)
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

	void LivingEntity::setMaxHealth(int value)
	{
		maxHealth = value;
	}

	void LivingEntity::setHealth(int value)
	{
		health = value;
	}

	void LivingEntity::setCharisma(int value)
	{
		abilityscores[5] = value;
	}

	int * LivingEntity::getEffectiveAbilityScoreArray()
	{
		return effectiveAbilityScores;
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
		maxHealth += 10 + getModifier(2);
		// Setlevel calls updateStats which will update attacks per turn, saving throws, etc
		setLevel(level + 1);
	}

	int LivingEntity::rollInitiative() {
		return 20 + getModifier(1);
	}

	int LivingEntity::rollDamage() {
		// TODO: Damage bonus should depend on weapon type
		return 8 + getModifier(0);
	}

	int LivingEntity::rollAttack() {
		int result = 20 + (attackBonus - 5 * (attacksPerTurn-attacksRemaining));
		attacksRemaining--;
		return result;
	}

	void LivingEntity::resetAttacks() {
		attacksRemaining = attacksPerTurn;
	}

	int LivingEntity::getAttacksRemaining() {
		return attacksRemaining;
	}
