#include "ButtonList.h"
#include <Windows.h>
#include <fileapi.h>

ButtonList::ButtonList(int x, int y, int width, int height) :Pane(x, y, width, height)
{
	previousButton = new Button("none", &Renderer::FONT_ROBOTO, 0, 0, width, (height/3)-10);
	currentButton = new Button("none", &Renderer::FONT_ROBOTO, 0, height/3, width, (height / 3)-10);
	nextButton = new Button("none", &Renderer::FONT_ROBOTO, 0, height / 3 * 2,width , (height / 3)-10);

	currentButton->setBorderColor(200, 0, 0, 255);
	currentButton->setBorderColor_hover(255, 0, 0, 255);

	currentButton->setBorderSize(3);

	previousButton->setVisible(false);


	loadButtons();
	

	addComponent(previousButton);
	addComponent(currentButton);
	addComponent(nextButton);

	previousButton->addOnClick_callback([this](Component*,int,int)
	{
		if(this->buttonIndex>0)
		{
			this->buttonIndex--;
			setButtons();
		}
	});
	currentButton->addOnClick_callback([this](Component*, int, int)
	{
		//Campaign* campaign = Campaign::loadCampaign(buttons[getButtonIndex()]);

	});
	nextButton->addOnClick_callback([this](Component*, int, int)
	{
		if (this->buttonIndex<buttons.size()-1)
		{
			this->buttonIndex++;
			setButtons();
		}
	});
	setButtons();

}

void ButtonList::setButtons()
{
	int rSize = buttons.size() - 1;
	if (buttonIndex < buttons.size()) {
		currentButton->setText(buttons[buttonIndex]);
		currentButton->setVisible(true);
	}
	else
	{
		currentButton->setVisible(false);
	}
	if(buttonIndex>0)
	{
		previousButton->setText(buttons[buttonIndex -1]);
		previousButton->setVisible(true);
	}else
	{
		previousButton->setVisible(false);
	}
	if (buttonIndex<rSize)
	{
		nextButton->setText(buttons[buttonIndex + 1]);
		nextButton->setVisible(true);
	}else
	{
		nextButton->setVisible(false);
	}
}

void ButtonList::render()
{
	drawDefaultStyle();
	Pane::render();
}

void ButtonList::loadButtons()
{
	buttons.clear();
	char search_path[200];
	sprintf_s(search_path, "%s*.*", "campaigns/");
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
				buttons.push_back(name);
				y += fontSize + 10;
			}
		} while (::FindNextFile(hFind, &fd));
		::FindClose(hFind);
	}

	setButtons();
}