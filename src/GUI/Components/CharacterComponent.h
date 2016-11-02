#pragma once
#include "Style.h"

#include  "../../character.h"
#include "Pane.h"
#include "Label.h"
#include "../Renderer.h"


class CharacterComponent:public Pane
{
public:
	CharacterComponent(Character* character, int x, int y, int width, int height);

	void render() override;

	void reloadLabelText();

	~CharacterComponent();
private:
	Character* character;
	

	void drawStat(int x, int y, std::string name, int level);

	Label* levelLabel;

	//int str, int dex, int cons, int intel, int wisd, int chari
	Label* labelStr;
	Label* labelDex;
	Label* labelCons;
	Label* labelInt;
	Label* labelWisd;
	Label* labelChari;
	Label* statLabels[6];

};
