#pragma once
#include "../../ItemContainer.h"
#include "Pane.h"
#include "Label.h"

/**
 * \brief Displays an item container
 *
 */
class ItemContainerComponent:public Pane, Observer
{
public:
	ItemContainerComponent(ItemContainer* container, int x, int y, int width, int height);

	/**
	 * \brief set the Item Container to display
	 */
	void setItemContainer(ItemContainer* container);

	void render() override;

	void Update() override;
private:
	ItemContainer* container;
	Label** itemLabels;
	Label* nameLabel;
};
