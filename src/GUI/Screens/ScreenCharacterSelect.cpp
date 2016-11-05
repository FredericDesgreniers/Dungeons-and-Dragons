#include "ScreenCharacterSelect.h"

#include "ScreenPlayCampaign.h"
#include "../Renderer.h"
#include "../Components/CharacterSelect.h"


ScreenCharacterSelect::ScreenCharacterSelect(Game* game, Campaign* campaign):Screen(game), campaign(campaign)
{
	Button* defaultCharacterBtn = new Button("Random character roll", &Renderer::FONT_ROBOTO, 10,300,0,0);
	defaultCharacterBtn->adjustButtonDimensions();
	defaultCharacterBtn->addOnClick_callback([this](Component* component, int x, int y)
	{
		ScreenPlayCampaign* screen_play_campaign = new ScreenPlayCampaign(this->game, this->campaign, new Character(1));
		Renderer::addVoidScreen(this->game->getGuiManager()->setScreen(screen_play_campaign));
	});

	CharacterSelect* cs = new CharacterSelect(10, 30, 200, 200);
	cs->addOnCharacterClick_callback([this](std::string name)
	{
		Character* c = Character::loadCharacter(name);
		ScreenPlayCampaign* screen_play_campaign = new ScreenPlayCampaign(this->game, this->campaign, c);
		Renderer::addVoidScreen(this->game->getGuiManager()->setScreen(screen_play_campaign));

	});
	cs->setBorderSize(10);
	cs->setBorderColor_both(255, 255, 255, 255);
	addComponent(cs);
	addComponent(defaultCharacterBtn);
}

void ScreenCharacterSelect::render()
{
	Screen::render();
	Renderer::drawString("Chose a character to play the " + campaign->getName() + " campaign with...", Renderer::FONT_ROBOTO.get(24), 0,0,1,{255,255,255,255});
	
}
