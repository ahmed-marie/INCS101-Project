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

typedef enum CARD_EVENT
{
	CARD_NOT_FOUND, CARD_FOUND
} CARD_EVENT_T;

typedef enum REVEALED_CARDS_EVENT
{
	TWO_SAME_STANDARD, TWO_DIFFERENT_STANDARD,
	TWO_PENALTY, TWO_BONUS, STANDARD_AND_BONUS,
	STANDARD_AND_PENALTY, BONUS_AND_PENALTY
} REVEALED_CARDS_EVENT_T;

typedef enum DECK_STATUS
{
	EMPTY_DECK, ONE_CARD_LEFT, TWO_OR_MORE_CARDS_LEFT
} DECK_STATUS_T;

class Deck
{
private:
	// cardsArr represents the array of cards (DECK_SIZE)
	// 6 pairs of StandardCard, 1 PenaltyCard and 1 BonusCard
	Card** cardsArr;
	// removedCards represented the number
	// of removed cards from the deck
	int removedCards;
	// revealedCardsIndex represents the
	// indicies of the revealed cards
	int revealedCardsIndex[2];
public:
	Deck();
	Deck(Card** cardsArr); // not tested
	~Deck();
	void setCardsArr(Card** cardsArr); // not tested
	Card** getCardsArr();
	void shuffle();
	void displayGrid();
	bool isCardExists(int index);
	DECK_STATUS_T getDeckStatus();
	CARD_EVENT_T revealCard(int row, int col);
	REVEALED_CARDS_EVENT_T evaluateFlippedCards();

};
#endif

