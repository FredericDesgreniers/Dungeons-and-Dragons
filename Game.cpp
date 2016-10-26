#include "Game.h"
#include <SDL/SDL.h>
#include <iostream>
#include <SDL/SDL_ttf.h>
#include "Renderer.h"

#undef main

int main()
{
	Renderer renderer;

	if(!renderer.init())
		return 1;







	


	//font color
	SDL_Color whiteColor = { 255,255,255 };




	//font location / bounds
	SDL_Rect text_rect;
	text_rect.x = 0;
	text_rect.y = 0;
	text_rect.w = 100;
	text_rect.h = 20;

	SDL_Texture* titleText = renderer.CreateTexture("d&d game", Renderer::FONT_ROBOTO_24, whiteColor);

	//render loop
	while(true) //TODO: Add loop exit.
	{
		
		renderer.iniRender();
		//render here
		renderer.RenderTexture(titleText, &text_rect);
		renderer.render();

	}

	renderer.destroyTexture(titleText);

}
