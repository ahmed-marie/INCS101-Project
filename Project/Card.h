#ifndef CARD_H
#define CARD_H

#include "utilities.h"

class Card
{
protected:
	int number;
	bool faceUp;
public:

	Card(int number = 0, bool faceUp = false);
	virtual ~Card();
	void setNumber(int number);
	int getNumber();
	void setFaceUp(bool faceUp);
	bool isFaceUp();
	void display();
};


#endif // !CARD_H


