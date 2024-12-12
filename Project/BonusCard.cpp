#include "BonusCard.h"

//BonusCard::BonusCard() {}

BonusCard::BonusCard(int number, bool faceUp) : Card(number, faceUp)
{
	cardType = BONUS;
};

BonusCard::~BonusCard() {}

void BonusCard::displayCardMessage()
{
	cout << "Bonus Card is revealed" << endl;
}