//! @file 
//! @brief Implementation file for NimbleBuilder class

#include "NimbleBuilder.h"


void NimbleBuilder::buildAbilityScores() {
	// Roll 6 ability scores. See Dice::rollStat for rolling details. 
	int abilityScores[6] = { Dice::rollStat(),Dice::rollStat() ,Dice::rollStat() ,Dice::rollStat(),Dice::rollStat() ,Dice::rollStat() };
	// Sort the resulting values in ascending order. 
	sort(abilityScores, abilityScores + 6);
	// Assign ability scores based on nimble fighter priority
	m_livingEntity->setDexterity(abilityScores[5]); // Assign the highest score to dexterity
	m_livingEntity->setConstitution(abilityScores[4]); // Assign the 2nd highest score to constitution
	m_livingEntity->setStrength(abilityScores[3]); // Assign the 3rd highest score to strength
	m_livingEntity->setIntelligence(abilityScores[2]); // Assign the 4th highest score to intelligence
	m_livingEntity->setCharisma(abilityScores[1]); // Assign the 5th highest score to charisma
	m_livingEntity->setWisdom(abilityScores[0]); // Assign the 6th highest score to wisdom
	int maxHealth = 0;
	for (int i = 0; i < level; i++) {
		maxHealth += (Dice::roll("1d10") + m_livingEntity->getModifier(2));
	}
	m_livingEntity->setMaxHealth(maxHealth);
	m_livingEntity->setLevel(level);

}

void NimbleBuilder::buildEquipped() {
	// Equip basic items
	m_livingEntity->equipBasic();
	// Equip short sword
	delete(m_livingEntity->equip(new Item("Short Sword", Item::ItemType::WEAPON, 0, 0, 0, 0, 0, 0, 0, 0, 0)));
	// TODO (Beyond the scope of this assignment) Equip  nimble specific armor. Added for potential use in project
}

void NimbleBuilder::buildName()
{
	m_livingEntity->setName("Nimble Fighter");
}