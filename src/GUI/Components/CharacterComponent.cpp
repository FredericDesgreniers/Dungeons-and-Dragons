#include "CharacterComponent.h"

#include "../../character.h"

#include "../Renderer.h"
#include "VariableComponent.h"

CharacterComponent::CharacterComponent(Character* character, int x, int y, int width, int height):Pane(x,y,width,height), character(character)
{
	setFontSize(15);

	int i = 10;
	addComponent((new Label("Lvl  - ", &Renderer::FONT_ROBOTO, 10, i+=20, 0, 0))->setFontSize(15)->adjustDimensions());

	addComponent ((new Label("Str  - ", &Renderer::FONT_ROBOTO, 10, i += 20, 0, 0))->setFontSize(15)->adjustDimensions());
	addComponent((new VariableComponent(&character->getAbilityScoreArray()[0], &Renderer::FONT_ROBOTO, 60, i))->setFontSize(15));
	addComponent ((new Label("Dex  - ", &Renderer::FONT_ROBOTO, 10, i += 20,0,0))->setFontSize(15)->adjustDimensions());
	addComponent((new VariableComponent(&character->getAbilityScoreArray()[1], &Renderer::FONT_ROBOTO, 60, i))->setFontSize(15));
	addComponent ((new Label("Int  - ", &Renderer::FONT_ROBOTO, 10, i += 20,0,0))->setFontSize(15)->adjustDimensions());
	addComponent((new VariableComponent(&character->getAbilityScoreArray()[2], &Renderer::FONT_ROBOTO, 60, i))->setFontSize(15));
	addComponent ((new Label("Wisd - ", &Renderer::FONT_ROBOTO, 10, i += 20,0,0))->setFontSize(15)->adjustDimensions());
	addComponent((new VariableComponent(&character->getAbilityScoreArray()[3], &Renderer::FONT_ROBOTO, 60, i))->setFontSize(15));
	addComponent ((new Label("Cons - ", &Renderer::FONT_ROBOTO, 10, i += 20,0,0))->setFontSize(15)->adjustDimensions());
	addComponent((new VariableComponent(&character->getAbilityScoreArray()[4], &Renderer::FONT_ROBOTO, 60, i))->setFontSize(15));
	addComponent ((new Label("Char - ",&Renderer::FONT_ROBOTO, 10, i += 20,0,0))->setFontSize(15)->adjustDimensions());
	addComponent((new VariableComponent(&character->getAbilityScoreArray()[5], &Renderer::FONT_ROBOTO, 60, i))->setFontSize(15));


	




	this->setHeight(7 * 25 + 30);
	this->setWidth(100);


}
void CharacterComponent::tick()
{
	Pane::tick();

}


void CharacterComponent::render()
{
	Pane::render();
	drawDefaultStyle();


}


CharacterComponent::~CharacterComponent()
{
	
}
