//! @file 
//! @brief Implementation file for Director class
#pragma once
#include "Director.h"


Director::Director() : Director(1) {
}

Director::Director(int lvl) {
	m_LivingEntityBuilder = nullptr;
	level = lvl;
}
void Director::setLivingEntityBuilder(LivingEntityBuilder * livingEntityBuilder)
{
	if (livingEntityBuilder != nullptr) {
		m_LivingEntityBuilder = livingEntityBuilder;
		m_LivingEntityBuilder->setLevel(level);
	}
	else
		std::cout << "Director: Set LivingEntityBuilder failed. nullptr received as argument" << endl;
}

void Director::setLevel(int lvl) {
	level = lvl;
	if (m_LivingEntityBuilder != nullptr) {
		m_LivingEntityBuilder->setLevel(lvl);
	}
}

void Director::constructLivingEntity() {
	m_LivingEntityBuilder->createNewLivingEntity();
	m_LivingEntityBuilder->buildAbilityScores();
	m_LivingEntityBuilder->buildEquipped();
	m_LivingEntityBuilder->buildName();
}