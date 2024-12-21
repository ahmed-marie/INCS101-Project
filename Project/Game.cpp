#include "Game.h"

// please note the attributes are statically allocated
// therefore, when the Game() constructor is called
// it will call the constructor of its attributes
// similarly for the destructors. The destructor will
// call the destructors of the attributes

Game::Game()
{
	currentTurn = -1;
	nextTurn = -1;
	gameState = GAME_CREATED;
}

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
	//shuffle the deck
	deck.shuffle();

	// display the deck
	deck.displayGrid();

	// Display Scores
	for (int i = 0; i < PLAYER_NUMBERS; i++)
	{
		players[i].displayScore();
	}

	// Ask for which player wil start
	cout << "Which Player will start? [1 2]: ";
	int i;
	cin >> i;
	// decrement the index for zero indexing
	i--;
	// set the player's index to currentTurn
	currentTurn = i;
	// set the other index to nextTurn
	nextTurn = (i + 1) % 2;
	// increment the current player's turn
	players[currentTurn].incrementTurn();
	// set the gameState to GAME_START
	gameState = GAME_START;
}

TURN_STATE_T Game::evaluateTurn(int& score_ref)
{
	TURN_STATE_T state; int n;
	REVEALED_CARDS_EVENT_T event = deck.evaluateFlippedCards();
	switch (event)
	{
	case TWO_SAME_STANDARD:
		score_ref = 1;
		state = BONUS_TURN; break;
	case TWO_DIFFERENT_STANDARD:
		score_ref = 0;
		state = END_TURN; break;
	case STANDARD_AND_PENALTY:
		score_ref = -1;
		state = END_TURN; break;
	case STANDARD_AND_BONUS:
		score_ref = 1;
		state = END_TURN; break;
	case BONUS_AND_PENALTY:
		score_ref = 0;
		state = END_TURN; break;
	case TWO_BONUS:
		// let the user decide the action
		// get 2 bonus points or
		// get one and an extra turn
		cout << "Two Bonus Cards Revealed! You have 2 options:" << endl;
		cout << "1. Get two points" << endl;
		cout << "2. Get one point and get an extra turn" << endl;
		cout << "please enter the option no. [1 2]: ";
		cin >> n;
		if (n == 1)
		{
			score_ref = 2;
			state = END_TURN;
		}
		else
		{
			score_ref = 1;
			state = BONUS_TURN;
		}
		break;
	case TWO_PENALTY:
		// let the user decide the action
		// lose 2 bonus points or
		// lose 1 and skip a turn
		cout << "Two Penalty Cards Revealed! You have 2 options:" << endl;
		cout << "1. Lose two points" << endl;
		cout << "2. Lose one point and skip a turn" << endl;
		cout << "please enter the option no. [1 2]: ";
		cin >> n;
		if (n == 1)
		{
			score_ref = -2;
			state = END_TURN;
		}
		else
		{
			score_ref = -1;
			state = SKIP_TURN;
		}
		break;

	default: break;
	}
	return state;
}

void Game::requestCardFlip()
{
	// 1. request input [row, col] from the user
	cout << "Please Enter the card's row and column [1 4] [row col]: ";
	int row = -1; int col = -1;
	cin >> row;
	cin >> col;
	// check if the row and col are inside the range [1 4]
	while (!((1 <= row) && (row <= 4) && (1 <= col) && (col <= 4)))
	{
		cout << "Invalid indices. Please enter a valid indices [1 4] [row col]: ";
		cin >> row;
		cin >> col;
	}
	CARD_EVENT_T card_status = deck.revealCard(row, col);
	while (card_status != CARD_FOUND)
	{
		if (card_status == CARD_NOT_FOUND)
		{
			cout << "Card is removed. Please enter another indices [1 4] [row col]: ";
		}
		else if (card_status == CARD_REVEALED_BEFORE)
		{
			cout << "Card is already revealed. Please enter another indices [1 4] [row col]: ";
		}
		cin >> row;
		cin >> col;
		card_status = deck.revealCard(row, col);
	}
	deck.displayGrid();
}

void Game::flipLastCard(int& score_ref)
{
	CARD_TYPE_T card_type = deck.revealLastCard();
	deck.displayGrid();
	switch (card_type)
	{
		case BONUS: score_ref = 1; break;
		case PENALTY: score_ref = -1; break;
		default: score_ref = 0;  break;
	}
}

void Game::takeTurn()
{
	// decrement the current player's turn 
	players[currentTurn].decrementTurn();
	cout << players[currentTurn].getName() << "'s Turn" << endl;
	// flip the first card
	requestCardFlip();
	// flip the second card
	requestCardFlip();
	// evaluate the player's turn and score
	int score_ref = 0;
	TURN_STATE_T turn_status = evaluateTurn(score_ref);
	// update the current's player's score
	players[currentTurn].updateScore(score_ref);

	// display the players' scores
	for(int i = 0; i < PLAYER_NUMBERS; i++)
		players[i].displayScore();


	// check the current's player turn status
	switch (turn_status)
	{
		case BONUS_TURN: 
			players[currentTurn].incrementTurn(); break;
		case SKIP_TURN:
			players[currentTurn].decrementTurn(); break;
		case END_TURN:
			//players[currentTurn].decrementTurn(); break;
		default: break;
	}
	// check the deck's status
	DECK_STATUS_T deck_status = deck.getDeckStatus();
	switch (deck_status)
	{
		case EMPTY_DECK:
			// no cards, game end
			gameState = GAME_END; break;
		case ONE_CARD_LEFT:
			score_ref = 0;
			// reveal the last card
			flipLastCard(score_ref);
			// add its points to the current player
			players[currentTurn].updateScore(score_ref);
			// no cards, game end
			gameState = GAME_END; break;
		case TWO_OR_MORE_CARDS_LEFT:
			// cards still availabe, game continued
			gameState = GAME_LOOP;
			deck.displayGrid();
			break;
		default: break;
	}
}

void Game::shiftTurn()
{
	players[nextTurn].incrementTurn();
	currentTurn = nextTurn;
	nextTurn = (nextTurn + 1) % 2;
}

void Game::loopGame()
{
	gameState = GAME_LOOP;

	while (gameState == GAME_LOOP)
	{
		// while the current player's turnNo is greater than zero
		while ((players[currentTurn].getTurnsNo() > 0) && (gameState == GAME_LOOP))
		{
			takeTurn();
		}
		// check whether the game has ended or the current player's turn has ended
		if (gameState == GAME_LOOP)
		{
			//shift the turns
			shiftTurn();
		}
		// if gameState != GAME_LOOP, this means that the takeTurn() function returned GAME_END
		// and should exit the loopGame() function
		else
		{
			return;
		}
	}
}

void Game::finalizeGame()
{
	cout << "End Game" << endl;
	players[0].displayScore();
	players[1].displayScore();
	if (players[0].getScore() > players[1].getScore())
	{
		cout << players[0].getName() << " wins!!" << endl;
	}
	else if(players[0].getScore() < players[1].getScore())
	{
		cout << players[1].getName() << " wins!!" << endl;
	}
	else
	{
		cout << "Draw!!" << endl;
	}
}

