#pragma once
#include "Pane.h"
#include "Button.h"
#include "../Renderer.h"
#include "../Screens/ScreenCampaignCreation.h"
#include "../Screens/ScreenCharacterSelect.h"
/**
 * \brief Pane with a lsit of clickable and nvigatable buttons
 * 3 buttons are shown at a time.
 */
class ButtonList:public Pane{
	public:
	/**
	 * Button list constructor. Give position and dimensions
	 */
		ButtonList(int x, int y, int width, int height);
	/**
	 * Set buttons in list
	 */
		void setButtons();
	/**
	 * Load buttons to list
	 */
		void loadButtons();
	/**
	 * override render method
	 */
		void render() override;
		/**
		 * get current button index
		 */
		int getButtonIndex() { return buttonIndex; }
	/**
	 * Get current center button
	 */
		Button* getCurrentButton() { return currentButton; }
private:
	/**
	 * Button list
	 */
	std::vector<std::string> buttons;
	/**
	 * previous button
	 */
	Button* previousButton;
	/**
	 * Current button
	 */
	Button* currentButton;
	/**
	 * Next button
	 */
	Button* nextButton;
	/**
	 * current center button index
	 */
	int buttonIndex = 0;
};
