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
}


Deck::Deck(Card** cardsArr)
{
	this->cardsArr = cardsArr;
}


Deck::~Deck()
{

	// delete the dynamically-created 1D array of Card* cardsArr
	// first delete each dynamically allocated entry (pointed by each pointer)
	for (int i = 0; i < DECK_SIZE; i++)
	{
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
			cardsArr[index]->display();
			cout << " ";
		}
		cout << endl;
	}
}