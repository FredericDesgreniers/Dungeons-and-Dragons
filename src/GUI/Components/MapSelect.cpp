#include "MapSelect.h"
#include <Windows.h>
#include <fileapi.h>

MapSelect::MapSelect(int x, int y, int width, int height) :Pane(x, y, width, height), previousMap(MapBuilder::createEmptyMap(10, 10)->get(), 100, 0,300,200), currentMap(MapBuilder::createEmptyMap(10, 10)->get(), 100, 220, 300, 200), nextMap(MapBuilder::createEmptyMap(10, 10)->get(), 100, 440, 300, 200)
{
	
	previousMap.setVisible(false);



	char search_path[200];
	sprintf_s(search_path, "%s*.*", "maps/");
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
				
				maps.push_back(MapBuilder::loadFromFile(name)->get());

				y += fontSize + 10;

			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}

	addComponent(&previousMap);
	addComponent(&currentMap);
	addComponent(&nextMap);

	previousMap.addOnClick_callback([this](Component*,int,int)
	{
		if(this->mapIndex>0)
		{
			this->mapIndex--;
			setMaps();
		}
	});
	currentMap.addOnClick_callback([this](Component*, int, int)
	{
		if (this->mapIndex>0)
		{
			//TODO add map to campaign
		}
	});
	nextMap.addOnClick_callback([this](Component*, int, int)
	{
		if (this->mapIndex<maps.size()-1)
		{
			this->mapIndex++;
			setMaps();
		}
	});
		setMaps();

}
void MapSelect::setMaps()
{
	currentMap.setMap(maps[mapIndex]);
	if(mapIndex>0)
	{
		previousMap.setMap(maps[mapIndex-1]);
		previousMap.setVisible(true);
	}else
	{
		previousMap.setVisible(false);
	}
	if (mapIndex<maps.size()-1)
	{
		nextMap.setMap(maps[mapIndex + 1]);
		nextMap.setVisible(true);
	}else
	{
		nextMap.setVisible(false);
	}
}
