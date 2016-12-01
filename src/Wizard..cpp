#include "Wizard.h"
#include "GUI/Renderer.h"

Wizard::Wizard():Monster('W')
{
	spellProgress = 0;
	setPathfinderDistance(15);
	setName("Wizard");
}


SDL_Color Wizard::getDisplayColor()
{
	return{ 0,0,255,255 };
}


int Wizard::getSpellProgress()
{
	return spellProgress;
}
