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


/*
void Game::loopGame()
{
	gameState = GAME_LOOP;

	while (gameSate == GAME_LOOP)
	{
		// while the current player's turnNo is not equal to zero
		while ((players[currentPlayer].getTurnsNo() != 0) && (gameSate == GAME_LOOP))
		{
			gameState = takeTurn();
		}
		// check whether the game has ended or the current player's turn has ended
		if (gameState == GAME_LOOP)
		{
			//shift the turns
			nextTurn();
		}
		// if gameState != GAME_LOOP, this means that the takeTurn() function returned GAME_END
		// and should exit the loopGame() function
		else
		{
			return;
		}
	}
}
*/