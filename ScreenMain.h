#pragma once
#include "Screen.h"

class ScreenMain : public Screen
{
public:
	ScreenMain();

	void onButtonClicked(Button* b) override;
};
