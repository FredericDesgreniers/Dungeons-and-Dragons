#include "CharacterObserver.h"
#include "Character.h"
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
	cout << "Update from Observer pattern: " << _subject->toString() << endl;
}

Character* CharacterObserver::getSubject()
{
	return _subject;
}