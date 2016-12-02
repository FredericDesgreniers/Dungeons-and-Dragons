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

	/**
	 * Set the entity to display
	 */
	void setLivingEntity(LivingEntity*);

	/**
	 * Override render method
	 */
	void render() override;

	/**
	 * Override tick method
	 */
	void tick() override;

	/**
	 * Destructor to clean up
	 */
	~CharacterComponent();
private:
	/**
	 * Stores character to display
	 */
	LivingEntity* character;


};
