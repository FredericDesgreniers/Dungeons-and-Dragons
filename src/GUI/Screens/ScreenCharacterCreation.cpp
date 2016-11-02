#include "ScreenCharacterCreation.h"
#include "screenMain.h"
#include "../Components/TextField.h"
#include "../Renderer.h"

ScreenCharacterCreation::ScreenCharacterCreation(Game* game) : Screen(game)
{
	strength = "-", constitution = "-", dexterity = "-", intelligence = "-", wisdom = "-", charisma = "-";
	TextField* nameInput = new TextField("Test", 250, 100, 100, 20);
	nameInput->setFontSize(15);

	Button* rollBtn = new Button("Roll!", &Renderer::FONT_ROBOTO, 100, 600, 100, 30);

	Button* backBtn = new Button("Back", &Renderer::FONT_ROBOTO, 100, 600, 100, 30);


	backBtn->adjustButtonDimensions();

	backBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		Screen* screen = this->game->getGuiManager()->setScreen(new ScreenMain(this->game));
		Renderer::addVoidScreen(screen);
		std::cout << "Back to main menu!" << std::endl;
	});


	addComponent(backBtn);
	addComponent(nameInput);
}

void ScreenCharacterCreation::render()
{

	Renderer::drawString("Character Editor", Renderer::FONT_ROBOTO.get(24), 250, 0, 1, { 100,100,100,255 });

	Renderer::drawString("Name", Renderer::FONT_ROBOTO.get(16), 100, 100, 1, { 100,100,100,255 });
	Renderer::drawString("Some Guy", Renderer::FONT_ROBOTO.get(16), 250, 100, 1, { 100,100,100,255 });

	Renderer::drawString("Race", Renderer::FONT_ROBOTO.get(16), 100, 125, 1, { 100,100,100,255 });
	Renderer::drawString("Human", Renderer::FONT_ROBOTO.get(16), 250, 125, 1, { 100,100,100,255 });

	Renderer::drawString("Class", Renderer::FONT_ROBOTO.get(16), 100, 150, 1, { 100,100,100,255 });
	Renderer::drawString("Warrior", Renderer::FONT_ROBOTO.get(16), 250, 150, 1, { 100,100,100,255 });

	Renderer::drawString("Strength", Renderer::FONT_ROBOTO.get(16), 100, 175, 1, { 100,100,100,255 });
	Renderer::drawString(strength, Renderer::FONT_ROBOTO.get(16), 250, 175, 1, { 100,100,100,255 });

	Renderer::drawString("Constitution", Renderer::FONT_ROBOTO.get(16), 100, 200, 1, { 100,100,100,255 });
	Renderer::drawString(constitution, Renderer::FONT_ROBOTO.get(16), 250, 200, 1, { 100,100,100,255 });

	Renderer::drawString("Dexterity", Renderer::FONT_ROBOTO.get(16), 100, 225, 1, { 100,100,100,255 });
	Renderer::drawString(dexterity, Renderer::FONT_ROBOTO.get(16), 250, 225, 1, { 100,100,100,255 });

	Renderer::drawString("Intelligence", Renderer::FONT_ROBOTO.get(16), 100, 250, 1, { 100,100,100,255 });
	Renderer::drawString(intelligence, Renderer::FONT_ROBOTO.get(16), 250, 250, 1, { 100,100,100,255 });

	Renderer::drawString("Wisdom", Renderer::FONT_ROBOTO.get(16), 100, 275, 1, { 100,100,100,255 });
	Renderer::drawString(wisdom, Renderer::FONT_ROBOTO.get(16), 250, 275, 1, { 100,100,100,255 });

	Renderer::drawString("Charisma", Renderer::FONT_ROBOTO.get(16), 100, 300, 1, { 100,100,100,255 });
	Renderer::drawString(charisma, Renderer::FONT_ROBOTO.get(16), 250, 300, 1, { 100,100,100,255 });

	Screen::render();
}


