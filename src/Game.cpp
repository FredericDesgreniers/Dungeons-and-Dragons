#include "Game.h"

#include "GUI/Screens/ScreenMain.h"
#include "GUI/Renderer.h"
#include <direct.h>


#undef main


Game::Game()
{
	gui_manager = new GuiManager();
}

bool Game::ini()
{
	_mkdir("maps/");
	_mkdir("characters/");

	if (!Renderer::init())
		return false;

	//font color



	ScreenMain* titleScreen = new ScreenMain(this);

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
			case SDL_KEYDOWN:
				gui_manager->keyPressed(event.key.keysym.sym);
				switch(event.key.keysym.sym)
				{
				case SDLK_z:
					gui_manager->toggleDebug();
					break;
				}
				break;

			}
		}

		//logic here
		gui_manager->runTick();

		Renderer::iniRender();

		gui_manager->renderScreen();
		//render here

		Renderer::render();


		Renderer::destroyVoidedScreens();
	}

	return true;
}

bool Game::exit()
{
	Renderer::destroyRenderer();

	return true;
}

GuiManager* Game::getGuiManager()
{
	return gui_manager;
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
