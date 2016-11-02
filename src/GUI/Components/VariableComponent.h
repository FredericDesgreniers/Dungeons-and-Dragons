#pragma once
#include "Label.h"

class VariableComponent : public Label
{
public:
	VariableComponent(int* variable, Font* font,int x, int y);

	void tick() override;

private:
	int* variable;
	int oldValue;
};
