#include "Game.h"
#include "Renderer.h"
#include "GuiManager.h"
#include "ScreenMain.h"

#undef main

int main()
{
	GuiManager gui_manager;

	if(!Renderer::init())
		return 1;

	//font color



	ScreenMain* startScreen = new ScreenMain();
	
	gui_manager.setScreen(startScreen);


	//font location / bounds

	bool running = true;

	//render loop
	while(running) //TODO: Add loop exit.
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				
			case SDL_MOUSEBUTTONUP:
				int x, y;

				SDL_GetMouseState(&x, &y);
				gui_manager.clickScreen(x, y);
				break;
			case SDL_QUIT:
				running = false;
				break;
			}
		}

		//logic here
		gui_manager.runTick();

		Renderer::iniRender();

		gui_manager.renderScreen();
		//render here

		Renderer::render();

	}

	
	Renderer::destroyRenderer();

}
