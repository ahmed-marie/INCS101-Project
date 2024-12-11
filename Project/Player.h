#ifndef PLAYER_H
#define PLAYER_H

#include "utilities.h"

class Player
{
private:
	string name;
	int score;
	int turnsNo;
public:
	Player(string name = "", int score = 0);
	~Player();
	string getName();
	void setName(string name);
	int getScore();
	void setScore(int score);
	void displayScore();
	void updateScore(int score);
	void setTurnsNo(int turns);
	int getTurnsNo();
	void incrementTurn();
	void incrementTurn(int turn);
	void decrementTurn();
};

#endif // !PLAYER_H



