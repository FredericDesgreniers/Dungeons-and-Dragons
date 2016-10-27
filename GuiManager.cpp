#include "GuiManager.h"
#include <iostream>

GuiManager::GuiManager()
{
	currentScreen = nullptr;
}

void GuiManager::renderScreen()
{
	if (currentScreen != nullptr)
		currentScreen->render();
}


void GuiManager::runTick()
{
	if (currentScreen != nullptr)
		currentScreen->tick();
}

void GuiManager::clickScreen(int x, int y)
{
	std::cout << x << " " << y << std::endl;
	currentScreen->click(x, y);
}


Screen* GuiManager::setScreen(Screen* screen)
{
	Screen* oldScreen = currentScreen;
	currentScreen = screen;
	return oldScreen;
}
