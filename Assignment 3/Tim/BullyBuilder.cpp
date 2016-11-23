//! @file 
//! @brief Implementation file for BullyBuilder class
#include "BullyBuilder.h"


void BullyBuilder::buildAbilityScores() {
	// Roll 6 ability scores. See Dice::rollStat for rolling details.
	int abilityScores[6] = { Dice::rollStat(),Dice::rollStat() ,Dice::rollStat() ,Dice::rollStat(),Dice::rollStat() ,Dice::rollStat() };
	// Sort the resulting values in ascending order.
	sort(abilityScores, abilityScores + 6);
	// Assign ability scores based on bully fighter priority
	m_livingEntity->setStrength(abilityScores[5]); // Assign the highest score to strength
	m_livingEntity->setConstitution(abilityScores[4]); // Assign the 2nd highest score to constitution
	m_livingEntity->setDexterity(abilityScores[3]); // Assign the 3rd highest score to dexterity
	m_livingEntity->setIntelligence(abilityScores[2]); // Assign the 4th highest score to intelligence
	m_livingEntity->setCharisma(abilityScores[1]); // Assign the 5th highest score to charisma
	m_livingEntity->setWisdom(abilityScores[0]); // Assign the 6th highest score to wisdom
	// The rationale for rolling the health for the specified level in this class rather than simply using the levelUp function
	// on the character
	int maxHealth = 0;
	for (int i = 0; i < level; i++) {
		maxHealth += (Dice::roll("1d10") + m_livingEntity->getModifier(2));
	}
	m_livingEntity->setMaxHealth(maxHealth);// Set max health to rolled value
	m_livingEntity->setLevel(level);
}

void BullyBuilder::buildEquipped() {
	// Equip basic items
	m_livingEntity->equipBasic();
	delete(m_livingEntity->equip(new Item("Longsword", Item::ItemType::WEAPON, 0, 0, 0, 0, 0, 0, 0, 0, 0)));
	// TODO (Beyond the scope of this assignment) Equip bully-specific armor. Added for potential use in project
}

void BullyBuilder::buildName()
{
	m_livingEntity->setName("Bully Fighter");
}