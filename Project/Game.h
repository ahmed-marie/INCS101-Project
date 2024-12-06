#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"

#define PLAYER_NUMBERS 2

class Game
{
private:
	Player players[PLAYER_NUMBERS];
	Deck deck;
public:
	Game();
	~Game();
	void intializeGame(void);
};


#endif // !GAME_H

