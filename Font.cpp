#include "Font.h"
#include "Renderer.h"

Font::Font(std::string name): name(name)
{

}

TTF_Font* Font::get(int size)
{
	if(size < 0 || size >=100)
	{
		return nullptr;
	}
	if(fonts[size] == nullptr)
	{
		fonts[size] = TTF_OpenFont(("resources/" + name + ".ttf").c_str(), size);
		if (fonts[size] == nullptr)
		{
			std::cout << "Could not load " << name << ".ttf at size " << size << std::endl;
			std::cout << SDL_GetError() << std::endl;
			return nullptr;

		}
		
	}
	
	return fonts[size];
	
}

