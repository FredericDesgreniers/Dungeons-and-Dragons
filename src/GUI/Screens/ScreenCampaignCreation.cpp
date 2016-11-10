#include "ScreenCampaignCreation.h"
#include "../Components/MapSelect.h"
#include "../Renderer.h"
#include "../Components/TextField.h"

ScreenCampaignCreation::ScreenCampaignCreation(Game* game):Screen(game)
{
	campaign = new Campaign("temp", std::vector<Map*>());

	int wx, wy;
	SDL_GetWindowSize(Renderer::window, &wx, &wy);

	TextField* nameField = new TextField("Campaign1", wx / 2, 5, wx / 2 - 50, 30);
	nameField->setFontSize(20);
	addComponent(nameField);

	campaignPreview = new MapSelect(campaign->getMaps(), (wx / 2 - 100 + 150), 50, wx / 2 - 100, wy - 100);

	campaignPreview->setBackgroundColor_both(50, 50, 50, 255);
	campaignPreview->setPadding(10, 10, 10, 10);
	campaignPreview->setBorderColor_both(150, 150, 150, 255);
	campaignPreview->setBorderSize(1);
	addComponent(campaignPreview);
	campaignPreview->addOnMapClick_callback([this](Map* map)
	{
		campaign->removeMap(map);
		campaignPreview->loadMaps(campaign->getMaps());
	});

	MapSelect* mapSelect = new MapSelect(50, 50, wx / 2 - 100, wy - 100);
	mapSelect->setBackgroundColor_both(50, 50, 50, 255);
	mapSelect->setPadding(10, 10, 10, 10);
	mapSelect->setBorderColor_both(150, 150, 150, 255);
	mapSelect->setBorderSize(1);
	addComponent(mapSelect);
	mapSelect->addOnMapClick_callback([this](Map* map)
	{
		campaign->addMap(map);
		campaignPreview->loadMaps(campaign->getMaps());
	});
	
	Button* saveButton = new Button("Save", &Renderer::FONT_ROBOTO, 100, wy - 45, 100, 30);
	saveButton->adjustButtonDimensions();
	addComponent(saveButton);
	saveButton->addOnClick_callback([this](Component* comp, int x, int y)
	{
		for each (Map* map in campaign->getMaps())
		{
			cout << map->getName() << endl;
		}
	});
}

ScreenCampaignCreation::saveCampaign()
{
	std::ofstream mapFile("maps/" + fileName + ".dnd");

	if (mapFile.is_open())
	{
		int width = map->getWidth();
		int height = map->getHeight();
		string name = fileName;

		mapFile << name << std::endl;
		mapFile << width << std::endl;
		mapFile << height << std::endl;

		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				int type = map->getTile(x, y)->getId();

				switch (type)
				{
				case 0:
					mapFile << '-';
					break;
				case 1:
					mapFile << 'W';
					break;
				case 2:
					mapFile << 'S';
					break;
				case 3:
					mapFile << 'E';
					break;
				default:
					mapFile << ' ';
					break;
				}

				Entity* entity = map->getEntity(x, y);

				if (entity != nullptr)
				{
					mapFile << entity->getRenderChar();
				}
				else
				{
					mapFile << '\'';
				}
			}
			mapFile << std::endl;
		}
		builder->map = map;
		mapFile.flush();
		mapFile.close();
	}
}

ScreenCampaignCreation::loadCampaign()
{

}
