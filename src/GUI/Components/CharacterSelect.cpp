#include "CharacterSelect.h"
#include "Windows.h"
#include "string"
#include <iostream>
#include "Button.h"
#include "../Renderer.h"

CharacterSelect::CharacterSelect(int x, int y, int width, int height):Pane(x,y,width,height)
{
	std::vector<std::string> names;
	char search_path[200];
	sprintf_s(search_path, "%s*.*", "characters/");
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFile(search_path, &fd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		int y = 0;
		do
		{
			// read all (real) files in current folder, delete '!' read other 2 default folder . and ..
			if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				
				const std::string name = std::string(fd.cFileName).substr(0, strlen(fd.cFileName) - 4);
				Button* b = (new Button(name, &Renderer::FONT_ROBOTO, 0, y, 0, 0))->adjustButtonDimensions();
				b->addOnClick_callback([this, name](Component*, int, int)
				{
					for(std::function<void(std::string name)> f: onCharacterClick_callback)
					{
						f(name);
					}
				});
				b->setPadding(0);
				y += fontSize+10;
				addComponent(b);
 				names.push_back(std::string("characters") + fd.cFileName);
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}


}

void CharacterSelect::addOnCharacterClick_callback(std::function<void(std::string name)> func)
{
	onCharacterClick_callback.push_back(func);
}


