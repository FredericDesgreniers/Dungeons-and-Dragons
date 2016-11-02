#pragma once
#include "Label.h"

class VariableComponent : public Label
{
public:
	VariableComponent(int* variable, Font* font,int x, int y);

	void tick() override;
	VariableComponent* setFontSize(int size) override;
private:
	int* variable;
	int oldValue;
};
