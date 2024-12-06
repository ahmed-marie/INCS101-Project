#ifndef PLAYER_H
#define PLAYER_H

#include "utilities.h"

class Player
{
private:
	string name;
	int score;
public:
	Player(string name = "", int score = 0);
	~Player();
	string getName();
	void setName(string name);
	int getScore();
	void setScore(int score);
	void displayScore();
};

#endif // !PLAYER_H



