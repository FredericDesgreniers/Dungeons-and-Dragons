#include "GuiManager.h"
#include <iostream>
#include "Renderer.h"
#define DEBUG
GuiManager::GuiManager()
{
	currentScreen = nullptr;

	debug = false;
}

void GuiManager::renderScreen()
{
	if (currentScreen != nullptr)
		currentScreen->render();

if (debug){

	if (currentScreen != nullptr)
		currentScreen->renderDebug();

	int mx, my;
	SDL_GetMouseState(&mx, &my);
	Renderer::drawString(std::to_string(mx) + " : " + std::to_string(my), Renderer::FONT_ROBOTO.get(15), 0, 0, 1, { 255,255,255,255 });

	Uint32 averageFrameTime = Renderer::getAverageFrameTime();
	int fps = 1000 / (int)averageFrameTime;

	SDL_Color fpsColor;
	if(fps < 30)
	{
		fpsColor.r = 255;
	}else if(fps < 60)
	{
		fpsColor.r = 255;
		fpsColor.g = 255;
	}else
	{
		fpsColor.g = 255;
	}

	Renderer::drawString("fps: "+std::to_string(fps), Renderer::FONT_ROBOTO.get(15), 0, 20, 1,
	fpsColor);

}
}


void GuiManager::runTick()
{
	if (currentScreen != nullptr)
		currentScreen->tick();
}

void GuiManager::clickScreen(int x, int y)
{
	currentScreen->click(x, y);
}


Screen* GuiManager::setScreen(Screen* screen)
{
	Screen* oldScreen = currentScreen;
	currentScreen = screen;
	return oldScreen;
}
