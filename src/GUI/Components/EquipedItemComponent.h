#pragma once
#include "Pane.h"
#include "../../Item.h"
#include "Button.h"

class EquipedItemComponent:public Pane, public Observer
{
public:
	EquipedItemComponent(Item** items,int x, int y, int width, int height);
	void render() override;
	void click(int x, int y) override;
	void addOnItemClick_callback(std::function<void(Item*, int)>);
	
	void setItems(Item** itms);

	void Update() override;
private:
	Item** items;
	std::vector<Button*> itemButtons;

	std::vector<std::function<void(Item*,int)>> onItemClickCallback;
};
