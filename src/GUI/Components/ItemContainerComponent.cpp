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
			itemLabels[i] = new Label("Empty", &Renderer::FONT_ROBOTO, 0, 0, 0, 0);
			itemLabels[i]->setVisible(false);
			addComponent(itemLabels[i]);
		}
		
	}

	Update();
}

void ItemContainerComponent::Update()
{
	int yPos = 0;
	for (int i = 0; i < container->getSize(); i++)
	{
		Item* item = container->getItemAtIndex(i);
		if(item!=nullptr)
		{
			itemLabels[i]->setText(itemLabels[i]->getText());
			itemLabels[i]->setPositionX(0);
			itemLabels[i]->setPositionY(yPos);
			itemLabels[i]->adjustDimensions();
			itemLabels[i]->setVisible(true);
			yPos += 20;
		}else
		{
			itemLabels[i]->setVisible(false);
		}
	}
}


