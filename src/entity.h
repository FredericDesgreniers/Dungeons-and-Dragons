#pragma once

class Entity
{
public:
	Entity(char renderChar);

	void setPosition(int x, int y)
	{
		positionX = x;
		positionY = y;
	}
	int getPositionX()
	{
		return positionX;
	}
	int getPositionY()
	{
		return positionY;
	}

	char getRenderChar()
	{
		return renderChar;
	}

private:
	int positionX, positionY;
	char renderChar = ' ';
};