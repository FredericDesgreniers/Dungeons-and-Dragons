#pragma once
#include "Style.h"

#include  "../../character.h"
#include "Pane.h"
#include "Label.h"
#include "../Renderer.h"
#include "VariableComponent.h"


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
