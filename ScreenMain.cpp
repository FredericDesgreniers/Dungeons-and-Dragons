#include "ScreenMain.h"
#include "Renderer.h"

ScreenMain::ScreenMain()
{
	addButton(new Button(0, "Play", 100,100,100,30));
}

void ScreenMain::onButtonClicked(Button* b)
{
	
}

void ScreenMain::render()
{
	Screen::render();

	int mx, my;
	SDL_GetMouseState(&mx, &my);

	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = 100;
	rect.h = 20;

	SDL_Texture* text = Renderer::CreateTexture(std::to_string(mx) + ": " + std::to_string(my), Renderer::FONT_ROBOTO_24, { 255,255,255,255 });
	Renderer::RenderTexture(text, &rect);

	Renderer::destroyTexture(text);


}


