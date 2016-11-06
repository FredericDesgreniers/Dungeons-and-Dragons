#include "EquipedItemComponent.h"
#include "Label.h"
#include "../Renderer.h"
EquipedItemComponent::EquipedItemComponent(Item** items, int x, int y, int width, int height):Pane(x,y,width,height)
{
	this->items = items;
	setFontSize(15);
	for (int i = Item::ItemType::HELMET; i != Item::ItemType::WEAPON; i++)
	{

		addComponent((new Label(Item::displayType(static_cast<Item::ItemType>(i)), &Renderer::FONT_ROBOTO, 0, i*(fontSize+20), 0, 0))->setFontSize(fontSize)->adjustDimensions());
	}
	this->setHeight(Item::ItemType::WEAPON * (fontSize+20) + 30);
	this->setWidth(100);
}

void EquipedItemComponent::render()
{
	Pane::render();
	drawDefaultStyle();
	for (int i = Item::ItemType::HELMET; i != Item::ItemType::WEAPON; i++)
	{
		if(items[i]!=nullptr)
			Renderer::drawString(items[i]->getName(), Renderer::FONT_ROBOTO.get(15), 150, i*(fontSize+20),1,{255,255,255,255});
	}

}

