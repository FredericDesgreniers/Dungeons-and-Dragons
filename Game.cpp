#include "Game.h"
#include "Renderer.h"
#include "GuiManager.h"
#include "ScreenMain.h"
#include "ScreenTitle.h"

#undef main


Game::Game()
{
	gui_manager = new GuiManager();
}

bool Game::ini()
{

	if (!Renderer::init())
		return false;

	//font color



	ScreenTitle* titleScreen = new ScreenTitle(this);

	gui_manager->setScreen(titleScreen);
	
	return true;

}

bool Game::run()
{
	bool running = true;

	//render loop
	while (running) //TODO: Add loop exit.
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{

			case SDL_MOUSEBUTTONUP:
				int x, y;

				SDL_GetMouseState(&x, &y);
				gui_manager->clickScreen(x, y);
				break;
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYUP:
				switch(event.key.keysym.sym)
				{
				case SDLK_z:
					gui_manager->toggleDebug();
					break;
				}
			}
		}

		//logic here
		gui_manager->runTick();

		Renderer::iniRender();

		gui_manager->renderScreen();
		//render here

		Renderer::render();

	}

	return true;
}

bool Game::exit()
{
	Renderer::destroyRenderer();

	return true;
}


int main()
{
	Game game;
	if(!game.ini())
	{
		std::cout << "Error initializing the game" << std::endl;
	}
	if(!game.run())
	{
		std::cout << "Error running the game" << std::endl;
	}
	if(!game.exit())
	{
		std::cout << "Error exiting the game" << std::endl;
	}

	//font location / bounds

	

	


}
