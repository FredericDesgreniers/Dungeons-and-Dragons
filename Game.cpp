#include "Game.h"
#include <SDL/SDL.h>
#include <iostream>
#include <SDL/SDL_ttf.h>
#undef main

int main()
{
	//Initilize SDL2
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}


	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
	//create Window 
	//a
	SDL_Window *win = SDL_CreateWindow("D&D game", 50, 50, 500, 500, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (win == nullptr)
	{
		std::cout << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	//create renderer
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(ren == nullptr)
	{
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
	}
	

	//open font
	TTF_Font* font = TTF_OpenFont("resources/Roboto-Regular.ttf", 24);
	if (font == nullptr)
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "TTF_openFOnt... error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		std::cin.get();
		return 1;
	}
	//font color
	SDL_Color whiteColor = { 255,255,255 };

	SDL_Surface* sText = TTF_RenderText_Solid(font, "D&D Game", whiteColor);

	if(sText == nullptr)
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_renderText... error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		std::cin.get();
		return 1;
	}
	//create font texture
	SDL_Texture* text = SDL_CreateTextureFromSurface(ren, sText);

	if(text == nullptr)
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL+CeateTexture... error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		std::cin.get();
		return 1;
	}

	//font location / bounds
	SDL_Rect text_rect;
	text_rect.x = 0;
	text_rect.y = 0;
	text_rect.w = 100;
	text_rect.h = 20;


	//render loop
	while(true)
	{
		SDL_RenderClear(ren);

		//render here
		SDL_RenderCopy(ren, text, NULL, &text_rect);

		SDL_RenderPresent(ren);

		SDL_Delay(100);
	}


	SDL_DestroyTexture(text);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}