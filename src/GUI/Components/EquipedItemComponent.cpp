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
		Button* itemButton = (new Button(items[i] == nullptr ? "None" : items[i]->getName(), &Renderer::FONT_ROBOTO, 50, i*(fontSize+20), 0, 0));
		itemButton->setFontSize(fontSize);
		itemButton->adjustDimensions();
		itemButton->setPadding(0, 0, 0, 0);
		itemButtons.push_back(itemButton);
		addComponent(itemButton);
		itemButton->addOnClick_callback([this,i](Component* c, int,int)
		{
			for(std::function<void(Item* item, int i)> func: this->onItemClickCallback)
			{
				func(this->items[i], i);
			}
		});

	}
	this->setHeight(Item::ItemType::WEAPON * (fontSize+20) + 30);

}

void EquipedItemComponent::render()
{
	Pane::render();
	drawDefaultStyle();
}

void EquipedItemComponent::addOnItemClick_callback(std::function<void(Item*, int)> func)
{
	onItemClickCallback.push_back(func);
}

void EquipedItemComponent::click(int x, int y)
{
	Pane::click(x, y);
}

void EquipedItemComponent::Update()
{
	for (int i = Item::ItemType::HELMET; i != Item::ItemType::WEAPON; i++)
	{
		itemButtons[i]->setText(items[i] == nullptr ? "None" : items[i]->getName());
		itemButtons[i]->adjustDimensions();
	}
}
