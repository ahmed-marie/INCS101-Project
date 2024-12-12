#include "StandardCard.h"

//StandardCard::StandardCard() {}

StandardCard::StandardCard(int number, bool faceUp) : Card(number, faceUp)
{
	cardType = STANDARD;
};

StandardCard::~StandardCard() {}

void StandardCard::displayCardMessage()
{
	cout << "Standard Card " << number << " is revealed" << endl;
}
