#ifndef PENALTY_CARD
#define PENALTY_CARD

#include "Card.h"
class PenaltyCard : public Card
{
public:
	//PenaltyCard();
	PenaltyCard(int number = 0, bool faceUp = false);
	~PenaltyCard();
};

#endif // !PENALTY_CARD



