#include "ItemContainerComponent.h"
#include "../Renderer.h"


ItemContainerComponent::ItemContainerComponent(ItemContainer* container, int x, int y, int width, int height) :Pane(x, y, width, height)
{
	nameLabel = new Label("Name", &Renderer::FONT_ROBOTO, 50,0,10,10);
	addComponent(nameLabel);
	setItemContainer(container);
}

void ItemContainerComponent::render()
{
	Pane::render();
	drawDefaultStyle();
}

void ItemContainerComponent::setItemContainer(ItemContainer* container)
{
	if(container!=nullptr)
	{
		container->Detach(this);
	}
	
	this->container = container;

	container->Attach(this);
	nameLabel->setText(container->getName());
	nameLabel->adjustDimensions();
	if (itemLabels == nullptr) {
		itemLabels = new Label*[container->getSize()];
		for (int i = 0; i < container->getSize(); i++)
		{
			itemLabels[i] = new Button("Empty", &Renderer::FONT_ROBOTO, 0, 0, 0, 0);
			itemLabels[i]->setPadding(0, 0, 0, 0);
			itemLabels[i]->setVisible(false);

			addComponent(itemLabels[i]);
		}
		
	}

	Update();
}
void ItemContainerComponent::addOnItemClick_callback(std::function<void(Item*, int)> func)
{
	onItemClick_callback.push_back(func);
}

void ItemContainerComponent::Update()
{

	int yPos = 40;
	for (int i = 0; i < container->getSize(); i++)
	{
		Item* item = container->getItemAtIndex(i);
		if(item!=nullptr)
		{
			Label* label = itemLabels[i];
			label->setText(item->getName());
			label->setPositionX(getPositionX()+ 20);
			label->setPositionY(getPositionY()+yPos);
			label->adjustDimensions();
			label->setVisible(true);
			label->clearCallbacks();

			label->addOnClick_callback([this,  i](Component*, int, int)
			{
				for (std::function<void(Item*, int)> func : onItemClick_callback)
				{
					func(this->container->getItemAtIndex(i), i);
				}
				
			});
			
		}else
		{
			itemLabels[i]->setVisible(false);
		}
		yPos += 40;
	}
}

