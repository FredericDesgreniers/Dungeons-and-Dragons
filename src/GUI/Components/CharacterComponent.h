#pragma once

#include "Pane.h"
#include "../../LivingEntity.h"

/**
 * Used to display the character's stats on the screen as a component.
 */
class CharacterComponent:public Pane
{
public:
	CharacterComponent(LivingEntity* character, int x, int y, int width, int height);

	void setLivingEntity(LivingEntity*);

	void render() override;

	void tick() override;


	~CharacterComponent();
private:
	LivingEntity* character;


};
