#include "Deck.h"

Deck::Deck()
{
	// Allocate memory for cardsArr (type: array of pointer to cards)
	
	cardsArr = new Card* [DECK_SIZE];

	// Initialize the cardsArr with the different types of cards
	// 1. intialize the first 12 cards with standard cards
	int size = NUMBER_OF_STANDARD_CARDS_PAIRS;

	// arrayIndex represent the index in the array, counterIndex represents the card number
	int arrayIndex = 0;
	for (int counterIndex = 1; counterIndex <= size; counterIndex++)
	{
		// 1. initialize the first card in the pair
		cardsArr[arrayIndex++] = new StandardCard(counterIndex);
		// 2. initialize the second card in the pair
		cardsArr[arrayIndex++] = new StandardCard(counterIndex);
	}

	// 2. intialize the next two cards with bonus cards
	size += NUMBER_OF_BONUS_CARDS_PAIRS;
	for (int counterIndex = (arrayIndex / 2) + 1; counterIndex <= size; counterIndex++)
	{
		// 1. initialize the first card in the pair
		cardsArr[arrayIndex++] = new BonusCard(counterIndex);
		// 2. initialize the second card in the pair
		cardsArr[arrayIndex++] = new BonusCard(counterIndex, false);
	}
	// 3. intialize the next two cards with penalty cards
	size += NUMBER_OF_PENALTY_CARDS_PAIRS;
	for (int counterIndex = (arrayIndex / 2) + 1; counterIndex <= size; counterIndex++)
	{
		// 1. initialize the first card in the pair
		cardsArr[arrayIndex++] = new PenaltyCard(counterIndex);
		// 2. initialize the second card in the pair
		cardsArr[arrayIndex++] = new PenaltyCard(counterIndex, false);
	}
	// initialized the number of removed cards to 0
	removedCards = 0;

	// initialize the revealedCardsIndex Array elements to -1
	revealedCardsIndex[0] = -1;
	revealedCardsIndex[1] = -1;
}


Deck::Deck(Card** cardsArr)
{
	this->cardsArr = cardsArr;

	// initialized the number of removed cards to 0
	removedCards = 0;

	// initialize the revealedCardsIndex Array elements to -1
	revealedCardsIndex[0] = -1;
	revealedCardsIndex[1] = -1;
}


Deck::~Deck()
{
	// delete the dynamically-created 1D array of Card* cardsArr
	// first delete each dynamically allocated entry (pointed by each pointer)
	for (int i = 0; i < DECK_SIZE; i++)
	{
		if(cardsArr[i] != nullptr)
			delete cardsArr[i];
	}
	// delete the whole array
	delete[] cardsArr;
}


void Deck::setCardsArr(Card** cardsArr)
{
	this->cardsArr = cardsArr;
}


Card** Deck::getCardsArr()
{
	return cardsArr;
}


void Deck::shuffle()
{
	srand(static_cast<unsigned>(time(0)));
	for (int i = 0; i < DECK_SIZE; ++i) {
		int j = rand() % DECK_SIZE; // Generate a random index
		swap(cardsArr[i], cardsArr[j]); // Swap the cards at indices i and j
	}
}


void Deck::displayGrid()
{
	for (int i = 0; i < GRID_SIZE; i++)
	{
		//cout << "    ";
		for (int j = 0; j < GRID_SIZE; j++)
		{
			int index = i * GRID_SIZE + j; // i * j - 1
			// if the card pointer is not a nullptr 
			// (not removed from array)
			if (cardsArr[index] != nullptr)
			{
				cardsArr[index]->display();
			}
			else
			{
				cout << " ";
			}
			cout << " ";
		}
		cout << endl;
	}
}

bool Deck::isCardExists(int index)
{
	return cardsArr[index] != nullptr;
}

DECK_STATUS_T Deck::getDeckStatus()
{
	if (removedCards == DECK_SIZE)
	{
		return EMPTY_DECK;
	}
	else if (removedCards == (DECK_SIZE - 1))
	{
		return ONE_CARD_LEFT;
	}
	else
	{
		return TWO_OR_MORE_CARDS_LEFT;
	}
}

CARD_EVENT_T  Deck::revealCard(int row, int col)
{
	// converts row and col to index. 
	// row and col have values between 1 and GRID_SIZE inclusive
	int index = (row - 1) * GRID_SIZE + col - 1; // i * j - 1
	if (isCardExists(index) == false)
	{
		return CARD_NOT_FOUND;
	}
	else
	{
		// Flip the card
		cardsArr[index]->setFaceUp(true);
		// add its index in the reavealedCardIndex
		// 0 or 1 whether 0 is free
		if (revealedCardsIndex[0] == -1)
		{
			revealedCardsIndex[0] = index;
		}
		else
		{
			revealedCardsIndex[1] = index;
		}
		// display the card's message
		cardsArr[index]->displayCardMessage();
		
		return CARD_FOUND;
	}
}

REVEALED_CARDS_EVENT_T Deck::evaluateFlippedCards()
{
	REVEALED_CARDS_EVENT_T status;
	// get the card pointers
	Card* card1_ptr = cardsArr[revealedCardsIndex[0]];
	Card* card2_ptr = cardsArr[revealedCardsIndex[1]];
	// get their corresponding type
	CARD_TYPE_T card1_type = card1_ptr->getCardType();
	CARD_TYPE_T card2_type = card2_ptr->getCardType();

	// Determine the card's status 
	// (numbered according to cases in Notion)

	// two standard cards: 1. same 7. different
	if ((card1_type == STANDARD) && (card2_type == STANDARD))
	{
		if (card1_ptr->getNumber() == card1_ptr->getNumber())
		{
			status = TWO_SAME_STANDARD;
		}
		else
		{
			status = TWO_DIFFERENT_STANDARD;
		}
	}
	// 2. Two penalty cards
	else if ((card1_type == PENALTY) && (card2_type == PENALTY))
	{
		status = TWO_PENALTY;
	}
	// 3. Two bonus cards
	else if ((card1_type == BONUS) && (card2_type == BONUS))
	{
		status = TWO_BONUS;
	}
	// 4. A Bonus card and a Penalty Card
	else if (((card1_type == BONUS) && (card2_type == PENALTY)) ||
		((card1_type == PENALTY) && (card2_type == BONUS)))
	{
		status = BONUS_AND_PENALTY;
	}
	// 5. A Standard card and a Bonus Card
	else if (((card1_type == STANDARD) && (card2_type == BONUS)) ||
		((card1_type == BONUS) && (card2_type == STANDARD)))
	{
		status = STANDARD_AND_BONUS;
	}
	// 6. A Standard card and a Penalty Card
	else if (((card1_type == STANDARD) && (card2_type == PENALTY)) ||
		((card1_type == PENALTY) && (card2_type == STANDARD)))
	{
		status = STANDARD_AND_PENALTY;
	}
	else
	{
		// non existing case
	}
	
	// manipulating deck and cards based on their type
	switch (status)
	{
		// cases 1. to 4.
		case TWO_SAME_STANDARD:
		case TWO_PENALTY:
		case TWO_BONUS:
		case BONUS_AND_PENALTY:
			// delete both cards
			delete card1_ptr;
			delete card2_ptr;
			// set the pointers to nullptr
			cardsArr[revealedCardsIndex[0]] = nullptr;
			cardsArr[revealedCardsIndex[1]] = nullptr;
			// increment removedCards by 2
			removedCards += 2;
			break;

		// case 5. and 6.
		case STANDARD_AND_BONUS:
		case STANDARD_AND_PENALTY:
			if (card1_type == STANDARD)
			{
				// flip the standard card
				cardsArr[revealedCardsIndex[0]]->setFaceUp(false);
				// delete the bonus/penalty card
				delete card2_ptr;
				cardsArr[revealedCardsIndex[1]] = nullptr;
			}
			else
			{
				// flip the standard card
				cardsArr[revealedCardsIndex[1]]->setFaceUp(false);
				// delete the bonus/penalty card
				delete card1_ptr;
				cardsArr[revealedCardsIndex[0]] = nullptr;
			}
			// increment removedCards by 1
			removedCards++;
			break;

		case TWO_DIFFERENT_STANDARD:
			// flip the standard cards
			cardsArr[revealedCardsIndex[0]]->setFaceUp(false);
			cardsArr[revealedCardsIndex[1]]->setFaceUp(false);

		default: break;
	}

	// set the card indices in revealedCardsIndex to -1
	revealedCardsIndex[0] = -1;
	revealedCardsIndex[1] = -1;

	// return the status
	return status;
}
