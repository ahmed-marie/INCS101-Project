#include "Card.h"

Card::Card(int number, bool faceUp)
{
	this->number = number;
	this->faceUp = faceUp;
}


Card::~Card() {}


void Card::setNumber(int number)
{
	this->number = number;
}


int Card::getNumber()
{
	return number;
}


void Card::setFaceUp(bool faceUp)
{
	this->faceUp = faceUp;
}


bool Card::isFaceUp()
{
	return faceUp;
}


void Card::display()
{
	if (faceUp)
	{
		cout << number;
	}
	else
	{
		cout << "*";
	}
}