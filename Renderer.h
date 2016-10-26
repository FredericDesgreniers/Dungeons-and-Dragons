#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <iostream>

class Renderer
{
public:
	Renderer();
	bool init();
	
	void iniRender();
	void render();

	static TTF_Font* FONT_ROBOTO_24;
	
	SDL_Texture* CreateTexture(std::string text, TTF_Font* font, SDL_Color color);
	void RenderTexture(SDL_Texture*, SDL_Rect* bounds);

	void destroyTexture(SDL_Texture* texture);

	~Renderer();

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	bool loadFonts();

};
