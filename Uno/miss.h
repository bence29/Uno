#pragma once
#include"include.h"
#include "card.h"

using namespace std;

class Miss : public Card {
	char color;
public:
	virtual ~Miss() {}
	Miss(char pcolor='p');
	virtual void setCardNumber(const unsigned n) {}
	virtual void setCardColor(const char c) {
		if (c == 'p' || c == 'z' || c == 's' || c == 'k')
			color = c;
	}
	virtual unsigned getCardNumber() const { return 10; }
	virtual char getCardColor() const {
		return color;
	}
	virtual char getCardType() const {
		return 'm';
	}
	virtual string getCardColorS() const {
		string c;
		if (getCardColor() == 'p')
			c = "Piros";
		else if (getCardColor() == 'z')
			c = "Zold";
		else if (getCardColor() == 's')
			c = "Sarga";
		else if (getCardColor() == 'k')
			c = "Kek";
		else
			c = "Error";
		return c;
	}
	virtual string getCardTypeS() const {
		return "Kimaradsz";
	}
	void drawCard() const {
		cout << "Tipus: " << getCardTypeS() << "	" << "Szin: " << getCardColorS();
	}
};