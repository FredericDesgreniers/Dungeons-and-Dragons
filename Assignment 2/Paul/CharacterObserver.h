#pragma once
#include "Observer.h"
#include "Character.h"

class CharacterObserver : public Observer
{
public:
	CharacterObserver();
	CharacterObserver(Character* c);
	~CharacterObserver();
	
	void Update();
	void display();
	Character* getSubject();



private:
	Character *_subject;
};
