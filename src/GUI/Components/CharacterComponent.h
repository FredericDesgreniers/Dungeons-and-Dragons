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

	void reloadLabelText();
	void tick() override;


	~CharacterComponent();
private:
	Character* character;
	

	void drawStat(int x, int y, std::string name, int level);

	VariableComponent* levelLabel;

	//int str, int dex, int cons, int intel, int wisd, int chari
	VariableComponent* labelStr;
	VariableComponent* labelDex;
	VariableComponent* labelCons;
	VariableComponent* labelInt;
	VariableComponent* labelWisd;
	VariableComponent* labelChari;
	VariableComponent* statLabels[6];

};
