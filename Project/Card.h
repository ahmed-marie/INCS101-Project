#ifndef CARD_H
#define CARD_H

#include "utilities.h"

typedef enum CARD_TYPE
{
	DEFAULT, STANDARD, BONUS, PENALTY
}CARD_TYPE_T;

class Card
{
protected:
	int number;
	bool faceUp;
	CARD_TYPE_T cardType;

public:
	Card(int number = 0, bool faceUp = false);
	virtual ~Card();
	void setNumber(int number);
	int getNumber();
	void setFaceUp(bool faceUp);
	bool isFaceUp();
	void display();
	CARD_TYPE_T getCardType();
	virtual void displayCardMessage() = 0;
};


#endif // !CARD_H


