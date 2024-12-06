#include "Player.h"

Player::Player(string name, int score)
{
	this->name = name;
	this->score = score;
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