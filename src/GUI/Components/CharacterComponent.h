#pragma once

#include "Pane.h"
#include "../../character.h"

/**
 * Used to display the character's stats on the screen as a component.
 */
class CharacterComponent:public Pane
{
public:
	CharacterComponent(Character* character, int x, int y, int width, int height);

	
	void render() override;

	void tick() override;


	~CharacterComponent();
private:
	Character* character;


};
