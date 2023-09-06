#pragma once
#include "include.h"
#include "card.h"

using namespace std;

class ColorSwitchPlusFour : public Card {
public:
	virtual ~ColorSwitchPlusFour() {}
	virtual void setCardNumber(const unsigned n) {}
	virtual void setCardColor(const char c) {}
	virtual unsigned getCardNumber() const { return 10; }
	virtual char getCardColor() const { return 'f'; }
	virtual string getCardColorS() const {
		return "Fekete";
	}
	virtual char getCardType() const {
		return '4';
	}
	virtual string getCardTypeS() const {
		return "Szinv+4";
	}
	void drawCard() const {
		cout << "Tipus: " << getCardTypeS();
	}
};