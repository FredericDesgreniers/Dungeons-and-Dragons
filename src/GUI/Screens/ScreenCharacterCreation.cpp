#include "ScreenCharacterCreation.h"
#include "screenMain.h"
#include "../Components/TextField.h"
#include "../Renderer.h"
#include "../../dice.h"
#include <string>

ScreenCharacterCreation::ScreenCharacterCreation(Game* game) : Screen(game)
{
	strength = "     -", constitution = "     -", dexterity = "     -", intelligence = "     -", wisdom = "     -", charisma = "     -";
	TextField* nameInput = new TextField("Test", 250, 100, 100, 20);
	nameInput->setFontSize(15);

	Button* rollBtn = new Button("Roll!", &Renderer::FONT_ROBOTO, 400, 300, 100, 30);
	rollBtn->adjustButtonDimensions();

	Button* backBtn = new Button("Back", &Renderer::FONT_ROBOTO, 100, 600, 100, 30);
	backBtn->adjustButtonDimensions();


	

	backBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		Screen* screen = this->game->getGuiManager()->setScreen(new ScreenMain(this->game));
		Renderer::addVoidScreen(screen);
		std::cout << "Back to main menu!" << std::endl;
	});

	rollBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		setStrength(rollStat());
		setConstitution(rollStat());
		setDexterity(rollStat());
		setIntelligence(rollStat());
		setWisdom(rollStat());
		setCharisma(rollStat());
		std::cout << "Rolling stats!" << std::endl;
	});


	addComponent(backBtn);
	addComponent(rollBtn);
	addComponent(nameInput);
}

void ScreenCharacterCreation::render()
{

	Renderer::drawString("Character Editor", Renderer::FONT_ROBOTO.get(24), 250, 0, 1, { 255,255,255,255 });

	Renderer::drawString("Name", Renderer::FONT_ROBOTO.get(16), 100, 100, 1, { 255,255,255,255 });
	Renderer::drawString("Some Guy", Renderer::FONT_ROBOTO.get(16), 250, 100, 1, { 255,255,255,255 });

	Renderer::drawString("Race", Renderer::FONT_ROBOTO.get(16), 100, 125, 1, { 255,255,255,255 });
	Renderer::drawString("Human", Renderer::FONT_ROBOTO.get(16), 250, 125, 1, { 255,255,255,255 });

	Renderer::drawString("Class", Renderer::FONT_ROBOTO.get(16), 100, 150, 1, { 255,255,255,255 });
	Renderer::drawString("Warrior", Renderer::FONT_ROBOTO.get(16), 250, 150, 1, { 255,255,255,255 });

	Renderer::drawString("Strength", Renderer::FONT_ROBOTO.get(16), 100, 175, 1, { 255,255,255,255 });
	Renderer::drawString(strength, Renderer::FONT_ROBOTO.get(16), 250, 175, 1, { 255,255,255,255 });

	Renderer::drawString("Constitution", Renderer::FONT_ROBOTO.get(16), 100, 200, 1, { 255,255,255,255 });
	Renderer::drawString(constitution, Renderer::FONT_ROBOTO.get(16), 250, 200, 1, { 255,255,255,255 });

	Renderer::drawString("Dexterity", Renderer::FONT_ROBOTO.get(16), 100, 225, 1, { 255,255,255,255 });
	Renderer::drawString(dexterity, Renderer::FONT_ROBOTO.get(16), 250, 225, 1, { 255,255,255,255 });

	Renderer::drawString("Intelligence", Renderer::FONT_ROBOTO.get(16), 100, 250, 1, { 255,255,255,255 });
	Renderer::drawString(intelligence, Renderer::FONT_ROBOTO.get(16), 250, 250, 1, { 255,255,255,255 });

	Renderer::drawString("Wisdom", Renderer::FONT_ROBOTO.get(16), 100, 275, 1, { 255,255,255,255 });
	Renderer::drawString(wisdom, Renderer::FONT_ROBOTO.get(16), 250, 275, 1, { 255,255,255,255 });

	Renderer::drawString("Charisma", Renderer::FONT_ROBOTO.get(16), 100, 300, 1, { 255,255,255,255 });
	Renderer::drawString(charisma, Renderer::FONT_ROBOTO.get(16), 250, 300, 1, { 255,255,255,255 });

	Screen::render();
}

string ScreenCharacterCreation::rollStat() {
	int rolls[4] = { 0,0,0,0 };
	int sum = 0;
	sum += rolls[0] = Dice::roll("1d6");
	sum += rolls[1] = Dice::roll("1d6");
	sum += rolls[2] = Dice::roll("1d6");
	sum += rolls[3] = Dice::roll("1d6");
	int smallest = rolls[0];
	for (int i = 1; i < 4; i++) {
		if (rolls[i] < smallest)
			smallest = rolls[i];
	}
	sum -= smallest;

	ostringstream StrStream;
	StrStream << sum;
	return StrStream.str();
}

void ScreenCharacterCreation::setStrength(std::string value) {
	strength = value;
}

void ScreenCharacterCreation::setConstitution(std::string value) {
	constitution = value;
}

void ScreenCharacterCreation::setDexterity(std::string value) {
	dexterity = value;
}

void ScreenCharacterCreation::setIntelligence(std::string value) {
	intelligence = value;
}

void ScreenCharacterCreation::setWisdom(std::string value) {
	wisdom = value;
}

void ScreenCharacterCreation::setCharisma(std::string value) {
	charisma = value;
}

