#include "ScreenItemCreation.h"

ScreenItemCreation::ScreenItemCreation(Game* game) : Screen(game)
{

	for (int i = 0; i < 9; ++i)
	{
		abilityScores[i] = "0";
	}

	type = "Helmet";
	typeCounter = 0;

	it = new Item();
	it->Attach(this);

	itemName = new TextField("Name here", 125, 100, 150, 25);
	itemName->setFontSize(20);

	int x = 220;


	Button* confirmBtn = new Button("Save Item", &Renderer::FONT_ROBOTO, 300, 600, 100, 30);
	confirmBtn->setFontSize(25);
	confirmBtn->adjustButtonDimensions();

	// ----- PLUS AND MINUS BUTTONS


	// STR
	Button* strPlus = new Button("+", &Renderer::FONT_ROBOTO, x, x, 1, 1);
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

	Button* strMinus = new Button("-", &Renderer::FONT_ROBOTO, x + 20, x, 1, 1);
	copyStyle(*strPlus, *strMinus);
	copySize(*strPlus, *strMinus);
	strMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(0);
	});


	// DEX
	Button* dexPlus = new Button("+", &Renderer::FONT_ROBOTO, x, x + 35, 1, 1);
	copyStyle(*strPlus, *dexPlus);
	copySize(*strPlus, *dexPlus);
	dexPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(1);
	});

	Button* dexMinus = new Button("-", &Renderer::FONT_ROBOTO, x + 20, x + 35, 1, 1);
	copyStyle(*strPlus, *dexMinus);
	copySize(*strPlus, *dexMinus);
	dexMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(1);
	});


	// CON
	Button* conPlus = new Button("+", &Renderer::FONT_ROBOTO, x, x + 70, 1, 1);
	copyStyle(*strPlus, *conPlus);
	copySize(*strPlus, *conPlus);
	conPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(2);
	});

	Button* conMinus = new Button("-", &Renderer::FONT_ROBOTO, x + 20, x + 70, 1, 1);
	copyStyle(*strPlus, *conMinus);
	copySize(*strPlus, *conMinus);
	conMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(2);
	});


	// INT
	Button* intPlus = new Button("+", &Renderer::FONT_ROBOTO, x, x + 105, 1, 1);
	copyStyle(*strPlus, *intPlus);
	copySize(*strPlus, *intPlus);
	intPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(3);
	});

	Button* intMinus = new Button("-", &Renderer::FONT_ROBOTO, x + 20, x + 105, 1, 1);
	copyStyle(*strPlus, *intMinus);
	copySize(*strPlus, *intMinus);
	intMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(3);
	});


	// WIS
	Button* wisPlus = new Button("+", &Renderer::FONT_ROBOTO, x, x + 140, 1, 1);
	copyStyle(*strPlus, *wisPlus);
	copySize(*strPlus, *wisPlus);
	wisPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(4);
	});

	Button* wisMinus = new Button("-", &Renderer::FONT_ROBOTO, x + 20, x + 140, 1, 1);
	copyStyle(*strPlus, *wisMinus);
	copySize(*strPlus, *wisMinus);
	wisMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(4);
	});


	// CHA
	Button* chaPlus = new Button("+", &Renderer::FONT_ROBOTO, x, x + 175, 1, 1);
	copyStyle(*strPlus, *chaPlus);
	copySize(*strPlus, *chaPlus);
	chaPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(5);
	});

	Button* chaMinus = new Button("-", &Renderer::FONT_ROBOTO, x + 20, x + 175, 1, 1);
	copyStyle(*strPlus, *chaMinus);
	copySize(*strPlus, *chaMinus);
	chaMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(5);
	});


	// ATK
	Button* atkPlus = new Button("+", &Renderer::FONT_ROBOTO, x, x + 210, 1, 1);
	copyStyle(*strPlus, *atkPlus);
	copySize(*strPlus, *atkPlus);
	atkPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(6);
	});

	Button* atkMinus = new Button("-", &Renderer::FONT_ROBOTO, x + 20, x + 210, 1, 1);
	copyStyle(*strPlus, *atkMinus);
	copySize(*strPlus, *atkMinus);
	atkMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(6);
	});


	// DMG
	Button* dmgPlus = new Button("+", &Renderer::FONT_ROBOTO, x, x + 245, 1, 1);
	copyStyle(*strPlus, *dmgPlus);
	copySize(*strPlus, *dmgPlus);
	dmgPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(7);
	});

	Button* dmgMinus = new Button("-", &Renderer::FONT_ROBOTO, x + 20, x + 245, 1, 1);
	copyStyle(*strPlus, *dmgMinus);
	copySize(*strPlus, *dmgMinus);
	dmgMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(7);
	});


	// ARM
	Button* armPlus = new Button("+", &Renderer::FONT_ROBOTO, x, x + 280, 1, 1);
	copyStyle(*strPlus, *armPlus);
	copySize(*strPlus, *armPlus);
	armPlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		increment(8);
	});

	Button* armMinus = new Button("-", &Renderer::FONT_ROBOTO, x + 20, x + 280, 1, 1);
	copyStyle(*strPlus, *armMinus);
	copySize(*strPlus, *armMinus);
	armMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		decrement(8);
	});


	// TYPE
	Button* typePlus = new Button("+", &Renderer::FONT_ROBOTO, x, x - 35, 1, 1);
	copyStyle(*strPlus, *typePlus);
	copySize(*strPlus, *typePlus);
	typePlus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		if (typeCounter == 6)
		{
			typeCounter = 0;
			changeType(typeCounter);
		}
		else 
		{
			changeType(++typeCounter);
		}
	});

	Button* typeMinus = new Button("-", &Renderer::FONT_ROBOTO, x + 20, x - 35, 1, 1);
	copyStyle(*strPlus, *typeMinus);
	copySize(*strPlus, *typeMinus);
	typeMinus->addOnClick_callback([this](Component* comp, int x, int y)
	{
		if (typeCounter == 0)
		{
			typeCounter = 6;
			changeType(typeCounter);
		}
		else
		{
			changeType(--typeCounter);
		}
	});


	// confirm button behavior
	confirmBtn->addOnClick_callback([this](Component* comp, int x, int y)
	{
			createItem();
	});

	// Labels
	addComponent((new Label("Type", &Renderer::FONT_ROBOTO, 20, 190, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Strength", &Renderer::FONT_ROBOTO, 20, 220, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Dexterity", &Renderer::FONT_ROBOTO, 20, 255, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Constitution", &Renderer::FONT_ROBOTO, 20, 290, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Intelligence", &Renderer::FONT_ROBOTO, 20, 325, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Wisdom", &Renderer::FONT_ROBOTO, 20, 360, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Charisma", &Renderer::FONT_ROBOTO, 20, 395, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Attack", &Renderer::FONT_ROBOTO, 20, 430, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Damage", &Renderer::FONT_ROBOTO, 20, 465, 1, 1))->setFontSize(20)->adjustDimensions());
	addComponent((new Label("Armor", &Renderer::FONT_ROBOTO, 20, 500, 1, 1))->setFontSize(20)->adjustDimensions());

	// Add Components
	addComponent(itemName);
	addComponent(confirmBtn);
	addComponent(typePlus);
	addComponent(typeMinus);
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
	addComponent(atkPlus);
	addComponent(atkMinus);
	addComponent(dmgPlus);
	addComponent(dmgMinus);
	addComponent(armPlus);
	addComponent(armMinus);
}

void ScreenItemCreation::render()
{
	Renderer::drawString("Item Editor", Renderer::FONT_ROBOTO.get(24), 250, 0, 1, { 255,255,255,255 });

	Renderer::drawString("Name", Renderer::FONT_ROBOTO.get(20), 20, 100, 1, { 255,255,255,255 });
	
	Renderer::drawString(Item::displayType(it->getItemType()), Renderer::FONT_ROBOTO.get(20), 125, 190, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[0], Renderer::FONT_ROBOTO.get(20), 175, 220, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[1], Renderer::FONT_ROBOTO.get(20), 175, 255, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[2], Renderer::FONT_ROBOTO.get(20), 175, 290, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[3], Renderer::FONT_ROBOTO.get(20), 175, 325, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[4], Renderer::FONT_ROBOTO.get(20), 175, 360, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[5], Renderer::FONT_ROBOTO.get(20), 175, 395, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[6], Renderer::FONT_ROBOTO.get(20), 175, 430, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[7], Renderer::FONT_ROBOTO.get(20), 175, 465, 1, { 255,255,255,255 });

	Renderer::drawString(abilityScores[8], Renderer::FONT_ROBOTO.get(20), 175, 500, 1, { 255,255,255,255 });

	Screen::render();
}

void ScreenItemCreation::increment(int stat)
{
	switch (stat)
	{
	case 0:
		it->setStrBoost(it->getStrBoost() + 1);
		break;
	case 1:
		it->setDexBoost(it->getDexBoost() + 1);
		break;
	case 2:
		it->setConBoost(it->getConBoost() + 1);
		break;
	case 3:
		it->setIntBoost(it->getIntBoost() + 1);
		break;
	case 4:
		it->setWisBoost(it->getWisBoost() + 1);
		break;
	case 5:
		it->setChaBoost(it->getChaBoost() + 1);
		break;
	case 6:
		it->setAtkBoost(it->getAtkBoost() + 1);
		break;
	case 7:
		it->setDmgBoost(it->getDmgBoost() + 1);
		break;
	case 8:
		it->setArmBoost(it->getArmBoost() + 1);
		break;
	default:

		break;
	}
}

void ScreenItemCreation::decrement(int stat)
{
	switch (stat)
	{
	case 0:
		it->setStrBoost(it->getStrBoost() - 1);
		break;
	case 1:
		it->setDexBoost(it->getDexBoost() - 1);
		break;
	case 2:
		it->setConBoost(it->getConBoost() - 1);
		break;
	case 3:
		it->setIntBoost(it->getIntBoost() - 1);
		break;
	case 4:
		it->setWisBoost(it->getWisBoost() - 1);
		break;
	case 5:
		it->setChaBoost(it->getChaBoost() - 1);
		break;
	case 6:
		it->setAtkBoost(it->getAtkBoost() - 1);
		break;
	case 7:
		it->setDmgBoost(it->getDmgBoost() - 1);
		break;
	case 8:
		it->setArmBoost(it->getArmBoost() - 1);
		break;
	default:

		break;
	}
}

void ScreenItemCreation::changeType(int stat)
{
	switch (stat)
	{
	case 0:
		it->setItemType(Item::ItemType::HELMET);
		break;
	case 1:
		it->setItemType(Item::ItemType::ARMOR);
		break;
	case 2:
		it->setItemType(Item::ItemType::SHIELD);
		break;
	case 3:
		it->setItemType(Item::ItemType::RING);
		break;
	case 4:
		it->setItemType(Item::ItemType::BOOTS);
		break;
	case 5:
		it->setItemType(Item::ItemType::BELT);
		break;
	case 6:
		it->setItemType(Item::ItemType::WEAPON);
		break;
	default:
		break;
	}
}

void ScreenItemCreation::createItem()
{
	it->setName(itemName->getText());
	Item::saveItem(itemName->getText(), it);

}

void ScreenItemCreation::Update()
{
	
	it->validateItem(it);

	setStrength(to_string(it->getStrBoost()));
	setDexterity(to_string(it->getDexBoost()));
	setConstitution(to_string(it->getConBoost()));
	setIntelligence(to_string(it->getIntBoost()));
	setWisdom(to_string(it->getWisBoost()));
	setCharisma(to_string(it->getChaBoost()));
	setAttack(to_string(it->getAtkBoost()));
	setDamage(to_string(it->getDmgBoost()));
	setArmor(to_string(it->getArmBoost()));

	setType(Item::displayType(it->getItemType()));

	itemName->setText(it->getName());


}

void ScreenItemCreation::setType(std::string value) {
	type = value;
}

void ScreenItemCreation::setStrength(std::string value) {
	abilityScores[0] = value;
}

void ScreenItemCreation::setDexterity(std::string value) {
	abilityScores[1] = value;
}

void ScreenItemCreation::setConstitution(std::string value) {
	abilityScores[2] = value;
}

void ScreenItemCreation::setIntelligence(std::string value) {
	abilityScores[3] = value;
}

void ScreenItemCreation::setWisdom(std::string value) {
	abilityScores[4] = value;
}

void ScreenItemCreation::setCharisma(std::string value) {
	abilityScores[5] = value;
}

void ScreenItemCreation::setAttack(std::string value) {
	abilityScores[6] = value;
}

void ScreenItemCreation::setDamage(std::string value) {
	abilityScores[7] = value;
}

void ScreenItemCreation::setArmor(std::string value) {
	abilityScores[8] = value;
}

ScreenItemCreation::~ScreenItemCreation()
{
	delete it;
}