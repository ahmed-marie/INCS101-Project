#ifndef DECK_H
#define DECK_H

#include "BonusCard.h"
#include "StandardCard.h"
#include "PenaltyCard.h"

#include <ctime>

#define GRID_SIZE 4

#define NUMBER_OF_STANDARD_CARDS_PAIRS 6
#define NUMBER_OF_BONUS_CARDS_PAIRS 1
#define NUMBER_OF_PENALTY_CARDS_PAIRS 1

#define DECK_SIZE (2*(NUMBER_OF_STANDARD_CARDS_PAIRS + \
                   NUMBER_OF_BONUS_CARDS_PAIRS + \
                   NUMBER_OF_PENALTY_CARDS_PAIRS))

class Deck
{
private:
	// cardsArr represents the array of cards (DECK_SIZE)
	// 6 pairs of StandardCard, 1 PenaltyCard and 1 BonusCard
	Card** cardsArr;

public:
	Deck();
	Deck(Card** cardsArr); // not tested
	~Deck();
	void setCardsArr(Card** cardsArr); // not tested
	Card** getCardsArr();
	void shuffle();
	void displayGrid();
};
#endif

