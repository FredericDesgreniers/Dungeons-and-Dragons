#include "ScreenCharacterCreation.h"


ScreenCharacterCreation::ScreenCharacterCreation(Game* game) : Screen(game)
{
	character = new Character(1);

	for (int i = 0; i < 7; i++) {
		abilityScores[i] = "0";
	}
	nameInput = new TextField("Test", 125, 100, 150, 25);
	nameInput->setFontSize(20);
	int i = 220;

	Button* rollBtn = new Button("Roll!", &Renderer::FONT_ROBOTO, 105, i+260, 1, 1);
	rollBtn->setFontSize(30);
	rollBtn->adjustButtonDimensions();

	Button* backBtn = new Button("Back", &Renderer::FONT_ROBOTO, 100, 600, 1, 1);
	backBtn->setFontSize(30);
	backBtn->adjustButtonDimensions();

	Button* confirmBtn = new Button("Save Character", &Renderer::FONT_ROBOTO, 300, 600, 100, 30);
	confirmBtn->setFontSize(25);
	confirmBtn->adjustButtonDimensions();


	Button* loadBtn = new Button("Load Test.chr", &Renderer::FONT_ROBOTO, 500, 600, 100, 30);
	loadBtn->setFontSize(25);
	loadBtn->adjustButtonDimensions();


	Button* strPlus = new Button("+", &Renderer::FONT_ROBOTO, 220, i, 1, 1);
	strPlus->setFontSize(20)->setBackgroundColor_both(203, 203, 203, 100);
	strPlus->setFontColor(0, 0, 0, 100);
	strPlus->setBorderColor_hover(51, 153, 255, 100);
	strPlus->setBorderSize(3);
	strPlus->setBorderSize_hover(3);
	strPlus->setFontUnderline_both(0);
	strPlus->setPadding(1);
	strPlus->adjustButtonDimensions();
	strPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(0);
		
	});


	Button* strMinus = new Button("-", &Renderer::FONT_ROBOTO, 240, i, 1, 1);
	copyStyle(*strPlus, *strMinus);
	copySize(*strPlus, *strMinus);
	strMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(0);

	});

	Button* dexPlus = new Button("+", &Renderer::FONT_ROBOTO, 220, i+35, 1, 1);
	dexPlus->setFontSize(20)->setBackgroundColor_both(203, 203, 203, 100);
	dexPlus->setFontColor(0, 0, 0, 100);
	dexPlus->setBorderColor_hover(51, 153, 255, 100);
	dexPlus->setBorderSize(3);
	dexPlus->setBorderSize_hover(3);
	dexPlus->setFontUnderline_both(0);
	dexPlus->setPadding(1);
	dexPlus->adjustButtonDimensions();
	dexPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(1);

	});

	Button* dexMinus = new Button("-", &Renderer::FONT_ROBOTO, 240, i+35, 1, 1);
	copyStyle(*strPlus, *dexMinus);
	copySize(*strPlus, *dexMinus);
	dexMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(1);

	});

	Button* conPlus = new Button("+", &Renderer::FONT_ROBOTO, 220, i + 70, 1, 1);
	copyStyle(*strPlus, *conPlus);
	copySize(*strPlus, *conPlus);
	conPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(2);

	});

	Button* conMinus = new Button("-", &Renderer::FONT_ROBOTO, 240, i + 70, 1, 1);
	copyStyle(*strPlus, *conMinus);
	copySize(*strPlus, *conMinus);
	conMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(2);

	});

	Button* intPlus = new Button("+", &Renderer::FONT_ROBOTO, 220, i + 105, 1, 1);
	copyStyle(*strPlus, *intPlus);
	copySize(*strPlus, *intPlus);
	intPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(3);

	});

	Button* intMinus = new Button("-", &Renderer::FONT_ROBOTO, 240, i + 105, 1, 1);
	copyStyle(*strPlus, *intMinus);
	copySize(*strPlus, *intMinus);
	intMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(3);

	});

	Button* wisPlus = new Button("+", &Renderer::FONT_ROBOTO, 220, i + 140, 1, 1);
	copyStyle(*strPlus, *wisPlus);
	copySize(*strPlus, *wisPlus);
	wisPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(4);

	});

	Button* wisMinus = new Button("-", &Renderer::FONT_ROBOTO, 240, i + 140, 1, 1);
	copyStyle(*strPlus, *wisMinus);
	copySize(*strPlus, *wisMinus);
	wisMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(4);

	});

	Button* chaPlus = new Button("+", &Renderer::FONT_ROBOTO, 220, i + 175, 1, 1);
	copyStyle(*strPlus, *chaPlus);
	copySize(*strPlus, *chaPlus);
	chaPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(5);

	});

	Button* chaMinus = new Button("-", &Renderer::FONT_ROBOTO, 240, i + 175, 1, 1);
	copyStyle(*strPlus, *chaMinus);
	copySize(*strPlus, *chaMinus);
	chaMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(5);

	});


	addComponent((new Label("Race", &Renderer::FONT_ROBOTO, 20, 135, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Human", &Renderer::FONT_ROBOTO, 140, 135, 1, 1))->setFontSize(20)->adjustDimensions());

	addComponent((new Label("Class", &Renderer::FONT_ROBOTO, 20, 170, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Warrior", &Renderer::FONT_ROBOTO, 140, 170, 1, 1))->setFontSize(20)->adjustDimensions());

	addComponent((new Label("Strength", &Renderer::FONT_ROBOTO, 20, i, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Dexterity", &Renderer::FONT_ROBOTO, 20, i+35, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Constitution", &Renderer::FONT_ROBOTO, 20, i+70, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Intelligence", &Renderer::FONT_ROBOTO, 20, i+105, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Wisdom", &Renderer::FONT_ROBOTO, 20, i+140, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Charisma", &Renderer::FONT_ROBOTO, 20, i+175, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Remaining", &Renderer::FONT_ROBOTO, 20, i+210, 1, 1))->setFontSize(20)->adjustDimensions());
	
	EquipedItemComponent* eiComp = new EquipedItemComponent(character->getEquippedItems(), 350, 100, 100, 100);
	eiComp->setBorderColor_both(150, 150, 140, 255);
	eiComp->setBorderSize(1);
	eiComp->setPadding(10, 10, 10, 10);


	backBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		Screen* screen = this->game->getGuiManager()->setScreen(new ScreenMain(this->game));
		Renderer::addVoidScreen(screen);
		std::cout << "Back to main menu!" << std::endl;
	});

	rollBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		rollCharacter();
	});

	confirmBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{	
		if (abilityScores[0] == "0") {
			std::cout << "Cannot instantiate character: press roll" << std::endl;
		}

		else if ((stoi(abilityScores[6]) > 0)) {
			std::cout << "Cannot instantiate character: points not spent" << std::endl;
		}

		else if (nameInput->getText() == "") {
			std::cout << "Cannot instantiate character: enter a name" << std::endl;
		}

		else {
			std::cout << "Character Instantiated:" << std::endl;
			createCharacter();
		}
	});

	//This is a temporary button to test loading functionality.
	loadBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		Character* temp;
		if (temp=Character::loadCharacter("Test")) {
			int* loadAbilities = temp->getAbilityScoreArray();
			setStrength(to_string(loadAbilities[0]));
			setDexterity(to_string(loadAbilities[1]));
			setConstitution(to_string(loadAbilities[2]));
			setIntelligence(to_string(loadAbilities[3]));
			setWisdom(to_string(loadAbilities[4]));
			setCharisma(to_string(loadAbilities[5]));
			nameInput->setText(temp->getName());
			setRemaining("0");
			
			character = temp;
			
		}
		else {
			std::cout << "Load Failed" << endl;
		}
		temp = nullptr;
		character->outputEquipped();
	});


	addComponent(backBtn);
	addComponent(rollBtn);
	addComponent(strPlus);
	addComponent(strMinus);
	addComponent(dexPlus);
	addComponent(dexMinus);
	addComponent(conPlus);
	addComponent(conMinus);
	addComponent(intPlus);
	addComponent(intMinus);
	addComponent(wisPlus);
	addComponent(wisMinus);
	addComponent(chaPlus);
	addComponent(chaMinus);
	addComponent(nameInput);
	addComponent(confirmBtn);
	addComponent(loadBtn);
	addComponent(eiComp);
}

void ScreenCharacterCreation::render()
{

	Renderer::drawString("Character Editor", Renderer::FONT_ROBOTO.get(24), 250, 0, 1, { 255,255,255,255 });

	Renderer::drawString("Name", Renderer::FONT_ROBOTO.get(20), 20, 100, 1, { 255,255,255,255 });

	



	Renderer::drawString(abilityScores[0], Renderer::FONT_ROBOTO.get(20), 175, 220, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[1], Renderer::FONT_ROBOTO.get(20), 175, 255, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[2], Renderer::FONT_ROBOTO.get(20), 175, 290, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[3], Renderer::FONT_ROBOTO.get(20), 175, 325, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[4], Renderer::FONT_ROBOTO.get(20), 175, 360, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[5], Renderer::FONT_ROBOTO.get(20), 175, 395, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[6], Renderer::FONT_ROBOTO.get(20), 175, 430, 1, { 255,255,255,255 });

	Screen::render();
}


void ScreenCharacterCreation::increment(int stat) {

	if ((abilityScores[stat] == "18") || (abilityScores[6]=="0")) {
		std::cout << "Stat Increment failed" << endl;
		return;
	}
	string test = to_string(6);
	switch (stat) {
	case 0:
		setRemaining(to_string((stoi(abilityScores[6])) - 1));
		setStrength(to_string((stoi(abilityScores[0])) + 1));
		break;

	case 1:
		setRemaining(to_string((stoi(abilityScores[6])) - 1));
		setDexterity(to_string((stoi(abilityScores[1])) + 1));
		break;

	case 2:
		
		setRemaining(to_string((stoi(abilityScores[6])) - 1));
		setConstitution(to_string((stoi(abilityScores[2])) + 1));
		break;

	case 3:
		setRemaining(to_string(stoi(abilityScores[6]) - 1));
		setIntelligence(to_string(stoi(abilityScores[3]) + 1));
		break;
	case 4:
		
		setRemaining(to_string(stoi(abilityScores[6]) - 1));
		setWisdom(to_string(stoi(abilityScores[4]) + 1));
		break;

	case 5:
		setRemaining(to_string(stoi(abilityScores[6]) - 1));
		setCharisma(to_string(stoi(abilityScores[5]) + 1));
		break;

	default:
		break;
	}

}


void ScreenCharacterCreation::decrement(int stat) {
	if (stoi(abilityScores[stat]) <= 3) {
		std::cout << "Stat Decrement failed" << endl;
		return;
	}

	switch (stat) {
	case 0:
		setRemaining(to_string(stoi(abilityScores[6]) + 1));
		setStrength(to_string(stoi(abilityScores[0]) - 1));
		break;
	case 1:
		setRemaining(to_string(stoi(abilityScores[6]) + 1));
		setDexterity(to_string(stoi(abilityScores[1]) - 1));
		break;

	case 2:
		setRemaining(to_string(stoi(abilityScores[6]) + 1));
		setConstitution(to_string(stoi(abilityScores[2]) - 1));
		break;

	case 3:
		setRemaining(to_string(stoi(abilityScores[6]) + 1));
		setIntelligence(to_string(stoi(abilityScores[3]) - 1));
		break;

	 case 4:
		setRemaining(to_string(stoi(abilityScores[6]) + 1));
		setWisdom(to_string(stoi(abilityScores[4]) - 1));
		break;
	

	 case 5:
		setRemaining(to_string(stoi(abilityScores[6]) + 1));
		setCharisma(to_string(stoi(abilityScores[5]) - 1));
		break;
	default:
		break;
	}

}

void ScreenCharacterCreation::rollCharacter() {
	std::cout << "Rolling stats!" << std::endl;


	setStrength(to_string(Dice::rollStat()));
	setConstitution(to_string(Dice::rollStat()));
	setDexterity(to_string(Dice::rollStat()));
	setIntelligence(to_string(Dice::rollStat()));
	setWisdom(to_string(Dice::rollStat()));
	setCharisma(to_string(Dice::rollStat()));
	setRemaining("0");

	//std::cout << "Adding test equipment:" << endl;
	//character->equip(new Item("Belt of Strength+3", Item::ItemType::BELT, 3, 0, 0, 0, 0, 0, 0, 0, 0));
	//character->equip(new Item("Helm of Smartmaking+4", Item::ItemType::HELMET, 0, 0, 0, 4, 0, 0, 0, 0, 0));
	//character->equip(new Item("Armor of Armorclass+5", Item::ItemType::ARMOR, 0, 0, 0, 0, 0, 0, 0, 0, 5));
	///character->equip(new Item("Shield of No-effect-whatsoever", Item::ItemType::SHIELD, 0, 0, 0, 0, 0, 0, 0, 0, 0));
	//character->equip(new Item("Ring of Smoothtalking +2", Item::ItemType::RING, 0, 0, 0, 0, 0, 2, 0, 0, 0));
	//character->equip(new Item("Boots of Dexterity+1", Item::ItemType::BOOTS, 0, 1, 0, 0, 0, 0, 0, 0, 0));
	//character->equip(new Item("Sword of Attack+1", Item::ItemType::WEAPON, 0, 0, 0, 0, 0, 0, 1, 1, 0));

}

void ScreenCharacterCreation::setStrength(std::string value) {
	abilityScores[0] = value;
}

void ScreenCharacterCreation::setDexterity(std::string value) {
	abilityScores[1] = value;
}

void ScreenCharacterCreation::setConstitution(std::string value) {
	abilityScores[2] = value;
}

void ScreenCharacterCreation::setIntelligence(std::string value) {
	abilityScores[3] = value;
}

void ScreenCharacterCreation::setWisdom(std::string value) {
	abilityScores[4] = value;
}

void ScreenCharacterCreation::setCharisma(std::string value) {
	abilityScores[5] = value;
}


void ScreenCharacterCreation::setRemaining(std::string value) {
	abilityScores[6] = value;
}

void ScreenCharacterCreation::createCharacter() {

	character->setLevel(1);
	character->setStrength(stoi(abilityScores[0]));
	character->setDexterity(stoi(abilityScores[1]));
	character->setConstitution(stoi(abilityScores[2]));
	character->setIntelligence(stoi(abilityScores[3]));
	character->setWisdom(stoi(abilityScores[4]));
	character->setCharisma(stoi(abilityScores[5]));
	character->setName(nameInput->getText());
	std::cout << character->toString() << endl;

	character->equip(new Item("Belt of Strength+3", Item::ItemType::BELT, 3, 0, 0, 0, 0, 0, 0, 0, 0));
	Character::saveCharacter(nameInput->getText(), character);



	//Item::saveItem("Belt of Testing", new Item("Belt of Testing", Item::ItemType::BELT, 3, 0, 0, 0, 0, 0, 0, 0, 0));
	//Item::loadItem("Belt of Testing");

	std::cout << character->toString() << endl;
}

ScreenCharacterCreation::~ScreenCharacterCreation() {
	delete character;
}