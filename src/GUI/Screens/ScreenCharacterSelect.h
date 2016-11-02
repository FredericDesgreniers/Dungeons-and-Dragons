#pragma once
#include "Screen.h"
#include "../../Campaign.h"

class ScreenCharacterSelect:public Screen
{
public:
	ScreenCharacterSelect(Game* game, Campaign* campaign);

	void render() override;

private:
	Campaign* campaign;
};
