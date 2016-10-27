#pragma once
#include <string>
#include <SDL/SDL.h>

class Button
{
public:
	Button(int id, std::string text, int x, int y, int width, int height);

	bool isInBounds(int x, int y) { return x >= this->x && y >= this->y && x <= this->x + width && y <= this->y + height; }

	void render();

	int getX() { return x; }
	int getY() { return y; }

	int getWidth() { return width; }
	int getHeight() { return height; }
	
	int getId() { return id; }

	~Button();

private:
	int id, x, y, width, height;
	std::string text;

	SDL_Texture* texture;
};
