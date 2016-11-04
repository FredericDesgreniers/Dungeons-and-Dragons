#pragma once
#include "Screen.h"
#include "screenMain.h"
#include "../../map.h"
#include "../../MapBuilder.h"
#include <sstream>
#include "../Components/TextField.h"
#include "../Renderer.h"
#include "../../dice.h"
#include <string>

class ScreenMapCreation : public Screen
{

private:

	Map* map;
	TextField* nameInput;

	int height;
	int width;

public:

	ScreenMapCreation(Game* game);

	void render() override;
	void createMap();

	void setHeight(int value);
	void setWidth(int value);

};
