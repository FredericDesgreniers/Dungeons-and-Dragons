#pragma once
#include "Pane.h"
#include "../../Item.h"

class EquipedItemComponent:public Pane
{
public:
	EquipedItemComponent(Item** items,int x, int y, int width, int height);
	void render() override;
private:
	Item** items;
};
