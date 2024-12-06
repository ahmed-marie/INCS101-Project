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

	// 5. Testing destructor
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

	// 5. Testing destructor
	delete newCard;
}

void testBonusCardClass()
{
	// Test 1: Creating a card with an Empty Constructor
	PenaltyCard* newCard = new PenaltyCard;

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
}

void testGameClass(void)
{
	Game game;
	game.intializeGame();
}

//int main()
//{
//	//testCardClass();
//	//testStandardCardClass();
//	//testPenaltyCardClass();
//	//testBonusCardClass();
//	//int x = testDeckClass();
//	//cout << x << endl;
//	//testPlayerClass();
//	//testGameClass();
//	return 0;
//}