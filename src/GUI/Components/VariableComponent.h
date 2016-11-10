#pragma once
#include "Label.h"
/**
 * VariableComponent will display an int pointed too
 */
class VariableComponent : public Label
{
public:
	/**
	 * Constructor given variable pointer(int*), x, y
	 */
	VariableComponent(int* variable, Font* font,int x, int y);
	/**
	 * Override tick method
	 */
	void tick() override;
	/**
	 * Set font size
	 */
	VariableComponent* setFontSize(int size) override;
private:
	int* variable;
	int oldValue;
};
