#include "CharacterComponent.h"

#include "../../LivingEntity.h"

#include "../Renderer.h"
#include "VariableComponent.h"

CharacterComponent::CharacterComponent(LivingEntity* character, int x, int y, int width, int height):Pane(x,y,width,height)
{
	setFontSize(15);

	setLivingEntity(character);

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
	Renderer::drawString(to_string(character->getLevel()), Renderer::FONT_ROBOTO.get(15),getPositionX()+50, getPositionY()+30, 1,{255,255,255,255});


}
void CharacterComponent::setLivingEntity(LivingEntity* entity)
{
	clearComponents();
	character = entity;
	int i = 10;
	addComponent((new Label(character->getName(), &Renderer::FONT_ROBOTO, 10, 0, 0, 0))->setFontSize(15)->adjustDimensions());
	addComponent((new Label("Lvl  - ", &Renderer::FONT_ROBOTO, 10, i += 20, 0, 0))->setFontSize(15)->adjustDimensions());
	addComponent((new Label("Str  - ", &Renderer::FONT_ROBOTO, 10, i += 20, 0, 0))->setFontSize(15)->adjustDimensions());
	addComponent((new VariableComponent(&character->getEffectiveAbilityScoreArray()[0], &Renderer::FONT_ROBOTO, 60, i))->setFontSize(15));
	addComponent((new Label("Dex  - ", &Renderer::FONT_ROBOTO, 10, i += 20, 0, 0))->setFontSize(15)->adjustDimensions());
	addComponent((new VariableComponent(&character->getEffectiveAbilityScoreArray()[1], &Renderer::FONT_ROBOTO, 60, i))->setFontSize(15));
	addComponent((new Label("Int  - ", &Renderer::FONT_ROBOTO, 10, i += 20, 0, 0))->setFontSize(15)->adjustDimensions());
	addComponent((new VariableComponent(&character->getEffectiveAbilityScoreArray()[2], &Renderer::FONT_ROBOTO, 60, i))->setFontSize(15));
	addComponent((new Label("Wisd - ", &Renderer::FONT_ROBOTO, 10, i += 20, 0, 0))->setFontSize(15)->adjustDimensions());
	addComponent((new VariableComponent(&character->getEffectiveAbilityScoreArray()[3], &Renderer::FONT_ROBOTO, 60, i))->setFontSize(15));
	addComponent((new Label("Cons - ", &Renderer::FONT_ROBOTO, 10, i += 20, 0, 0))->setFontSize(15)->adjustDimensions());
	addComponent((new VariableComponent(&character->getEffectiveAbilityScoreArray()[4], &Renderer::FONT_ROBOTO, 60, i))->setFontSize(15));
	addComponent((new Label("Char - ", &Renderer::FONT_ROBOTO, 10, i += 20, 0, 0))->setFontSize(15)->adjustDimensions());
	addComponent((new VariableComponent(&character->getEffectiveAbilityScoreArray()[5], &Renderer::FONT_ROBOTO, 60, i))->setFontSize(15));

}


CharacterComponent::~CharacterComponent()
{
	
}
