#include "CharacterObserver.h"
#include <iostream>
using namespace std;

CharacterObserver::CharacterObserver() {};

CharacterObserver::CharacterObserver(Character* c)
{
	_subject = c;
	_subject->Attach(this);
}

CharacterObserver::~CharacterObserver()
{
	_subject->Detach(this);
}

void CharacterObserver::Update()
{
	display();
}

void CharacterObserver::display()
{
	cout << _subject->toString() << endl;
}

