#include "ScreenCharacterCreation.h"


ScreenCharacterCreation::ScreenCharacterCreation(Game* game) : Screen(game)
{

	// Set all ability score strings to 0 until character is rolled
	for (int i = 0; i < 7; i++) {
		abilityScores[i] = "0";
	}
	// Instantiate character and register screen as observer
	character = new LivingEntity('c', 1, 1, 1, 1, 1, 1, 1);
	character->Attach(this);

	//Text field for name entry
	nameInput = new TextField("Artemis", 125, 65, 150, 25);
	nameInput->setFontSize(20);
	int i = 220;
	addComponent(nameInput);

	// Button to reroll character
	Button* rollBtn = new Button("Roll!", &Renderer::FONT_ROBOTO, 105, i+260, 1, 1);
	rollBtn->setFontSize(30);
	rollBtn->adjustButtonDimensions();
	rollBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		rollCharacter();
	});
	addComponent(rollBtn);

	// Button to save character to file
	Button* confirmBtn = new Button("Save Character", &Renderer::FONT_ROBOTO, 300, 600, 100, 30);
	confirmBtn->setFontSize(25);
	confirmBtn->adjustButtonDimensions();
	confirmBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		saveCharacter();
	});
	addComponent(confirmBtn);

	// Button to load character "Test.chr". For testing loading characters into editor
	Button* loadBtn = new Button("Load By Name", &Renderer::FONT_ROBOTO, 500, 600, 100, 30);
	loadBtn->setFontSize(25);
	loadBtn->adjustButtonDimensions();
	loadBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
		loadCharacter();
	});
	addComponent(loadBtn);

	// Create stat allocation buttons
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
	copyStyle(*strPlus, *dexPlus);
	copySize(*strPlus, *dexPlus);
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



	// Add labels for Character traits
	addComponent((new Label("Character Editor", &Renderer::FONT_ROBOTO,250, 0, 1, 1))->setFontSize(24)->adjustDimensions());
	addComponent((new Label("Name", &Renderer::FONT_ROBOTO, 20, 65, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Level", &Renderer::FONT_ROBOTO, 20, 100, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Race", &Renderer::FONT_ROBOTO, 20, 135, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Class", &Renderer::FONT_ROBOTO, 20, 170, 1, 1))->setFontSize(20)->adjustDimensions());

	// This is where race selection will occur if it is added in the future 
	addComponent((new Label("Human", &Renderer::FONT_ROBOTO, 140, 135, 1, 1))->setFontSize(20)->adjustDimensions());

	// This is where class selection will occur if it is added in the future
	addComponent((new Label("Warrior", &Renderer::FONT_ROBOTO, 140, 170, 1, 1))->setFontSize(20)->adjustDimensions());

	//Labels for ability scores and mods
	addComponent((new Label("Mod", &Renderer::FONT_ROBOTO, 267, 190, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Strength", &Renderer::FONT_ROBOTO, 20, i, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Dexterity", &Renderer::FONT_ROBOTO, 20, i+35, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Constitution", &Renderer::FONT_ROBOTO, 20, i+70, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Intelligence", &Renderer::FONT_ROBOTO, 20, i+105, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Wisdom", &Renderer::FONT_ROBOTO, 20, i+140, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Charisma", &Renderer::FONT_ROBOTO, 20, i+175, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Remaining", &Renderer::FONT_ROBOTO, 20, i+210, 1, 1))->setFontSize(20)->adjustDimensions());
	
	addComponent((new Label("Hit Points: ", &Renderer::FONT_ROBOTO, 350, 360, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Attacks Per Round: ", &Renderer::FONT_ROBOTO, 350, 395, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Attack Bonus: ", &Renderer::FONT_ROBOTO, 350, 430, 1, 1))->setFontSize(20)->adjustDimensions());


	//Inventory Display component
	eiComp = new EquipedItemComponent(character->getEquippedItems(), 350, 100, 200, 100);
	eiComp->setBorderColor_both(150, 150, 140, 255);
	eiComp->setBorderSize(1);
	eiComp->setPadding(10, 10, 10, 10);
	addComponent(eiComp);


	// Add Stat allocation buttons
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


}

void ScreenCharacterCreation::render()
{
	// Draw character level
	Renderer::drawString(std::to_string(character->getLevel()), Renderer::FONT_ROBOTO.get(20), 140, 100, 1, { 255,255,255,255 });

	// Draw ability scores and modifiers
	Renderer::drawString(abilityScores[0], Renderer::FONT_ROBOTO.get(20), 175, 220, 1, { 255,255,255,255 });
	Renderer::drawString((mods[0]>-1 ? "+" : "") + to_string(mods[0]), Renderer::FONT_ROBOTO.get(20), 275, 220, 1, { 255,255,255,255 });
	Renderer::drawString(abilityScores[1], Renderer::FONT_ROBOTO.get(20), 175, 255, 1, { 255,255,255,255 });
	Renderer::drawString((mods[1]>-1 ? "+" : "") + to_string(mods[1]), Renderer::FONT_ROBOTO.get(20), 275, 255, 1, { 255,255,255,255 });
	Renderer::drawString(abilityScores[2], Renderer::FONT_ROBOTO.get(20), 175, 290, 1, { 255,255,255,255 });
	Renderer::drawString((mods[2]>-1 ? "+" : "") + to_string(mods[2]), Renderer::FONT_ROBOTO.get(20), 275, 290, 1, { 255,255,255,255 });
	Renderer::drawString(abilityScores[3], Renderer::FONT_ROBOTO.get(20), 175, 325, 1, { 255,255,255,255 });
	Renderer::drawString((mods[3]>-1 ? "+" : "") + to_string(mods[3]), Renderer::FONT_ROBOTO.get(20), 275, 325, 1, { 255,255,255,255 });
	Renderer::drawString(abilityScores[4], Renderer::FONT_ROBOTO.get(20), 175, 360, 1, { 255,255,255,255 });
	Renderer::drawString((mods[4]>-1 ? "+" : "") + to_string(mods[4]), Renderer::FONT_ROBOTO.get(20), 275, 360, 1, { 255,255,255,255 });
	Renderer::drawString(abilityScores[5], Renderer::FONT_ROBOTO.get(20), 175, 395, 1, { 255,255,255,255 });
	Renderer::drawString((mods[5]>-1 ? "+" : "") + to_string(mods[5]), Renderer::FONT_ROBOTO.get(20), 275, 395, 1, { 255,255,255,255 });
	Renderer::drawString(abilityScores[6], Renderer::FONT_ROBOTO.get(20), 175, 430, 1, { 255,255,255,255 });

	Renderer::drawString(to_string(maxHealth), Renderer::FONT_ROBOTO.get(20), 530, 360, 1, { 255,255,255,255 });
	Renderer::drawString(to_string(attacksPerTurn), Renderer::FONT_ROBOTO.get(20), 530, 395, 1, { 255,255,255,255 });
	Renderer::drawString(to_string(attackBonus), Renderer::FONT_ROBOTO.get(20), 530, 430, 1, { 255,255,255,255 });


	// Render
	Screen::render();
}


void ScreenCharacterCreation::increment(int stat) {

	if ((abilityScores[stat] == "18") || (abilityScores[6]=="0")) {
		//std::cout << "Stat Increment failed" << endl;
		return;
	}
	string test = to_string(6);
	switch (stat) {
	case 0:
		//Increment strength and decrement remaining
		setRemaining(to_string((stoi(abilityScores[6])) - 1));
		character->setStrength(character->getStrength() + 1);
		break;

	case 1:
		// Increment dex and decrement remaining
		setRemaining(to_string((stoi(abilityScores[6])) - 1));
		character->setDexterity(character->getDexterity() + 1);
		break;

	case 2:
		// Increment con and decrement remaining, set health
		setRemaining(to_string((stoi(abilityScores[6])) - 1));
		character->setConstitution(character->getConstitution() + 1);
		if (newCharacter) {
			character->setMaxHealth(10 + character->getModifier(2));
		}
		break;

	case 3:
		// Increment  int and decrement remaining
		setRemaining(to_string(stoi(abilityScores[6]) - 1));
		character->setIntelligence(character->getIntelligence() + 1);
		break;
	case 4:
		// Increment wis and decrement remaining
		setRemaining(to_string(stoi(abilityScores[6]) - 1));
		character->setWisdom(character->getWisdom() + 1);
		break;

	case 5:
		// Increment cha and decrement remaining
		setRemaining(to_string(stoi(abilityScores[6]) - 1));
		character->setCharisma(character->getCharisma() + 1);
		break;

	default:
		break;
	}

}


void ScreenCharacterCreation::decrement(int stat) {
	if (stoi(abilityScores[stat]) <= 3) {
		return;
	}

	switch (stat) {
	case 0:
		// Decrement str and increment remaining
		setRemaining(to_string(stoi(abilityScores[6]) + 1));
		character->setStrength(character->getStrength()-1);
		break;
	case 1:
		// Decrement dex and increment remaining
		setRemaining(to_string(stoi(abilityScores[6]) + 1));
		character->setDexterity(character->getDexterity() - 1);
		break;

	case 2:
		// Decrement CON and increment remaining, update health

		setRemaining(to_string(stoi(abilityScores[6]) + 1));
		character->setConstitution(character->getConstitution() - 1);
		if (newCharacter) {
			character->setMaxHealth(10 + character->getModifier(2));
		}
		
		break;

	case 3:
		// Decrement INT and increment remaining
		setRemaining(to_string(stoi(abilityScores[6]) + 1));
		character->setIntelligence(character->getIntelligence() - 1);
		break;

	 case 4:
		 // Decrement WIS and increment remaining
		setRemaining(to_string(stoi(abilityScores[6]) + 1));
		character->setWisdom(character->getWisdom() - 1);
		break;

	 case 5:
		 // Decrement CHA and increment remaining
		setRemaining(to_string(stoi(abilityScores[6]) + 1));
		character->setCharisma(character->getCharisma() - 1);
		break;
	default:
		break;
	}

}

void ScreenCharacterCreation::rollCharacter() {

	// Reroll all ability scores
	character->setStrength(Dice::rollStat());
	character->setDexterity(Dice::rollStat());
	character->setConstitution(Dice::rollStat());
	character->setIntelligence(Dice::rollStat());
	character->setWisdom(Dice::rollStat());
	character->setCharisma(Dice::rollStat());
	// Unequip all items
	for (int i = 0; i < 7; i++) {
		delete(character->unequip(i));
	}
	// Equip starter items
	character->equipBasic();

	// Empty backpack
	for (int i = 0; i < 10; i++) {
		character->getBackpack()->removeItemAtIndex(i);
	}

	//Set level to 1
	character->setLevel(1);



	// Set max health to 10+con modifier
	character->setMaxHealth(10+character->getModifier(2));

	
	newCharacter = true; //Set a flag to indicate that this is a newly rolled character, so con bonus can be added to HP upon changes to con
	// Set name to defaultname
	character->setName("Artemis");

	// Set remaining ability points to 0
	setRemaining("0");
}



void ScreenCharacterCreation::saveCharacter() {
	// Ensure player has rolled stats before saving character
	if (abilityScores[0] == "0") {
		//std::cout << "Cannot save character, press roll" << std::endl;
	}
	// Ensure player does not have unspent points before saving character
	else if ((stoi(abilityScores[6]) > 0)) {
		//std::cout << "Cannot save character: points not spent" << std::endl;
	}
	// Ensure player has entered a name before saving character
	else if (nameInput->getText() == "") {
		//std::cout << "Cannot save character: enter a name" << std::endl;
	}

	else {
		// All conditions met. Save Character
		character->setName(nameInput->getText());
		// Check if this is a newly rolled character to add con bonus to HP if so
		character->saveLivingEntity();
		//std::cout << character->toString() << endl;
	}

}

void ScreenCharacterCreation::loadCharacter() {
	// Instantiate a temp character in case load fails
	LivingEntity* temp;
	// Load temp character
	temp = LivingEntity::loadLivingEntity(nameInput->getText());
	// Copy stats/items from temp to character
	character->copyStats(temp);
	// Set remaining points to 0
	setRemaining("0");
	newCharacter = false;
	delete temp;
}

void ScreenCharacterCreation::Update() {
	abilityScores[0] = to_string(character->getStrength());
	abilityScores[1] = to_string(character->getDexterity());
	abilityScores[2] = to_string(character->getConstitution());
	abilityScores[3] = to_string(character->getIntelligence());
	abilityScores[4] = to_string(character->getWisdom());
	abilityScores[5] = to_string(character->getCharisma());
	
	attacksPerTurn = character->getAttacksPerTurn();
	attackBonus = character->getAttackBonus();
	maxHealth = character->getMaxHealth();
	nameInput->setText(character->getName());
	for (int i = 0; i < 6; i++)
	{
		mods[i] = character->getModifier(i);
	}
	eiComp->Update();
}


ScreenCharacterCreation::~ScreenCharacterCreation() {
	character->Detach(this);
	delete character;
}

void ScreenCharacterCreation::setRemaining(std::string value) {
	abilityScores[6] = value;
}