#include "ScreenCharacterSelect.h"
#include "Renderer.h"
ScreenCharacterSelect::ScreenCharacterSelect(Game* game, Campaign* campaign):Screen(game), campaign(campaign)
{
	
}

void ScreenCharacterSelect::render()
{
	Screen::render();
	Renderer::drawString("Chose a character to play the " + campaign->getName() + " campaign with...", Renderer::FONT_ROBOTO.get(24), 0,0,1,{255,255,255,255});
	
}
