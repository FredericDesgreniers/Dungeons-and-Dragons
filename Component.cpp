#include "Component.h"

Component::Component(int width, int height)
{
	dimensions.w = width;
	dimensions.h = height;
}

Component::Component(int positionX, int positionY, int width, int height) : Component(width, height)
{
	

	dimensions.x = positionX;
	dimensions.y = positionY;
	
}

