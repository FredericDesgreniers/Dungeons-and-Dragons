#include "GuiManager.h"

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

Screen* GuiManager::setScreen(Screen* screen)
{
	Screen* oldScreen = currentScreen;
	currentScreen = screen;
	return oldScreen;
}
