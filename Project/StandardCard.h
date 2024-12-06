#ifndef STANDARD_CARD
#define STANDARD_CARD

#include "Card.h"
class StandardCard : public Card
{
public:
	//StandardCard();
	StandardCard(int number = 0, bool faceUp = false);
	~StandardCard();
};


#endif // !STANDARD_CARD



