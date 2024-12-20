#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"

#define PLAYER_NUMBERS 2

typedef enum GAME_STATE
{
	GAME_CREATED, GAME_START, GAME_LOOP, GAME_END
}GAME_STATE_T;

typedef enum TURN_STATE
{
	BONUS_TURN, SKIP_TURN, END_TURN
}TURN_STATE_T;

class Game
{
private:
	Player players[PLAYER_NUMBERS];
	Deck deck;
	GAME_STATE_T gameState;
	int currentTurn;
	int nextTurn;
public:
	Game();
	~Game();
	void intializeGame(void);
	TURN_STATE_T evaluateTurn(int& score_ref);
	void requestCardFlip();
	void flipLastCard(int& score_ref);
	void takeTurn();
	void shiftTurn();
	void loopGame();
	void finalizeGame();
};


#endif // !GAME_H

