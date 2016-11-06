#pragma once
#include "Screen.h"
#include "screenMain.h"
#include "../../map.h"
#include "../../MapBuilder.h"
#include <sstream>
#include "../Components/TextField.h"
#include "../Renderer.h"
#include "../../dice.h"
#include "../Components/MapComponent.h"
#include <string>

class ScreenMapCreation : public Screen
{

private:

	Map* map;
	Map* tileMap;
	Map* entityMap;
	MapComponent* mapComp;
	MapComponent* tileMapComp;
	MapComponent* entityMapComp;
	TextField* nameInput;

	MapTile* storedTile;
	Entity* storedEntity;

	int height;
	int width;

public:

	ScreenMapCreation(Game* game);

	void render() override;
	void createMap();
	void saveMap();
	bool validateMap();

	void setHeight(int value);
	void setWidth(int value);

};
