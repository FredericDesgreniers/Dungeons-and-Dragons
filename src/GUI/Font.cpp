#include "Font.h"
#include "Renderer.h"

Font::Font(std::string name): name(name)
{

}

TTF_Font* Font::get(const int size)
{
	if(size < 0)
	{
		return nullptr;
	}
	if(fonts[size] == nullptr)
	{
		fonts[size] = TTF_OpenFont(("resources/" + name + ".ttf").c_str(), size);
		if (fonts[size] == nullptr)
		{
			return nullptr;

		}
		
	}
	
	return fonts[size];
	
}

