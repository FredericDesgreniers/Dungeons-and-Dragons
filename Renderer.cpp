#include "Renderer.h"

Font Renderer::FONT_ROBOTO("Roboto-Regular");
SDL_Window* Renderer::window = nullptr;
SDL_Renderer* Renderer::renderer = nullptr;

Uint32 Renderer::fpsArray[20];
int Renderer::fpsCounter = 0;
Uint32 Renderer::lastTime = 0;

/**
 *
 */
bool Renderer::init()
{
	//Initilize SDL2
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	//initialize fonts
	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		return false;
	}

		//create Window 
	window = SDL_CreateWindow("D&D game", 50, 50, 900, 900, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (window == nullptr)
	{
		std::cout << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	//create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		SDL_DestroyWindow(window);
		std::cout << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
		return false;
	}



	return true;
}



SDL_Texture* Renderer::CreateTexture(std::string text, TTF_Font* font, SDL_Color color)
{
	SDL_Surface* sText = TTF_RenderText_Solid(font, text.c_str(), color);
	if (sText == nullptr)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		std::cout << "SDL_renderText... error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		
		return nullptr;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, sText);
	SDL_FreeSurface(sText);
	return texture;
}

void Renderer::RenderTexture(SDL_Texture* texture, SDL_Rect* bounds)
{
	SDL_RenderCopy(Renderer::renderer, texture, NULL, bounds);
}

void Renderer::drawString(std::string str, TTF_Font* font, int x, int y, int scale,  SDL_Color color)
{
	SDL_Texture* texture = CreateTexture(str, font, color);

	SDL_Rect bounds;
	bounds.x = x;
	bounds.y = y;

	TTF_SizeText(font, str.c_str(), &bounds.w, &bounds.h);
	bounds.w *= scale;
	bounds.h *= scale;
	RenderTexture(texture, &bounds);

	destroyTexture(texture);
}

void Renderer::iniRender()
{
	setColor(0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Renderer::render()
{
		if(lastTime == 0)
		{
			lastTime = SDL_GetTicks();
		}else
		{
			Uint32 time = SDL_GetTicks();
			fpsArray[fpsCounter] = time - lastTime;
			lastTime = time;

			fpsCounter++;
			if (fpsCounter >= 20)
				fpsCounter = 0;
		}

	SDL_RenderPresent(renderer);

}

Uint32 Renderer::getAverageFrameTime()
{
	Uint32 total = 0;
	for (int i = 0; i < 20; i++)
	{
		total += fpsArray[i];
	}
	return total / 20;
}


void Renderer::destroyTexture(SDL_Texture* texture)
{
	SDL_DestroyTexture(texture);
}

void Renderer::RenderRect(int x, int y, int width, int height)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	SDL_RenderFillRect(renderer, &rect);
}

void Renderer::RenderRectOutline(int x, int y, int width, int height)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;

	SDL_RenderDrawRect(renderer, &rect);
}
void Renderer::drawLine(int x1, int y1, int x2, int y2)
{
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Renderer::destroyRenderer()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


