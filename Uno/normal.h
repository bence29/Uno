#pragma once
#include"include.h"
#include "card.h"

using namespace std;

class Normal : public Card {
	unsigned number;
	char color;
public:
	virtual ~Normal() {}
	Normal(char pcolor = 'p', unsigned pnumber = 7);
	virtual void setCardNumber(const unsigned n) {
		if (n >= 0 && n <= 9)
			number = n;
	}
	virtual void setCardColor(const char c) {
		if (c == 'p' || c == 'z' || c == 's' || c == 'k')
			color = c;
	}
	virtual unsigned getCardNumber() const {
		return number;
	}
	virtual char getCardColor() const {
		return color;
	}
	virtual char getCardType() const {
		return 'n';
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
		return "Normal";
	}
	void drawCard() const {
		cout << "Tipus: " << getCardTypeS() << "	" << "Szin: " << getCardColorS()<<"	"<<"Szam: "<<getCardNumber();
	}
};
