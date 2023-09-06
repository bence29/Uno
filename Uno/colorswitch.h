#pragma once
#include "include.h"
#include "card.h"

using namespace std;

class ColorSwitch : public Card {
public:
	virtual ~ColorSwitch() {}
	virtual void setCardNumber(const unsigned n) {}
	virtual void setCardColor(const char c) {}
	virtual unsigned getCardNumber() const { return 10; }
	virtual char getCardColor() const { return 'f'; }
	virtual string getCardColorS() const {
		return "Fekete";
	}
	virtual char getCardType() const {
		return 'c';
	}
	virtual string getCardTypeS() const {
		return "Szinv";
	}
	void drawCard() const {
		cout << "Tipus: " << getCardTypeS();
	}
};