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
	/**
	 * Constructor given a container, x, y , width, height in int
	 */
	ItemContainerComponent(ItemContainer* container, int x, int y, int width, int height);

	/**
	 * \brief set the Item Container to display
	 */
	void setItemContainer(ItemContainer* container);

	void getItemContainer();

	/**
	 * Override render method
	 */
	void render() override;
	/**
	 * Add callback for when item is clicked
	 */
	void addOnItemClick_callback(std::function<void(Item*, int)>);
	/**
	 * Update when subject changes
	 */
	void Update() override;

	~ItemContainerComponent();
private:
	ItemContainer* container;
	Label** itemLabels;
	Label* nameLabel;
	
	std::vector<std::function<void(Item*, int)>> onItemClick_callback;
};
