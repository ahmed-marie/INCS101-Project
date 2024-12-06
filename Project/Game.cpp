#include "Game.h"

// please note the attributes are statically allocated
// therefore, when the Game() constructor is called
// it will call the constructor of its attributes
// similarly for the destructors. The destructor will
// call the destructors of the attributes

Game::Game(){}

Game::~Game(){}

void Game::intializeGame(void)
{
	// getting the players' names and intialize set it to the object
	for (int i = 0; i < PLAYER_NUMBERS; i++)
	{
		cout << "Player " << i + 1 << ": ";
		cout << "Please Enter Name: ";
		string name;
		cin >> name;
		players[i].setName(name);
	}
	cout << endl;
	// shuffle the deck
	deck.shuffle();

	// display the deck
	deck.displayGrid();

	cout << endl;
	// Display Scores
	for (int i = 0; i < PLAYER_NUMBERS; i++)
	{
		players[i].displayScore();
	}
}
