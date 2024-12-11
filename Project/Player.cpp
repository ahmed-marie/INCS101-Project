#include "Player.h"

Player::Player(string name, int score)
{
	this->name = name;
	this->score = score;
	turnsNo = 0;
}


Player::~Player() {}


string Player::getName()
{
	return name;
}


void Player::setName(string name)
{
	this->name = name;
}


int Player::getScore()
{
	return score;
}


void Player::setScore(int score)
{
	this->score = score;
}

void Player::displayScore()
{
	cout << name << "'s Score: " << score << endl;
}

void Player::updateScore(int score)
{
	this->score += score;
}

void Player::setTurnsNo(int turns)
{
	this->turnsNo = turns;
}

int Player::getTurnsNo()
{
	return turnsNo;
}

void Player::incrementTurn()
{
	++turnsNo;
}

void Player::incrementTurn(int turn)
{
	turnsNo += turn;
}

void Player::decrementTurn()
{
	--turnsNo;
}
