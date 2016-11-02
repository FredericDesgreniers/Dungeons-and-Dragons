#include "VariableComponent.h"

VariableComponent::VariableComponent(int* variable,Font* font, int x, int y) : Label(std::to_string(*variable),font,x,y,10,10), variable(variable)
{
	this->adjustDimensions();
	oldValue = *variable;
}

void VariableComponent::tick()
{
	if(oldValue!=*variable)
	{
		this->setText(std::to_string(*variable));
		oldValue = *variable;
	}
}

VariableComponent* VariableComponent::setFontSize(int size)
{
	Label::setFontSize(size);
	adjustDimensions();
	return this;
}


