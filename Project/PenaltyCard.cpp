#include "PenaltyCard.h"

//PenaltyCard::PenaltyCard() {}

PenaltyCard::PenaltyCard(int number, bool faceUp) : Card(number, faceUp)
{
	cardType = PENALTY;
};

PenaltyCard::~PenaltyCard() {}

void PenaltyCard::displayCardMessage()
{
	cout << "Penalty Card is revealed" << endl;
}