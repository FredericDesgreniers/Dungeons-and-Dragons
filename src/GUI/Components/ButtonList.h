#pragma once
#include "Pane.h"
#include "Button.h"
#include "../Renderer.h"
#include "../Screens/ScreenCampaignCreation.h"
#include "../Screens/ScreenCharacterSelect.h"

class ButtonList:public Pane{
	public:
		ButtonList(int x, int y, int width, int height);
		void setButtons();
		void loadButtons();
		virtual void render();

		int getButtonIndex() { return buttonIndex; }
		Button* getCurrentButton() { return currentButton; }
private:
	std::vector<std::string> buttons;
	Button* previousButton;
	Button* currentButton;
	Button* nextButton;

	int buttonIndex = 0;
};
