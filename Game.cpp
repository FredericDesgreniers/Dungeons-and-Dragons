#include "Game.h"
#include "Renderer.h"
#include "GuiManager.h"

#undef main

int main()
{
	GuiManager gui_manager;

	if(!Renderer::init())
		return 1;

	//font color



	Screen* startScreen = new Screen();
	
	gui_manager.setScreen(startScreen);


	//font location / bounds


	//render loop
	while(true) //TODO: Add loop exit.
	{
		//logic here
		gui_manager.runTick();

		Renderer::iniRender();

		gui_manager.renderScreen();
		//render here

		Renderer::render();

	}

	
	Renderer::destroyRenderer();

}
