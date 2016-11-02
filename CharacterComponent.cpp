#include "CharacterComponent.h"
#include "Renderer.h"

CharacterComponent::CharacterComponent(Character* character, int x, int y, int width, int height):Style(x,y,width,height), character(character)
{
	
}

void CharacterComponent::render()
{
	drawDefaultStyle(false);
	drawStat(getPositionX(), getPositionY(), "charisma", character->getCharisma());
	drawStat(getPositionX(), getPositionY()+30, "constitution", character->getConsitution());
	drawStat(getPositionX(), getPositionY()+60, "desterity", character->getDexterity());
	drawStat(getPositionX(), getPositionY()+90, "intelligence", character->getIntelligence());
	drawStat(getPositionX(), getPositionY()+120, "strenght", character->getStrength());
	drawStat(getPositionX(), getPositionY()+150, "wisdom", character->getWisdom());

}
void CharacterComponent::drawStat(int x, int y, std::string name, int level)
{
	Renderer::drawString(name+" "+std::to_string(level), Renderer::FONT_ROBOTO.get(25), x, y, 1, {255,255,255,255});
}
