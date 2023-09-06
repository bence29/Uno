#include"player.h"
#include<vector>

Player::Player(string iname, vector< Card* > card, unsigned cardNumber) {
	Next = nullptr;
	Prev = nullptr;
	name = iname;
	for (unsigned i = 0; i < cardNumber; i++) {
		Card* p = card[i];
		cards.push_back(p);
	}
}

Player::Player(unsigned cardNumber) : name("Default") {
	Next = nullptr;
	Prev = nullptr;
	for (unsigned i = 0; i < cardNumber; i++) {
		Card* p = getRandomCard();
		cards.push_back(p);
	}
}

void Player::displayCards() {
	for (unsigned i = 0; i < this->cards.size(); i++) {
		cout << i + 1 << ". ";
		cards[i]->drawCard();
		cout << endl;
	}
}

unsigned Player::cardnumber() {
	return cards.size();
}

void Player::displayName() {
	cout << name;
}

void Player::newCard() {
	Card* p = getRandomCard();
	this->cards.push_back(p);
}