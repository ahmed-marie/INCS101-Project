/*
	This is a test file implementing different methods to test the classes
*/

#include "Card.h"
#include "StandardCard.h"
#include "PenaltyCard.h"
#include "BonusCard.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"

/*
void testCardClass(void)
{
	// Test 1: Creating a card with an Empty Constructor
	Card* newCard = new Card;

	// 1. Testing getNumber() method: Output should be 0
	cout << "Card Number: " << newCard->getNumber() << endl;

	// 2. Testing isFaceUp() method: Output should be false
	cout << "Card faceUp: " << boolalpha << newCard->isFaceUp() << endl;

	// 3. Testing display() method: Output should be *
	newCard->display();
	cout << endl;

	// 4. Testing setNumber(<number>) method: Output should be <number>
	newCard->setNumber(5);
	cout << "Card Number: " << newCard->getNumber() << endl;

	// 5. Testing setFaceUp(<bool>) method: Output should be true
	newCard->setFaceUp(true);
	newCard->display();

	// 5. Testing destructor
	delete newCard;
}
*/

void testStandardCardClass(void)
{
	// Test 1: Creating a card with an Empty Constructor
	StandardCard* newCard = new StandardCard;

	// 1. Testing getNumber() method: Output should be 0
	cout << "Card Number: " << newCard->getNumber() << endl;

	// 2. Testing isFaceUp() method: Output should be false
	cout << "Card faceUp: " << boolalpha << newCard->getNumber() << endl;

	// 3. Testing display() method: Output should be *
	newCard->display();
	cout << endl;

	// 4. Testing setNumber(<number>) method: Output should be <number>
	newCard->setNumber(5);
	cout << "Card Number: " << newCard->getNumber() << endl;

	// 5. Testing setFaceUp(<bool>) method: Output should be true
	newCard->setFaceUp(true);
	newCard->display();
	cout << endl;

	// 6. Testing CARD_TYPE_T getCardType();
	if (newCard->getCardType() == STANDARD)
		cout << "Test Passed" << endl;
	else
		cout << "Test Failed" << endl;

	// 7. Testing Card Message
	newCard->displayCardMessage();

	// 8. Testing destructor
	delete newCard;
}

void testPenaltyCardClass()
{
	// Test 1: Creating a card with an Empty Constructor
	Card* newCard = new PenaltyCard;

	// 1. Testing getNumber() method: Output should be 0
	cout << "Card Number: " << newCard->getNumber() << endl;

	// 2. Testing isFaceUp() method: Output should be false
	cout << "Card faceUp: " << boolalpha << newCard->getNumber() << endl;

	// 3. Testing display() method: Output should be *
	newCard->display();
	cout << endl;

	// 4. Testing setNumber(<number>) method: Output should be <number>
	newCard->setNumber(5);
	cout << "Card Number: " << newCard->getNumber() << endl;

	// 5. Testing setFaceUp(<bool>) method: Output should be true
	newCard->setFaceUp(true);
	newCard->display();
	cout << endl;

	// 6. Testing CARD_TYPE_T getCardType();
	if (newCard->getCardType() == PENALTY)
		cout << "Test Passed" << endl;
	else
		cout << "Test Failed" << endl;

	// 7. Testing Card Message
	newCard->displayCardMessage();

	// 8. Testing destructor
	delete newCard;
}

void testBonusCardClass()
{
	// Test 1: Creating a card with an Empty Constructor
	BonusCard* newCard = new BonusCard;

	// 1. Testing getNumber() method: Output should be 0
	cout << "Card Number: " << newCard->getNumber() << endl;

	// 2. Testing isFaceUp() method: Output should be false
	cout << "Card faceUp: " << boolalpha << newCard->getNumber() << endl;

	// 3. Testing display() method: Output should be *
	newCard->display();
	cout << endl;

	// 4. Testing setNumber(<number>) method: Output should be <number>
	newCard->setNumber(5);
	cout << "Card Number: " << newCard->getNumber() << endl;

	// 5. Testing setFaceUp(<bool>) method: Output should be true
	newCard->setFaceUp(true);
	newCard->display();
	cout << endl;

	// 6. Testing CARD_TYPE_T getCardType();
	if (newCard->getCardType() == BONUS)
		cout << "Test Passed" << endl;
	else
		cout << "Test Failed" << endl;

	// 7. Testing Card Message
	newCard->displayCardMessage();


	// 5. Testing destructor
	delete newCard;
}

int testDeckClass(void)
{
	// 1. Creating a Deck with an Empty Constructor Deck();
	Deck d;
	
	// 2. Testing getCardsArr()
	cout << "Testing getCardsArr()" << endl;
	Card** cards = d.getCardsArr();
	// 2.1. printing the cards array: should be in order
	for (int i = 0; i < DECK_SIZE; i++)
	{
		cout << cards[i]->getNumber() << " ";
	}
	cout << endl;

	// 3. Testing displayGrid()
	cout << "Testing displayGrid()" << endl;
	// 3.1. set faceup = true for each card in the array 
	for (int i = 0; i < DECK_SIZE; i++)
	{
		cards[i]->setFaceUp(true);
	}

	// 3.2. dispaly grid: Output should be cards in order
	d.displayGrid();

	// 4. Testing shuffle()
	cout << "Testing shuffle()" << endl;
	// Output should be cards in random order
	d.shuffle();
	d.displayGrid();

	// 5. Testing destructor ~Deck() (insert a break point here)
	return 0;

	//Deck(Card * *cardsArr);
	//void setCardsArr(Card * *cardsArr);
}

void testPlayerClass(void)
{
	// 1. creating a person with default constructor
	Player p1 = Player();

	// 2. testing get name should return ""
	cout << "Testing getName()" << endl;
	cout << "Player Name: " << p1.getName() << endl;

	// 3. testing get score should return 0
	cout << "Testing getScore()" << endl;
	cout << "Player Name: " << p1.getScore() << endl;

	// 4. testing setName(): setting the name using setName()
	cout << "Testing setName()" << endl;
	p1.setName("Ahmed");
	cout << "Player Name: " << p1.getName() << endl;

	// 5. testing setScore(): setting the score using setScore()
	cout << "Testing setScore()" << endl;
	p1.setScore(5);
	cout << "Player Score: " << p1.getScore() << endl;

	// 6. testing displayScore(): expected output -> 5
	cout << "Testing displayScore()" << endl;
	p1.displayScore();

	// 7. testing updateScore(int score)
	cout << "Testing displayScore()" << endl;
	p1.updateScore(2);
	p1.displayScore();

	// 8. testing turnsNo setter and getter
	cout << "turnsNo setter and getter" << endl;
	cout << "setting turn to 2" << endl;
	p1.setTurnsNo(2);
	cout << "printing the turn (getTurnsNo): ";
	cout << p1.getTurnsNo() << endl;
	
	// 9. testing incrementTurn() 
	cout << "testing incrementTurn()" << endl;
	p1.incrementTurn(); // turnsNo = 3
	cout << "printing the turn (getTurnsNo): ";
	cout << p1.getTurnsNo() << endl;
	
	cout << "testing incrementTurn(2)" << endl;
	p1.incrementTurn(2); // turnsNo = 5
	cout << "printing the turn (getTurnsNo): ";
	cout << p1.getTurnsNo() << endl;
	
	cout << "testing decrementTurn()" << endl;
	p1.decrementTurn(); // turnsNo = 4
	cout << "printing the turn (getTurnsNo): ";
	cout << p1.getTurnsNo() << endl;

}

void testGameClass(void)
{
	Game game;
	game.intializeGame();
}


int testDeckClass_1(void)

{
	//initializing a deck
	Deck deck;

	deck.displayGrid();
	cout << endl;

	//1. Testing bool isCardExists(int index)
	cout << "1. Testing isCardExists function" << endl;

	cout << "Case 1: card exists: ";
	if (deck.isCardExists(0))
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}

	deck.displayGrid();
	cout << endl;

	cout << "Case 2: Card does not exist: ";
	// remove the first card in the cardsArr
	Card** cardsArr = deck.getCardsArr();
	delete cardsArr[0];
	cardsArr[0] = nullptr;
	// printing the test results
	if (!deck.isCardExists(0))
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}

	deck.displayGrid();
	cout << endl;
	
	//2. Testing CARD_EVENT_T revealCard(int row, int col);
	cout << "2. Testing revealCard function" << endl;
	cout << "Case 1: card exists: ";
	// attempt to reveal the 2nd element in the cardsArr
	CARD_EVENT_T e;
	e = deck.revealCard(1, 2);
	if (e == CARD_FOUND)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	
	deck.displayGrid();
	cout << endl;

	cout << "Case 2: card does not exists: ";
	// attempt to reveal the 1st element in the cardsArr
	// which is removed before
	e = deck.revealCard(1, 1);
	if (e == CARD_NOT_FOUND)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}

	deck.displayGrid();
	cout << endl;

	//2. Testing REVEALED_CARDS_EVENT_T evaluateFlippedCards()
	cout << "3. Testing evaluateFlippedCards function" << endl;
	cout << "Case 1: Two Different Standard Cards are flipped: " << endl;
	// Standard Card 1 is already flipped
	// Flip Standard Card 2
	deck.revealCard(1, 3);

	deck.displayGrid();
	cout << endl;

	// call the evaluateFlippedCards()
	REVEALED_CARDS_EVENT_T e2;
	e2 = deck.evaluateFlippedCards();
	if (e2 == TWO_DIFFERENT_STANDARD)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	// The grid should be flipped again
	deck.displayGrid();
	cout << endl;


	// call the evaluateFlippedCards()
	cout << "Case 2: Two Same Standard Cards are flipped: " << endl;
	// flip the first card: Standard 2
	deck.revealCard(1, 3);
	// flip the second card: Standard 2
	deck.revealCard(1, 4);

	deck.displayGrid();
	cout << endl;

	e2 = deck.evaluateFlippedCards();
	if (e2 == TWO_SAME_STANDARD)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	// The cards should be removed
	deck.displayGrid();
	cout << endl;

	cout << "Case 3: Standard and Bonus Cards are flipped: " << endl;
	cout << "Case 3.1: First Card Standard, Second Card Bonus" << endl;
	// flip the first card: Standard 1
	deck.revealCard(1, 2);
	// flip the second card: Bonus
	deck.revealCard(4, 1);

	deck.displayGrid();
	cout << endl;

	e2 = deck.evaluateFlippedCards();
	if (e2 == STANDARD_AND_BONUS)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	// The Bonus card should be removed
	deck.displayGrid();
	cout << endl;


	cout << "Case 3.2: First Card Bonus, Second Card Standard" << endl;
	// flip the first card: Standard 1
	deck.revealCard(4, 2);
	// flip the second card: Bonus
	deck.revealCard(1, 2);

	deck.displayGrid();
	cout << endl;

	e2 = deck.evaluateFlippedCards();
	if (e2 == STANDARD_AND_BONUS)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	// The Bonus card should be removed
	deck.displayGrid();
	cout << endl;

	cout << "Case 4: Standard and Penalty Cards are flipped: " << endl;
	cout << "Case 4.1: First Card Standard, Second Card Penalty" << endl;
	// flip the first card: Standard 3
	deck.revealCard(2, 1);
	// flip the second card: Penalty
	deck.revealCard(4, 3);

	deck.displayGrid();
	cout << endl;

	e2 = deck.evaluateFlippedCards();
	if (e2 == STANDARD_AND_PENALTY)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	// The Penalty card should be removed
	deck.displayGrid();
	cout << endl;


	cout << "Case 4.2: First Card Bonus, Second Card Standard" << endl;
	// flip the first card: Penalty
	deck.revealCard(4, 4);
	// flip the second card: Standard 3
	deck.revealCard(2, 2);

	deck.displayGrid();
	cout << endl;

	e2 = deck.evaluateFlippedCards();
	if (e2 == STANDARD_AND_PENALTY)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	// The Penalty card should be removed
	deck.displayGrid();
	cout << endl;

	// Testing DECK_STATUS_T getDeckStatus();
	cout << "Testing getDeckStatus function " << endl;
	cout << "Case 1: TWO_OR_MORE_CARDS_LEFT case: ";

	DECK_STATUS status;
	status = deck.getDeckStatus();
	if (status == TWO_OR_MORE_CARDS_LEFT)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}

	return 0;
}

int testDeckClass_2(void)
{
	Deck deck;
	REVEALED_CARDS_EVENT_T e;
	DECK_STATUS status;

	cout << "3. Testing evaluateFlippedCards function" << endl;
	cout << "Case 5: Bonus and Penalty Cards are flipped: " << endl;
	cout << "Case 5.1: First Card Bonus, Second Card Penalty" << endl;
	// flip the first card: Bonus
	deck.revealCard(4, 1);
	// flip the second card: Penalty
	deck.revealCard(4, 3);

	deck.displayGrid();
	cout << endl;
	
	e = deck.evaluateFlippedCards();
	if (e == BONUS_AND_PENALTY)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	// The Bonus card should be removed
	deck.displayGrid();
	cout << endl;

	cout << "Case 5.2: First Card Penalty, Second Card Bonus" << endl;
	// flip the first card: Penalty
	deck.revealCard(4, 4);
	// flip the second card: Bonus
	deck.revealCard(4, 2);

	deck.displayGrid();
	cout << endl;

	e = deck.evaluateFlippedCards();
	if (e == BONUS_AND_PENALTY)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	// The Bonus card should be removed
	deck.displayGrid();
	cout << endl;

	cout << "Testing getDeckStatus function " << endl;
	cout << "Case 2: EMPTY_DECK case: " << endl;

	// reveal the remaining cards except Standard 1
	deck.revealCard(1, 1);
	deck.revealCard(1, 2);
	deck.evaluateFlippedCards();

	deck.revealCard(1, 3);
	deck.revealCard(1, 4);
	deck.evaluateFlippedCards();
	
	deck.revealCard(2, 1);
	deck.revealCard(2, 2);
	deck.evaluateFlippedCards();

	deck.revealCard(2, 3);
	deck.revealCard(2, 4);
	deck.evaluateFlippedCards();

	deck.revealCard(3, 1);
	deck.revealCard(3, 2);
	deck.evaluateFlippedCards();

	deck.revealCard(3, 3);
	deck.revealCard(3, 4);
	deck.evaluateFlippedCards();

	deck.displayGrid();

	
	status = deck.getDeckStatus();
	if (status == EMPTY_DECK)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}

	return 0;
}

int testDeckClass_3(void)
{
	Deck deck;
	REVEALED_CARDS_EVENT_T e;
	DECK_STATUS status;

	cout << "3. Testing evaluateFlippedCards function" << endl;
	cout << "Case 6: TWO Bonus Cards are flipped: " << endl;
	// flip the first card: Bonus
	deck.revealCard(4, 1);
	// flip the second card: Bonus
	deck.revealCard(4, 2);

	deck.displayGrid();
	cout << endl;

	e = deck.evaluateFlippedCards();
	if (e == TWO_BONUS)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	// The Bonus cards should be removed
	deck.displayGrid();
	cout << endl;

	cout << "Case 7: TWO Penalty Cards are flipped: " << endl;
	// flip the first card: Bonus
	deck.revealCard(4, 3);
	// flip the second card: Bonus
	deck.revealCard(4, 4);

	deck.displayGrid();
	cout << endl;

	e = deck.evaluateFlippedCards();
	if (e == TWO_PENALTY)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	// The Bonus card should be removed
	deck.displayGrid();
	cout << endl;


	return 0;
}

int testDeckClass_4(void)
{
	Deck deck;
	REVEALED_CARDS_EVENT_T e;
	DECK_STATUS status;

	cout << "Testing getDeckStatus function " << endl;
	cout << "Case 3: ONE_CARD_LEFT case: " << endl;

	// Revealing Standard Cards 1 to 5
	// standard cards 1
	deck.revealCard(1, 1);
	deck.revealCard(1, 2);
	deck.evaluateFlippedCards();

	// standard cards 2
	deck.revealCard(1, 3);
	deck.revealCard(1, 4);
	deck.evaluateFlippedCards();

	// standard cards 3
	deck.revealCard(2, 1);
	deck.revealCard(2, 2);
	deck.evaluateFlippedCards();

	// standard cards 4
	deck.revealCard(2, 3);
	deck.revealCard(2, 4);
	deck.evaluateFlippedCards();

	// standard cards 5
	deck.revealCard(3, 1);
	deck.revealCard(3, 2);
	deck.evaluateFlippedCards();

	// standard card 6 and bonus
	deck.revealCard(3, 3);
	deck.revealCard(4, 1);
	deck.evaluateFlippedCards();

	// standard cards 6 
	deck.revealCard(3, 3);
	deck.revealCard(3, 4);
	deck.evaluateFlippedCards();

	// penalty cards 
	deck.revealCard(4, 3);
	deck.revealCard(4, 4);
	deck.evaluateFlippedCards();


	deck.displayGrid();


	status = deck.getDeckStatus();
	if (status == ONE_CARD_LEFT)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}

	cout << "Testing revealLastCard function" << endl;
	cout << "Test Case: Bonus Card: ";
	
	if(deck.revealLastCard() == BONUS)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}

	return 0;
}

int testDeckClass_5(void)
{
	Deck deck;
	REVEALED_CARDS_EVENT_T e;
	DECK_STATUS status;

	cout << "Testing getDeckStatus function " << endl;
	cout << "Case 3: ONE_CARD_LEFT case: " << endl;

	// Revealing Standard Cards 1 to 5
	// standard cards 1
	deck.revealCard(1, 1);
	deck.revealCard(1, 2);
	deck.evaluateFlippedCards();

	// standard cards 2
	deck.revealCard(1, 3);
	deck.revealCard(1, 4);
	deck.evaluateFlippedCards();

	// standard cards 3
	deck.revealCard(2, 1);
	deck.revealCard(2, 2);
	deck.evaluateFlippedCards();

	// standard cards 4
	deck.revealCard(2, 3);
	deck.revealCard(2, 4);
	deck.evaluateFlippedCards();

	// standard cards 5
	deck.revealCard(3, 1);
	deck.revealCard(3, 2);
	deck.evaluateFlippedCards();

	// standard card 6 and penalty
	deck.revealCard(3, 3);
	deck.revealCard(4, 3);
	deck.evaluateFlippedCards();

	// standard cards 6 
	deck.revealCard(3, 3);
	deck.revealCard(3, 4);
	deck.evaluateFlippedCards();

	// penalty cards 
	deck.revealCard(4, 1);
	deck.revealCard(4, 2);
	deck.evaluateFlippedCards();


	deck.displayGrid();


	status = deck.getDeckStatus();
	if (status == ONE_CARD_LEFT)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}

	cout << "Testing revealLastCard function" << endl;
	cout << "Test Case: Penalty Card: ";

	if (deck.revealLastCard() == PENALTY)
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}

	return 0;
}

/*
int main()
{
	//testCardClass();
	//testStandardCardClass();
	//testPenaltyCardClass();
	//testBonusCardClass();
	//int x = testDeckClass_5();
	//cout << x << endl;
	//testPlayerClass();
	//testGameClass();
	return 0;
}
*/