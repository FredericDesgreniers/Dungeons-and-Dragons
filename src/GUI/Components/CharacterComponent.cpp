#include "CharacterComponent.h"

#include "../../character.h"

#include "../Renderer.h"

CharacterComponent::CharacterComponent(Character* character, int x, int y, int width, int height):Pane(x,y,width,height), character(character)
{
	setFontSize(15);

	int i = 10;
	addComponent((new Label("Level  - ", &Renderer::FONT_ROBOTO, 10, i+=20, 0, 0))->setFontSize(10)->adjustDimensions());

	addComponent ((new Label("Str  - ", &Renderer::FONT_ROBOTO, 10, i += 20, 0, 0))->adjustDimensions());
	addComponent(new VariableComponent(&character->getAbilityScoreArray()[0], &Renderer::FONT_ROBOTO, 80, i));
	addComponent ((new Label("Dex  - ", &Renderer::FONT_ROBOTO, 10, i += 20,0,0))->adjustDimensions());
	addComponent(new VariableComponent(&character->getAbilityScoreArray()[1], &Renderer::FONT_ROBOTO, 80, i));
	addComponent ((new Label("Int  - ", &Renderer::FONT_ROBOTO, 10, i += 20,0,0))->adjustDimensions());
	addComponent(new VariableComponent(&character->getAbilityScoreArray()[2], &Renderer::FONT_ROBOTO, 80, i));
	addComponent ((new Label("Wisd - ", &Renderer::FONT_ROBOTO, 10, i += 20,0,0))->adjustDimensions());
	addComponent(new VariableComponent(&character->getAbilityScoreArray()[3], &Renderer::FONT_ROBOTO, 80, i));
	addComponent ((new Label("Cons - ", &Renderer::FONT_ROBOTO, 10, i += 20,0,0))->adjustDimensions());
	addComponent(new VariableComponent(&character->getAbilityScoreArray()[4], &Renderer::FONT_ROBOTO, 80, i));
	addComponent ((new Label("Char - ",&Renderer::FONT_ROBOTO, 10, i += 20,0,0))->adjustDimensions());
	addComponent(new VariableComponent(&character->getAbilityScoreArray()[5], &Renderer::FONT_ROBOTO, 80, i));


	




	this->setHeight(7 * 25 + 30);
	this->setWidth(100);
	reloadLabelText();

}
void CharacterComponent::tick()
{
	Pane::tick();

}

void CharacterComponent::reloadLabelText()
{

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
