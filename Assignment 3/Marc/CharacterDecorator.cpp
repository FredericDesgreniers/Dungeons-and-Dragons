//! @file 
//! @brief Implementation file for the CharacterDecorator class  
//!
#pragma once
#include "stdafx.h"
#include "CharacterDecorator.h"

//! Default Constructor
CharacterDecorator::CharacterDecorator()
{
	this->decoratedCharacter = nullptr;
	this->decorationSlot = Character::EquipmentSlot::None;
}

//! Custom Constructor
CharacterDecorator::CharacterDecorator(Character *decoratedCharacter, EquipmentSlot decorationSlot)
{
	this->decoratedCharacter = decoratedCharacter;
	this->decorationSlot = decorationSlot;
}

// Manually sets a decorated character
//! @param Character* : a pointer to a character to be set as the decorated character of this Character Decorator
void CharacterDecorator::setDecoratedCharacter(Character *character)
{
	decoratedCharacter = character;
}

// Manually gets a decorated character
//! @return a pointer to the character decorated by this Character Decorator
Character* CharacterDecorator::getDecoratedCharacter()
{
	return decoratedCharacter;
}
