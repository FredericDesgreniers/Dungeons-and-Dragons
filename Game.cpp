#include "Game.h"
#include "Renderer.h"

#undef main

int main()
{

	if(!Renderer::init())
		return 1;

	//font color
	SDL_Color whiteColor = { 255,255,255 };




	//font location / bounds

	SDL_Rect text_rect;
	text_rect.x = 0;
	text_rect.y = 0;
	text_rect.w = 100;
	text_rect.h = 40;
	SDL_Texture* titleText = Renderer::CreateTexture("d&d game", Renderer::FONT_ROBOTO_24, whiteColor);

	//render loop
	while(true) //TODO: Add loop exit.
	{
		Renderer::iniRender();
		//render here
		Renderer::RenderTexture(titleText, &text_rect);
		Renderer::render();

	}

	Renderer::destroyTexture(titleText);
	Renderer::destroyRenderer();

}
