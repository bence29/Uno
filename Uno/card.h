#pragma once
#include "include.h"

using namespace std;

class Card {
public:
	friend class Player;
	virtual ~Card() {}
	virtual void setCardNumber(const unsigned n) = 0;
	virtual void setCardColor(const char c) = 0;
	virtual unsigned getCardNumber() const =0;
	virtual char getCardColor() const =0;
	virtual char getCardType() const =0;
	virtual string getCardColorS() const =0;
	virtual string getCardTypeS() const =0;
	virtual void drawCard() const =0;
};
Card* getRandomCard();