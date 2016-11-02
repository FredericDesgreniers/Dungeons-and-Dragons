#include "CharacterComponent.h"

#include "../../character.h"

#include "../Renderer.h"

CharacterComponent::CharacterComponent(Character* character, int x, int y, int width, int height):Style(x,y,width,height), character(character)
{
	
}

void CharacterComponent::render()
{
	drawDefaultStyle();
	drawStat(getPositionX(), getPositionY(), "Charisma", character->getCharisma());
	drawStat(getPositionX(), getPositionY()+30, "Constitution", character->getConsitution());
	drawStat(getPositionX(), getPositionY()+60, "Desterity", character->getDexterity());
	drawStat(getPositionX(), getPositionY()+90, "Intelligence", character->getIntelligence());
	drawStat(getPositionX(), getPositionY()+120, "Strenght", character->getStrength());
	drawStat(getPositionX(), getPositionY()+150, "Wisdom", character->getWisdom());

}
void CharacterComponent::drawStat(int x, int y, std::string name, int level)
{
	Renderer::drawString(name+" "+std::to_string(level), Renderer::FONT_ROBOTO.get(25), x, y, 1, {255,255,255,255});
}
