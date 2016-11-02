#include "CharacterComponent.h"

#include "../../character.h"

#include "../Renderer.h"

CharacterComponent::CharacterComponent(Character* character, int x, int y, int width, int height):Pane(x,y,width,height), character(character)
{
	setFontSize(15);

	levelLabel = new Label("Level  - " + std::to_string(character->getStrength()), &Renderer::FONT_ROBOTO, 10, 12, 0, 0);
	levelLabel->setFontSize(18);
	labelStr = new Label("Str  - " + std::to_string(character->getStrength()), &Renderer::FONT_ROBOTO, 10, 10, 0, 0);
	labelDex = new Label("Dex  - "+std::to_string(character->getStrength()), &Renderer::FONT_ROBOTO, 10,25,0,0);
	labelInt = new Label("Int  - "+std::to_string(character->getStrength()), &Renderer::FONT_ROBOTO, 10,40,0,0);
	labelWisd = new Label("Wisd - "+std::to_string(character->getStrength()), &Renderer::FONT_ROBOTO, 10,55,0,0);
	labelCons = new Label("Cons - "+std::to_string(character->getStrength()), &Renderer::FONT_ROBOTO, 10,70,0,0);
	labelChari = new Label("Char - "+std::to_string(character->getStrength()), &Renderer::FONT_ROBOTO, 10,85,0,0);



	statLabels[0] = labelStr;
	statLabels[1] = labelDex;
	statLabels[2] = labelInt;
	statLabels[3] = labelWisd;
	statLabels[4] = labelCons;
	statLabels[5] = labelChari;

	addComponent(levelLabel);

	for (int i = 0; i < 6; i++)
	{
		statLabels[i]->setFontSize(18);
		statLabels[i]->setPositionY(i * 25 + 40);
		addComponent(statLabels[i]);
		statLabels[i]->adjustDimensions();
	}
	this->setHeight(7 * 25 + 30);
	this->setWidth(90);
	reloadLabelText();

}

void CharacterComponent::reloadLabelText()
{
	levelLabel->setText("Level " + std::to_string(character->getLevel()));
	levelLabel->adjustDimensions();

	labelStr->setText("Str " + std::to_string(character->getStrength()));
	labelDex->setText("Dex " + std::to_string(character->getDexterity()));
	labelInt->setText("Int " + std::to_string(character->getIntelligence()));
	labelWisd->setText("Wisd " + std::to_string(character->getWisdom()));
	labelCons->setText("Cons " + std::to_string(character->getConsitution()));
	labelChari->setText("Char " + std::to_string(character->getCharisma()));

	for (int i = 0; i < 6; i ++)
	{
		statLabels[i]->adjustDimensions();
	}
}

void CharacterComponent::render()
{
	Pane::render();
	drawDefaultStyle();


}
void CharacterComponent::drawStat(int x, int y, std::string name, int level)
{
	Renderer::drawString(name+" "+std::to_string(level), Renderer::FONT_ROBOTO.get(fontSize), x, y, 1, {255,255,255,255});
}

CharacterComponent::~CharacterComponent()
{
	
}
