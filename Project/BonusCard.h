#ifndef BONUS_CARD
#define BONUS_CARD

#include "Card.h"
class BonusCard : public Card
{
public:
	//BonusCard();
	BonusCard(int number = 0, bool faceUp = false);
	~BonusCard();
};

#endif // !BONUS_CARD


